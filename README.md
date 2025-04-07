# 📁 Structure Générale du Dépôt

Chaque exemple contient :

    host/ → code exécuté sur l’hôte (hors enclave)

    eapp/ → code exécuté dans l’enclave

    CMakeLists.txt → permet de compiler et packager les deux

Pour les compiler dans Keystone :

    Copier le dossier dans /keystone/examples/

    Ajouter add_subdirectory(nom_du_dossier) dans /keystone/examples/CMakeLists.txt

    Compiler : make -j$(nproc)

    Exécuter avec QEMU (cf. doc officielle)

# 🔍 Analyse de l’exemple addition
🔹 host/host.c

Ce fichier gère :

    L'initialisation de l'enclave

    L'enregistrement des OCALLs

    Le lancement de l’enclave

📌 Étapes importantes :

#include <edge_call.h>
#include <keystone_user.h>

👉 Inclusion des headers nécessaires pour communiquer avec l’enclave.

int main(int argc, char** argv) {
    ...
    params.untrusted_mem_ptr = (uintptr_t)shared_buffer;

👉 Allocation de la mémoire partagée entre l’hôte et l’enclave.

keystone_enclave_create(&enclave, &params);

👉 Création de l’enclave avec les paramètres définis.

keystone_enclave_run(&enclave, &retval);

👉 Lancement de l’application enclavée (le eapp).
🔹 eapp/eapp.c

C'est le programme dans l’enclave. Il effectue ici une addition simple de deux entiers et appelle une OCALL pour afficher le résultat.
📌 Points clés :

int a = 5;
int b = 3;
int c = a + b;

👉 Simple addition.

ocall_print_int(c);

👉 OCALL : l’enclave demande à l’hôte d’afficher le résultat, car elle ne peut pas faire d’I/O seule.

    Les OCALLs sont définies dans edge_wrapper.c/h et sont automatiquement sérialisées via edge_call (système Keystone).

🔐 Analyse de l’exemple password
🔹 host/host.c

Même logique qu’avant mais avec un autre type d’OCALL, ici liée à un mot de passe :

register_enclave(&enclave);

👉 Enregistrement de l’OCALL personnalisée pour la vérification de mot de passe.

ocall_check_password();

👉 Vérifie la correspondance via une fonction définie côté hôte.
🔹 eapp/eapp.c

Ici, on simule une logique simple :

char password[] = "1234";
ocall_check_password(password);

👉 L'enclave envoie un mot de passe à vérifier.

    Bien sûr, dans une vraie app, le mot de passe ne devrait jamais sortir de l’enclave, c’est juste une démo.

# 🧩 Fonctionnement des OCALLs et Edge Wrappers

Les OCALLs sont des fonctions appelées depuis l’enclave, mais exécutées dans l’hôte. Dans Keystone, elles sont encapsulées avec :

    edge_wrapper.h / .c (dans le dossier host)

    edge_call.h / .c (dans keystone runtime)

Exemple :
Côté enclave (eapp.c)

ocall_print_string("Hello");

Côté hôte (edge_wrapper.c)

void handle_ocall(uintptr_t call_id, void* buffer) {
    if (call_id == OCALL_PRINT_STRING) {
        printf("From Enclave: %s\n", (char*) buffer);
    }
}

    Keystone sérialise l’appel, l’envoie dans la mémoire partagée, puis l’hôte le lit et l’exécute.

✅ Résumé des étapes pour créer un nouvel exemple

    Créer host/, eapp/, et CMakeLists.txt

    Ajouter des OCALLs si besoin

    Copier le dossier dans /keystone/examples

    Modifier examples/CMakeLists.txt :

add_subdirectory(nom_du_dossier)

Compiler :

make -j$(nproc)

Lancer via QEMU selon la doc officielle.
