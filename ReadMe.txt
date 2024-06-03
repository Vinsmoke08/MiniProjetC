Mini Projet C

Auteur :

Nom 1: Roszak Roman
Nom 2: Azas Melvin

Ce projet présente un programme en C qui gère diverses opérations liées à l'adressage IP.
Objectif de l'application

L'objectif principal de cette application est de fournir un ensemble de fonctionnalités liées à l'adressage IP. Cela inclut le calcul d'adresse réseau, le décodage d'adresses IP, l'extraction des champs d'une adresse IP et la vérification du format des adresses IP.
Contenu du projet

    main.c : Le fichier source principal contenant la fonction main() qui exécute le programme.
    calculeradresse.c, decoderip.c, extraireleschamps.c, verifierleformat.c : Les fichiers source contenant les différentes fonctionnalités du programme.
    calculeradresse.h, decoderip.h, extraireleschamps.h, verifierleformat.h : Les fichiers d'en-tête correspondant aux fichiers source respectifs.
    Makefile : Le fichier de configuration Makefile pour automatiser les étapes de compilation.

Compilation et Exécution

Pour compiler et exécuter le programme, suivez ces étapes :

    Assurez-vous d'avoir GCC (GNU Compiler Collection) installé sur votre système.

    Placez tous les fichiers source (".c" et ".h") dans le répertoire src.

    Ouvrez un terminal et accédez au répertoire contenant le fichier Makefile.

    Exécutez la commande make. Cela compilera les fichiers source et créera l'exécutable final.

    Une fois la compilation terminée, l'exécutable MakeFile sera généré dans le répertoire bin.

    Pour exécuter le programme, dans un terminal, accédez au répertoire contenant l'exécutable MakeFile et exécutez la commande ./MakeFile.

Documentation des fonctions

Veuillez vous référer aux commentaires dans les fichiers source pour obtenir une documentation détaillée sur chaque fonction implémentée dans ce projet.

Cas d'erreur

Si une adresse IP invalide est fournie en entrée, les fonctions peuvent afficher un message d'erreur approprié ou retourner une valeur indiquant une erreur.
Pour plus d'informations sur l'implémentation et l'utilisation des fonctions, veuillez consulter le code source des fichiers correspondants.

Le code source de l'application est disponible dans le dépôt Git suivant : https://github.com/Vinsmoke08/MiniProjetC.git
