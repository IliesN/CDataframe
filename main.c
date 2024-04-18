#include "fonctions.h"
#include <stdio.h>

int main() {
    printf("Bienvenue\n");
    CDataframe *myCDataframe = creer_cdataframe();
    while(1){
        int choice;
        printf(
               "Veuillez entrer votre choix :\n"
               "1- Alimentation\n"
               "2- Affichage\n"
               "3- Opérations usuelles\n"
               "4- Analyses statistiques\n");
         scanf("%d", &choice);
         switch (choice) {
            case 1:
                printf("Veuillez entrer votre choix :\n"
                       "1- Création d'un CDataframe vide\n"
                       "2- Remplissage du CDataframe\n");

                int choice2;
                scanf("%d", &choice2);
                switch(choice2){
                    case 1:
                        break;

                    case 2:
                        printf("Veuillez entrer un titre à cette nouvelle colonne\n");
                        char titre;
                        scanf("%s", &titre);
                        COLONNE *mycol = creer_colonne(&titre);
                        printf("Combien de valeurs voulez-vous ajouter à cette colonne ?\n");
                        int nb_valeurs;
                        scanf("%d", &nb_valeurs);
                        for(int i = 0; i < nb_valeurs; i++){
                            printf("Entrez une valeur\n");
                            int nouvelle_valeur;
                            scanf("%d", &nouvelle_valeur);
                            inserer_valeur(mycol, nouvelle_valeur);
                            }
                        ajouter_colonne(myCDataframe, mycol);
                        }
                        continue;


            case 2:
                printf("Veuillez entrer votre choix :\n"
                       "1- Afficher tout le CDataframe\n"
                       "2- Afficher une partie des lignes du CDataframe\n"
                       "3- Afficher une partie des colonnes du CDataframe\n");
                int choice3;
                 scanf("%d", &choice3);
                 switch(choice3){
                     case 1:
                         afficher_cdataframe(myCDataframe);
                     case 2:
                         printf("Entrez une limite de lignes");
                         int limlig;
                         scanf("%d", &limlig);
                         afficher_lignes_cdataframe(myCDataframe, limlig);
                     case 3:
                         printf("Entrez une limite de colonnes");
                         int limcol;
                         scanf("%d", &limcol);
                         afficher_lignes_cdataframe(myCDataframe, limcol);
                 }
                     case 3:
                         printf("Veuillez entrer votre choix :\n"
                                "1- Supprimer une colonne du CDataframe\n"
                                "2- Renommer le titre d’une colonne du CDataframe\n"
                                "3- Accéder à la valeur se trouvant dans une cellule du CDataframe en utilisant son\n"
                                "numéro de ligne et de colonne\n"
                                "4- Afficher les noms des colonnes\n");
                    int choice4;
                    scanf("%d", &choice4);
                    switch(choice4){
                        case 1:
                            printf("Entrez l'indice de la colonne que vous souhaitez supprimer\n");
                            int indice_supp = scanf("%d");
                            supprimer_colonne_cdataframe(myCDataframe, indice_supp);
                            break;
                        case 2:
                            printf("Entrez l'indice de la colonne que vous souhaitez renommer\n");
                            int indice_rename = scanf("%d");
                            printf("Indiquez le nouveau nom :\n");
                            char new_name  = scanf("%s");
                            renommer_colonne_cdataframe(myCDataframe, indice_rename, &new_name);
                            break;
                        case 3:
                            printf("Entrez la valeur à chercher");
                            int val_cherchee = scanf("%d");
                            verifier_existence_valeur(myCDataframe, val_cherchee);
                            break;
                        case 4:
                            printf("Entrez les numéros de colonne et ligne");
                            int valeur, no_ligne, no_col;
                            scanf("%d %d", &no_col, &no_ligne);
                            if (acceder_valeur_cellule(myCDataframe, no_col, no_ligne, &valeur)) {
                                printf("Valeur trouvée : %d\n", valeur);
                            } else {
                                printf("Erreur lors de l'accès à la valeur.\n");
                            }
                            break;

                    }
                        case 4:
                            printf("Veuillez entrer votre choix :\n"
                                   "1- Afficher le nombre de lignes\n"
                                   "2- Afficher le nombre de colonnes\n"
                                   "3- Nombre de cellules contenant une valeur égale à x\n"
                                   "4- Nombre de cellules contenant une valeur supérieure à x (x donné en paramètre)\n"
                                   "5- Nombre de cellules contenant une valeur inférieure à x\n");
                            int choice5 = scanf("%d");
                            switch(choice5){
                                case 1:
                                    afficher_nombre_lignes(myCDataframe);
                                    break;
                                case 2:
                                    afficher_nombre_colonnes(myCDataframe);
                                    break;
                                case 3:
                                    printf("Entrez une valeur");
                                    int val_egal = scanf("%d");
                                    int nombre_egal = compter_cellules_valeur(myCDataframe, val_egal);
                                    printf("Nombre de cellules contenant la valeur %d : %d\n", val_egal, nombre_egal);
                                    break;
                                case 4:
                                    printf("Entrez une valeur");
                                    int val_sup = scanf("%d");
                                    int nombre_sup = compter_cellules_superieures(myCDataframe, val_sup);
                                    printf("Nombre de cellules contenant des valeurs supérieures à %d : %d\n", val_sup, nombre_sup);
                                    break;
                                case 5:
                                    printf("Entrez une valeur");
                                    int val_inf = scanf("%d");
                                    int nombre_inf = compter_cellules_inferieures(myCDataframe, val_inf);
                                    printf("Nombre de cellules contenant des valeurs inférieures à %d : %d\n", val_inf, nombre_inf);
                                    break;



                            }






                }



                break;

        }



    return 0;
}



