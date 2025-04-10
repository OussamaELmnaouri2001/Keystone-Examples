Exécution de deux enclaves distinctes de manière séquentielle à l'aide d'un même hôte commun.
Chaque enclave est compilée séparément et implémente une logique spécifique :

   eapp_password_check : vérifie un mot de passe entré par l’utilisateur via un appel OCALL.
   eapp_multiplier : calcule le produit de deux entiers et affiche le résultat.

Le programme hôte unique (multi_enclave_host.cpp) initialise, exécute, puis libère chaque enclave l'une après l'autre :
