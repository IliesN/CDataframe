#include "colonne.h"
#include "cdataframe.h"
#include <stdio.h>

int main() {

    printf("Bienvenue sur le CDataFrame de Ilies NASR et Ismael RADOUANE.\n\nEntrez n'importe quelle touche pour creer un CDataframe, entrez \"n\" pour quitter le programme.\n>");
    
    char choix_initial;
    scanf("%c", &choix_initial);
    printf("\n");

    if(choix_initial == 'n'){
        return 0;
    } else {
        CDataframe* cdataframe = creer_cdataframe();

        //remplissage_en_dur(cdataframe); ecrire_affichage_fichier(NOM_FICHIER_AFFICHAGE, cdataframe);  // Remplir & afficher le CDataframe en dur; à commenter pour laisser l'utilisateur saisir son contenu
        
        if (cdataframe->nombre_colonnes == 0) {
            printf("Votre CDataframe est vide.\nEntrez n'importe quelle touche afin de remplir le CDataframe, entrez \"n\" sinon.\n>");
            scanf("%c", &choix_initial);
            printf("\n");
            
            if (choix_initial != 'n') {
                remplir_cdataframe(cdataframe);
            }
        }

        int boucle_1;

        while (1) {
            int choix_utilisateur;
            printf("Voici les differentes fonctionnalites auxquelles vous pouvez acceder en entrant le numero associe :\n\n"
            "1 : Affichage\n"
            "2 : Operations usuelles\n"
            "3 : Analyses statistiques\n"
            "4 : Quitter\n\n>");
            scanf(" %d", &choix_utilisateur);
            printf("\n");

            switch (choix_utilisateur) {
                case 1:
                    boucle_1 = 1;
                    while (boucle_1) {
                        printf("Entrez le numero associe a la fonctionnalite :\n\n"
                        "1 : Afficher tout le CDataframe\n"
                        "2 : Afficher une partie des lignes du CDataframe\n"
                        "3 : Afficher une partie des colonnes du CDataframe\n"
                        "4 : Retour\n\n>");
                        scanf(" %d", &choix_utilisateur);
                        printf("\n");

                        switch (choix_utilisateur) {
                            case 1:
                                afficher_cdataframe(cdataframe);
                                break;
                            case 2:
                                printf("Entrez une limite de lignes :\n>");
                                int limite_lignes;
                                scanf(" %d", &limite_lignes);
                                afficher_lignes_cdataframe(cdataframe, limite_lignes);
                                break;
                            case 3:
                                printf("Entrez une limite de colonnes :\n>");
                                int limite_colonnes;
                                scanf(" %d", &limite_colonnes);
                                afficher_colonnes_cdataframe(cdataframe, limite_colonnes);
                                break;
                            case 4:
                                boucle_1 = 0;
                                break;
                            default: entree_invalide();
                        }
                    }
                    break;

                case 2:
                    boucle_1 = 1;
                    while (boucle_1) {
                        printf("Entrez le numero associe a la fonctionnalite :\n\n"
                        "1 : Ajouter une ligne de valeurs\n"
                        "2 : Supprimer une ligne de valeurs\n"
                        "3 : Ajouter une colonne\n"
                        "4 : Supprimer une colonne\n"
                        "5 : Renommer le titre d'une colonne du CDataframe\n"
                        "6 : Verifier l'existence d'une valeur (recherche) dans le CDataframe\n"
                        "7 : Accéder a la valeur se trouvant dans une cellule du CDataframe a partir de son indice de ligne et de colonne\n"
                        "8 : Afficher les noms des colonnes\n"
                        "9 : Retour\n\n>");
                        scanf(" %d", &choix_utilisateur);
                        printf("\n");

                        switch (choix_utilisateur) {
                            case 1:
                                break;
                            case 2:
                                break;
                            case 3:
                                printf("Veuillez entrer un titre a cette nouvelle colonne :\n>");
                                char titre;
                                scanf(" %s", &titre);
                                COLONNE *mycol = creer_colonne(&titre);
                                printf("Combien de valeurs voulez-vous ajouter a cette colonne ?\n>");
                                int nombre_valeurs;
                                scanf(" %d", &nombre_valeurs);
                                printf("\n");
                                for(int i = 0; i < nombre_valeurs; i++){
                                    printf("Entrez une valeur :\n>");
                                    int nouvelle_valeur;
                                    scanf(" %d", &nouvelle_valeur);
                                    inserer_valeur(mycol, nouvelle_valeur);
                                }
                                ajouter_colonne(cdataframe, mycol);
                                break;
                            case 4:
                                printf("Entrez l'indice de la colonne que vous souhaitez supprimer\n");
                                int indice_supp;
                                scanf(" %d", &indice_supp);
                                supprimer_colonne_cdataframe(cdataframe, indice_supp);
                                break;
                            case 5:
                                break;
                            case 6:
                                printf("Entrez une valeur :\n>");
                                int val_egal;
                                scanf(" %d", &val_egal);
                                int nombre_egal = compter_cellules_valeur(cdataframe, val_egal);
                                if (nombre_egal!=-1) {
                                    if (nombre_egal>=1) {printf("La valeur existe dans le CDataframe\n");}
                                    else {printf("La valeur n'existe pas\n");}
                                }
                                break;

                            case 7:
                                printf("Entrez les numeros de colonne et ligne");
                                int valeur, no_ligne, no_col;
                                scanf(" %d %d", &no_col, &no_ligne);
                                if (acceder_valeur_cellule(cdataframe, no_col, no_ligne, &valeur)) {
                                    printf("Valeur trouvee : %d\n", valeur);
                                } else {
                                    printf("Erreur lors de l'acces a la valeur.\n");
                                }
                                break;
                            case 8:
                                afficher_noms_colonnes(cdataframe);
                                break;
                            case 9:
                                boucle_1 = 0; break;
                            default:
                                entree_invalide();
                        }
                    }
                    break;
                case 3:
                    boucle_1 = 1;
                    while (boucle_1) {
                        printf("Entrez le numero associe a la fonctionnalite :\n\n"
                            "1 : Afficher le nombre de lignes\n"
                            "2 : Afficher le nombre de colonnes\n"
                            "3 : Nombre de cellules contenant une valeur égale à x\n"
                            "4 : Nombre de cellules contenant une valeur supérieure à x\n"
                            "5 : Nombre de cellules contenant une valeur inférieure à x\n6 : Retour\n\n>");
                        scanf(" %d", &choix_utilisateur);
                        switch (choix_utilisateur) {
                            case 1:
                                ////////////afficher_nombre_lignes(cdataframe);
                                break;
                            case 2:
                                afficher_nombre_colonnes(cdataframe);
                                break;
                            case 3:
                                printf("Entrez une valeur :\n>");
                                int val_egal;
                                scanf(" %d", &val_egal);
                                int nombre_egal = compter_cellules_valeur(cdataframe, val_egal);
                                if (nombre_egal!=-1)
                                    printf("Nombre de cellules contenant la valeur %d : %d\n", val_egal, nombre_egal);
                                break;
                            case 4:
                                printf("Entrez une valeur :\n>");
                                int val_sup;
                                scanf(" %d", &val_sup);
                                int nombre_sup = compter_cellules_superieures(cdataframe, val_sup);
                                if (nombre_sup!=-1)
                                    printf("Nombre de cellules contenant des valeurs superieures a %d : %d\n", val_sup,
                                    nombre_sup);
                                break;
                            case 5:
                                printf("Entrez une valeur :\n>");
                                int val_inf;
                                scanf(" %d", &val_inf);
                                int nombre_inf = compter_cellules_inferieures(cdataframe, val_inf);
                                if (nombre_inf!=-1)
                                    printf("Nombre de cellules contenant des valeurs inferieures a %d : %d\n", val_inf,
                                    nombre_inf);
                                break;
                            case 6:
                                boucle_1 = 0; break;
                            default:
                                entree_invalide();
                        }
                    }
                    break;

                case 4: return 0;
                default: entree_invalide();
            }
        }
    }
}
