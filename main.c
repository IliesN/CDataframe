#include "fonctions.h"
#include <stdio.h>

int main() {
    printf("Bienvenue sur le CDataFrame de Ilies NASR et Ismaël RADOUANE.");
    CDataframe *myCDataframe = creer_cdataframe();
    int boucle_1, boucle_2, boucle_3;
    while (1) {
        int choix_utilisateur;
        printf("\n\nVoici les différentes fonctionnalités "
                "auxquelles vous pouvez accéder en entrant le numéro associé.\n\n1 : Alimentation\n2 : Affichage\n3 : "
                "Opérations usuelles\n4 : Analyses statistiques\n5 : Quitter\n\n>");
        scanf(" %d", &choix_utilisateur);

        switch (choix_utilisateur) {
            case 1:
                boucle_1 = 1;
                while (boucle_1) {
                    printf("\nEntrez le numéro associé à la fonctionnalité :\n\n1 : Création d'un CDataframe vide\n"
                           "2 : Remplissage du CDataframe\n3 : Retour\n\n>");
                    scanf(" %d", &choix_utilisateur);
                    switch (choix_utilisateur) {
                        case 1:
                            printf("\nLe CDataFrame a été créé");
                            break;
                        case 2:
                            printf("\nVeuillez entrer un titre à cette nouvelle colonne :\n>");
                            char titre;
                            scanf(" %s", &titre);
                            COLONNE *mycol = creer_colonne(&titre);
                            printf("Combien de valeurs voulez-vous ajouter à cette colonne ?\n>");
                            int nb_valeurs;
                            scanf(" %d", &nb_valeurs);
                            printf("\n");
                            for(int i = 0; i < nb_valeurs; i++){
                                printf("Entrez une valeur :\n>");
                                int nouvelle_valeur;
                                scanf(" %d", &nouvelle_valeur);
                                inserer_valeur(mycol, nouvelle_valeur);
                            }
                            ajouter_colonne(myCDataframe, mycol);
                            afficher_cdataframe(myCDataframe);
                            break;
                        case 3:
                            boucle_1 = 0; break;
                        default: printf("\nEntrée invalide\n");
                    }
                }
                break;
            case 2:
                boucle_1 = 1;
                while (boucle_1) {
                    printf("\nEntrez le numéro associé à la fonctionnalité :\n\n1 : Afficher tout le CDataframe\n"
                           "2 : Afficher une partie des lignes du CDataframe\n"
                           "3 : Afficher une partie des colonnes du CDataframe\n4 : Retour\n\n>");
                    scanf(" %d", &choix_utilisateur);
                    switch (choix_utilisateur) {
                        case 1:
                            afficher_cdataframe(myCDataframe);
                            break;
                        case 2:
                            printf("Entrez une limite de lignes :\n>");
                            int limlig;
                            scanf(" %d", &limlig);
                            afficher_lignes_cdataframe(myCDataframe, limlig);
                            break;
                        case 3:
                            printf("Entrez une limite de colonnes :\n>");
                            int limcol;
                            scanf(" %d", &limcol);
                            afficher_colonnes_cdataframe(myCDataframe, limcol);
                            break;
                        case 4:
                            boucle_1 = 0; break;
                        default: printf("\nEntrée invalide\n");
                    }
                }
                break;
            case 3:
                boucle_1 = 1;
                while (boucle_1) {
                    printf("\nEntrez le numéro associé à la fonctionnalité :\n\n1 : Ajouter une ligne de valeurs\n2 : Supprimer une ligne de valeurs\n3 : Ajouter une colonne\n4 : Supprimer une colonne\n"
                           "5 : Renommer le titre d’une colonne du CDataframe\n6 : Vérifier l’existence d’une valeur (recherche) dans le CDataframe\n"
                           "7 : Accéder à la valeur se trouvant dans une cellule du CDataframe à partir de son indice de ligne et de colonne\n"
                           "8 : Afficher les noms des colonnes\n9 : Retour\n\n>");
                    scanf(" %d", &choix_utilisateur);
                    switch (choix_utilisateur) {
                        case 1:
                            printf("Entrez l'indice de la colonne que vous souhaitez supprimer\n");
                            int indice_supp = scanf(" %d");
                            supprimer_colonne_cdataframe(myCDataframe, indice_supp);
                            break;
                        case 2:
                            printf("Entrez l'indice de la colonne que vous souhaitez renommer\n");
                            int indice_rename = scanf(" %d");
                            printf("Indiquez le nouveau nom :\n");
                            char new_name = scanf(" %s");
                            renommer_colonne_cdataframe(myCDataframe, indice_rename, &new_name);
                            break;
                        case 3:
                            printf("Entrez les numéros de colonne et ligne");
                            int valeur, no_ligne, no_col;
                            scanf(" %d %d", &no_col, &no_ligne);
                            if (acceder_valeur_cellule(myCDataframe, no_col, no_ligne, &valeur)) {
                                printf("Valeur trouvée : %d\n", valeur);
                            } else {
                                printf("Erreur lors de l'accès à la valeur.\n");
                            }
                            break;
                        case 4:
                            afficher_noms_colonnes(myCDataframe);
                            break;

                    }
                }
                break;
            case 4:
                boucle_1 = 1;
                while (boucle_1) {
                    printf("\nEntrez le numéro associé à la fonctionnalité :\n\n"
                           "1 : Afficher le nombre de lignes\n"
                           "2 : Afficher le nombre de colonnes\n"
                           "3 : Nombre de cellules contenant une valeur égale à x\n"
                           "4 : Nombre de cellules contenant une valeur supérieure à x\n"
                           "5 : Nombre de cellules contenant une valeur inférieure à x\n6 : Retour\n\n>");
                    scanf(" %d", &choix_utilisateur);
                    switch (choix_utilisateur) {
                        case 1:
                            afficher_nombre_lignes(myCDataframe);
                            break;
                        case 2:
                            afficher_nombre_colonnes(myCDataframe);
                            break;
                        case 3:
                            printf("Entrez une valeur :\n>");
                            int val_egal;
                            scanf(" %d", &val_egal);
                            int nombre_egal = compter_cellules_valeur(myCDataframe, val_egal);
                            if (nombre_egal!=-1)
                                printf("Nombre de cellules contenant la valeur %d : %d\n", val_egal, nombre_egal);
                            break;
                        case 4:
                            printf("Entrez une valeur :\n>");
                            int val_sup;
                            scanf(" %d", &val_sup);
                            int nombre_sup = compter_cellules_superieures(myCDataframe, val_sup);
                            if (nombre_sup!=-1)
                                printf("Nombre de cellules contenant des valeurs supérieures à %d : %d\n", val_sup,
                                   nombre_sup);
                            break;
                        case 5:
                            printf("Entrez une valeur :\n>");
                            int val_inf;
                            scanf(" %d", &val_inf);
                            int nombre_inf = compter_cellules_inferieures(myCDataframe, val_inf);
                            if (nombre_inf!=-1)
                                printf("Nombre de cellules contenant des valeurs inférieures à %d : %d\n", val_inf,
                                   nombre_inf);
                            break;
                        case 6:
                            boucle_1 = 0; break;
                        default:
                            printf("\nEntrée invalide\n");
                    }
                }
                break;

            case 5: return 0;
            default: printf("\nEntrée invalide");
        }
    }
}