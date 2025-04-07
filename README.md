**Structure des exemples Keystone**

Chaque exemple dans le dépôt suit une structure standard composée de trois éléments principaux :

    eapp : L'application enclavée qui s'exécute dans l'enclave sécurisée.

    host : L'application hôte qui interagit avec l'enclave.

    CMakeLists.txt : Le fichier de configuration utilisé par CMake pour générer les fichiers de construction nécessaires.

**Intégration des exemples dans Keystone**

Pour intégrer ces exemples dans votre environnement Keystone, suivez les étapes suivantes :

    Copier les exemples dans le répertoire approprié :

    Placez chaque dossier d'exemple (par exemple, addition et password) dans le répertoire /keystone/examples/ de votre installation Keystone.

    Modifier le fichier CMakeLists.txt principal :

    Ouvrez le fichier CMakeLists.txt situé dans /keystone/examples/ et ajoutez une ligne pour inclure chaque nouvel exemple. Par exemple, pour ajouter les exemples addition et password :

add_subdirectory(addition)
add_subdirectory(password)

Compiler les exemples :

Après avoir ajouté les exemples et modifié le CMakeLists.txt, exécutez la commande suivante depuis le répertoire racine de Keystone pour compiler les exemples :

    make -j$(nproc)

    Exécuter les exemples :

    Une fois la compilation terminée, vous pouvez exécuter les exemples en lançant QEMU et en suivant les instructions détaillées dans la documentation officielle de Keystone : Keystone Basics.

**Détails des exemples**
Exemple : Addition
