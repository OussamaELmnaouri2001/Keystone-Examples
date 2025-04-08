# Structure Générale du Dépôt

Chaque exemple contient :

- `host` : code exécuté sur l’hôte (hors enclave)

- `eapp` : code exécuté dans l’enclave

- `CMakeLists.txt` : permet de compiler et packager les deux

Pour les compiler dans Keystone :

    Copier le dossier dans /keystone/examples/
    
    Ajouter add_subdirectory(nom_du_dossier) dans /keystone/examples/CMakeLists.txt
    
    Compiler : make -j$(nproc)
    
    Exécuter avec QEMU (doc officielle : https://docs.keystone-enclave.org/en/latest/Getting-Started/index.html)

# Analyse de l’exemple addition

`host/addition_host.cpp`

Ce fichier gère :

- L'initialisation de l'enclave

- L'enregistrement des OCALLs

- Le lancement de l’enclave

## Étapes importantes

`eapp/addition.c`
C'est le programme dans l’enclave. Il effectue une addition simple de deux entiers et appelle une OCALL pour afficher le résultat.

## Points clés

`ocall_print_int(c);`

- OCALL : l’enclave demande à l’hôte d’afficher le résultat, car elle ne peut pas faire d’I/O seule.

# Analyse de l’exemple password

`host/password_host.cpp`

Même logique qu’avant mais avec un autre type d’OCALL, ici liée à un mot de passe :

- Vérifie la correspondance via une fonction définie côté hôte.

`eapp/password.c`

# Fonctionnement des OCALLs et Edge Wrappers

todo
