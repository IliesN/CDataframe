RADOUANE Ismaël, NASR Ilies

Lien du dépôt : https://github.com/IliesN/CDataframe.git

Le projet consiste en l'élaboration d'une librairie en C afin de faciliter la manipulation de données. Il s'inspire du fonctionnement d'un "DataFrame" dans la librairie "Pandas" de Python; c'est pourquoi il est intitulé "CDataframe". Cette structure "Dataframe" se présente sous la forme d'un tableau; et le but du projet est de l'implémenter en C.

Nous avons décidé de choisir un parcours plutôt simple afin de pouvoir le perfectionner au maximum (Colonnes : Tous types de données >> CDataframe : Tableau dynamique >> Fonctionnalités : Basique + quelques fonctionnalités supplémentaires).

L'entièreté des fonctionnalités du CDataframe de tous types de données sont disponibles, sauf la possibilité d'ajouter des valeurs NULL dans le tableau par l'utilisateur et des données de type "structures", car cela semble plus difficile que les autres types et nous n'y trouvons pas l'intêret (+ cela sera trop compliqué à afficher). De plus, l'utilisateur a accès à un affichage complet et esthétique du CDataframe et peut exporter celui-ci sous format CSV.

Afin d'exécuter le programme, ouvrez un terminal dans le dossier contenant l'ensemble des fichiers du projet (ou alors déplacez vous à l'aide de la commande "cd" suivi du répertoire concerné), puis entrez la commande suivante "./main.exe". Vous pouvez également exécuter le programme normalement si vous êtes sur Windows.

Pour compiler le programme, il est nécessaire d'avoir installé gcc ("gcc --version" dans un terminal), puis récupérez le chemin absolu du dossier contenant l'ensemble des fichiers, et enfin entrez la commande suivante :
> cd "chemin\absolu\dossier\projet" ; if ($?) { gcc main.c colonne.c cdataframe.c -o main } ; if ($?) { .\main }
