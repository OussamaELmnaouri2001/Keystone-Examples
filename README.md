# Introduction à Keystone

**Keystone** est une **Trusted Execution Environment (TEE)** open-source conçue pour les architectures RISC-V.conçue pour les architectures **RISC-V**. Elle permet de créer des environnements d'exécution isolés (enclaves) qui peuvent exécuter des applications sensibles en toute sécurité, avec une surface de confiance minimale.
📄 Documentation officielle : https://docs.keystone-enclave.org 
✅ Version utilisée dans ce projet : Keystone 1.0.0 .

# Créer son propre projet dans Keystone 

## Prérequis

Avant de commencer, veuillez vous assurer que :
- Vous avez cloné le dépôt Keystone
- Vous avez terminé toutes les étapes de "Testing Keystone with QEMU" comme indiqué dans la documentation officielle "https://docs.keystone-enclave.org/en/latest/Getting-Started/Running-Keystone-with-QEMU.html"

## Étpaes de création d’un projet

### Se placer dans le dossier des exemples :

   cd /keystone/examples

### Créer un dossier pour ton projet :

    mkdir my_exemple
    cd my_example

### Créer la structure suivante :

    mkdir eapp
    mkdir host
    touch CMakeLists.txt

- eapp/ : Contient le code de l'enclave (le C exécuté de façon isolée).
- host/ : Contient le code (c++) qui lance et gère l’enclave (initialisation Keystone, Edge calls, etc.).
- CMakeLists.txt : Décrit la façon dont ton projet sera compilé.
**Inspiration** : regarde les fichiers CMakeLists.txt des autres exemples (comme addition, password, etc.)

## Étape d’intégration dans Keystone : 

### Ajouter ton projet dans le CMake principal :

Ouvre le fichier keystone/examples/CMakeLists.txt et ajoute la ligne suivante à la fin :

    add_subdirectory(my_example)

### Compiler :

    cd .. 
    make -j$(nproc)

### Exécuter sur QEMU :

Une fois votre projet compilé avec succès, vous pouvez le lancer avec la commande suivante

    make run 

Cela démarrera l'environnement QEMU. Ensuite, suivez les étapes décrites dans la documentation officielle : https://docs.keystone-enclave.org/en/latest/Getting-Started/QEMU-Run-Tests.html
Votre exécutable sera généré dans le répertoire suivant :

   /usr/share/keystone/examples/my_example.ke
