# Introduction à Keystone

Keystone est un *Trusted Execution Environment (TEE)* open-source conçu pour les architectures RISC-V. Il permet de créer des environnements d'exécution isolés (enclaves) qui peuvent exécuter des applications sensibles. Documentation officielle : https://docs.keystone-enclave.org

Versions utilisées dans ce projet : Keystone commit [88c49ee](https://github.com/keystone-enclave/keystone/tree/88c49ee99e745980eea623bddacb40f7303107bd), Ubuntu 22 LTS.

# Créer son propre projet dans Keystone

## Prérequis

```bash
cd $HOME
git clone https://github.com/keystone-enclave/keystone
cd keystone
git checkout 88c49ee
git submodule update --init --recursive
```

Vous avez réussi une première compilation du TEE :

1. [Installation des dépendances](https://docs.keystone-enclave.org/en/latest/Getting-Started/QEMU-Install-Dependencies.html)

2. [Compilation des sources](https://docs.keystone-enclave.org/en/latest/Getting-Started/QEMU-Compile-Sources.html)

## Étapes de création d’un projet

```bash
cd $HOME/keystone/examples
mkdir my_example
cd my_example
mkdir eapp
mkdir host
touch CMakeLists.txt
```

- `eapp/` : Contient le code de l'enclave (le C exécuté de façon isolée).
- `host/` : Contient le code (C++) qui lance et gère l’enclave (initialisation Keystone, Edge calls, etc.).
- `CMakeLists.txt` : Décrit la façon dont votre projet sera compilé.

**Inspiration** : regarde les fichiers `CMakeLists.txt` des autres exemples (comme [addition](./addition/), [password](./password/), etc.)

## Étape d’intégration dans Keystone

### Ajouter le projet dans le CMake principal

Ouvre le fichier `keystone/examples/CMakeLists.txt` et ajoute la ligne suivante à la fin :

```diff
@@ -35,3 +35,4 @@ add_subdirectory(hello)
 add_subdirectory(hello-native)
 add_subdirectory(attestation)
 add_subdirectory(tests)
+add_subdirectory(my_example)
```

### Recompilation de l'image et exécution de QEmu
```bash
cd $HOME/keystone 
make -j$(nproc)
make run 
```

Ensuite, suivez les étapes décrites dans : https://docs.keystone-enclave.org/en/latest/Getting-Started/QEMU-Run-Tests.html

```bash
modprobe keystone-driver
/usr/share/keystone/examples/my_example.ke
```
