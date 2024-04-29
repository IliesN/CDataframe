RADOUANE Ismaël, NASR Ilies

Lien du dépôt : https://github.com/IliesN/CDataframe.git

Le projet consiste en l'élaboration d'une librairie en C afin de faciliter la manipulation de données. Il s'inspire du fonctionnement d'un "DataFrame" dans la librairie "Pandas" de Python; c'est pourquoi il est intitulé "CDataframe". Cette structure "Dataframe" se présente sous la forme d'un tableau; et le but du projet est de l'implémenter en C.

Pour le moment, nous avons décidé de choisir le parcours initial afin de pouvoir le perfectionner au maximum (Colonnes : Entiers seulement >> CDataframe : Tableau dynamique >> Fonctionnalités : Basique). Lorsque nous aurons réglé la plupart des erreurs, nous ferons certainement des colonnes de tout type de données.

La majorité des fonctionnalités de la partie n°1 (Un CDataframe d’entiers) sont disponible, sauf certaines opérations usuelles telles que l'affichage des noms des colonnes.

Afin d'exécuter le programme, ouvrez un terminal dans le dossier contenant l'ensemble des fichiers du projet (ou alors déplacez vous à l'aide de la commande "cd" suivi du répertoire concerné), puis entrez la commande suivante "./main.exe". Vous pouvez également exécuter le programme normalement si vous êtes sur Windows.

Pour compiler le programme, il est nécessaire d'avoir installé gcc ("gcc --version" dans un terminal), puis ouvrez un terminal dans le dossier contenant l'ensemble des fichiers du projet (ou alors déplacez vous à l'aide de la commande "cd" suivi du répertoire concerné), puis entrez la commande suivante :
> "if ($?) { gcc main.c colonne.c cdataframe.c -o main } ; if ($?) { .\main }"
