Exécution de deux enclaves indépendantes de manière séquentielle à l'aide d'un même hôte commun.

Chaque enclave(Eapps) est compilée séparément et implémente une logique spécifique :

   *eapp_password_check* : vérifie un mot de passe entré par l’utilisateurL.
   
   *eapp_multiplier* : calcule le produit de deux entiers et affiche le résultat.

Le programme host unique (*multi_enclave_host.cpp*) initialise, exécute, puis libère chaque enclave l'une après l'autre.
