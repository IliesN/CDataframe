//
//
//

#include "colonne.h"
#include "cdataframe.h"
#include <stdio.h>
#include <stdlib.h>

int main() {

    printf("Bienvenue sur le CDataFrame de Ilies NASR et Ismael RADOUANE.\n\nEntrez n'importe quelle touche pour creer un CDataframe, entrez \"n\" pour quitter le programme.\n>");
    
    char choix_caractere;
    scanf("%c", &choix_caractere);
    printf("\n");

    if (choix_caractere == 'n') {
        return 0;
    } else {
        CDataframe *cdataframe = creer_cdataframe();

        if (cdataframe == NULL) {
            printf("Une erreur d'allocation est survenue.\nFin du programme.\n");
            return -1;
        }

        remplir_cdataframe_en_dur(cdataframe); //ecrire_cdataframe_fichier(NOM_FICHIER_AFFICHAGE, cdataframe, 0, 0);  afficher_cdataframe(cdataframe, 0, 0);  // Remplir & afficher le CDataframe en dur; a commenter pour laisser l'utilisateur saisir son contenu
        
        if (!cdataframe->nombre_colonnes) {
            printf("Votre CDataframe est vide.\nEntrez n'importe quelle touche afin de remplir le CDataframe, entrez \"n\" sinon.\n>");
            scanf("%c", &choix_caractere);
            printf("\n");
            
            if (choix_caractere != 'n') {
                remplir_cdataframe_utilisateur(cdataframe);
            }
        }

        int boucle_1;
        
        while (1) {
            int choix_entier;
            printf("Voici les differentes fonctionnalites auxquelles vous pouvez acceder en entrant le numero associe :\n\n"
            "1 : Affichage\n"
            "2 : Operations usuelles\n"
            "3 : Analyses statistiques\n"
            "4 : Quitter\n\n>");
            scanf(" %d", &choix_entier);
            printf("\n");

            switch (choix_entier) {
                case 1:
                    boucle_1 = 1;
                    while (boucle_1) {
                        printf("Entrez le numero associe a la fonctionnalite :\n\n"
                        "1 : Afficher l'integralite du CDataframe\n"
                        "2 : Afficher l'integralite du CDataframe en brut\n"
                        "3 : Afficher une partie du CDataframe\n"
                        "4 : Afficher une partie du CDataframe en brut\n"
                        "5 : Retour\n\n>");
                        scanf(" %d", &choix_entier);
                        printf("\n");

                        int limite_lignes, limite_colonnes;

                        switch (choix_entier) {
                            case 1:
                                afficher_cdataframe(cdataframe, 0, 0);

                                printf("Souhaitez vous exporter l'affichage dans un fichier \"affichage_cdataframe.txt\" ?\nEntrez n'importe quelle touche pour continuer, entrez \"n\" sinon.\n>");
                                scanf(" %c", &choix_caractere);
                                printf("\n");
                                if (choix_caractere != 'n') {
                                    ecrire_cdataframe_fichier(NOM_FICHIER_AFFICHAGE, cdataframe, 0, 0);
                                }
                                break;

                            case 2:
                                affichage_cdataframe_brut(cdataframe, 0, 0);
                                break;

                            case 3:
                                printf("Entrez une limite de lignes (entrez \"0\" si vous voulez afficher l'ensemble des lignes) :\n>");
                                scanf(" %d", &limite_lignes);
                                printf("Entrez une limite de colonnes (entrez \"0\" si vous voulez afficher l'ensemble des colonnes) :\n>");
                                scanf(" %d", &limite_colonnes);
                                printf("\n");

                                afficher_cdataframe_limite(cdataframe, limite_lignes, limite_colonnes);

                                printf("Souhaitez vous exporter l'affichage dans un fichier \"affichage_cdataframe.txt\" ?\nEntrez n'importe quelle touche pour continuer, entrez \"n\" sinon.\n>");
                                scanf(" %c", &choix_caractere);
                                printf("\n");
                                if (choix_caractere != 'n') {
                                    ecrire_cdataframe_fichier(NOM_FICHIER_AFFICHAGE, cdataframe, limite_lignes, limite_colonnes);
                                }
                                break;

                            case 4:
                                printf("Entrez une limite de lignes (entrez \"0\" si vous voulez afficher l'ensemble des lignes) :\n>");
                                scanf(" %d", &limite_lignes);
                                printf("Entrez une limite de colonnes (entrez \"0\" si vous voulez afficher l'ensemble des colonnes) :\n>");
                                scanf(" %d", &limite_colonnes);
                                printf("\n");

                                affichage_cdataframe_brut(cdataframe, limite_lignes, limite_colonnes);

                            case 5:
                                boucle_1 = 0;
                                break;
                            default:
                                entree_invalide();
                        }
                    }
                    break;

                case 2:
                    boucle_1 = 1;
                    while (boucle_1) {
                        printf("Entrez le numero associe a la fonctionnalite :\n\n"
                        "1 : Ajouter une ligne de valeurs\n"
                        "2 : Supprimer une ligne de valeurs d'indice x\n"
                        "3 : Ajouter des colonnes au CDataframe\n"
                        "4 : Supprimer une colonne d'indice x\n"
                        "5 : Renommer le titre d'une colonne du CDataframe d'indice x\n"
                        "6 : Verifier l'existence d'une valeur x\n"
                        "7 : Acceder a la valeur se trouvant dans une cellule du CDataframe a partir de ses indices de positions\n"
                        "8 : Afficher les noms de l'integralite des colonnes\n"
                        "9 : Retour\n\n>");
                        scanf(" %d", &choix_entier);
                        printf("\n");

                        switch (choix_entier) {
                            int resultat;
                            case 1:
                                if (!cdataframe->nombre_colonnes) {
                                    cdataframe_vide();
                                } else {
                                    int *tableau_valeurs = (int *) calloc(cdataframe->nombre_colonnes, sizeof(int));
                                    for (int i = 0; i < cdataframe->nombre_colonnes; i++) {
                                        printf("Entrez la valeur de la colonne d'indice %d que vous souhaitez ajouter :\n>", i);
                                        scanf(" %d", &choix_entier);
                                        tableau_valeurs[i] = choix_entier;
                                    }
                                    printf("\n");
                                    resultat = ajouter_ligne(cdataframe, tableau_valeurs);
                                    if (!resultat) {
                                        printf("La ligne a bien ete ajoutee.\n");
                                    } else {
                                        printf("Une erreur d'ajout est survenue.\n");
                                    }
                                }
                                printf("\n");
                                break;

                            case 2:
                                printf("Entrez l'indice de la ligne que vous souhaitez supprimer (vous pouvez afficher le CDataframe pour acceder a son indice) :\n>");
                                scanf(" %d", &choix_entier);
                                supprimer_ligne_indice(cdataframe, choix_entier);
                                break;

                            case 3:
                                remplir_cdataframe_utilisateur(cdataframe);
                                break;

                            case 4:
                                printf("Entrez l'indice de la colonne que vous souhaitez supprimer (vous pouvez afficher le CDataframe pour acceder a son indice) :\n>");
                                scanf(" %d", &choix_entier);
                                supprimer_colonne_indice(cdataframe, choix_entier);
                                break;

                            case 5:
                                printf("Entrez l'indice de la colonne que vous souhaitez renommer (vous pouvez afficher le CDataframe pour acceder a son indice) :\n>");
                                scanf(" %d", &choix_entier);
                                renommer_colonne(cdataframe, choix_entier);
                                break;

                            case 6:
                                printf("Entrez la valeur que vous recherchez :\n>");
                                scanf(" %d", &choix_entier);
                                resultat = existence_valeur(cdataframe, choix_entier);
                                if (!resultat) {
                                    printf("La valeur n'existe pas dans le CDataframe.");
                                } else if (resultat == 1) {
                                    printf("La valeur existe dans le CDataframe.");
                                }
                                break;

                            case 7:
                                if (!cdataframe->nombre_colonnes) {
                                    cdataframe_vide();
                                    break;
                                }
                                int indice_ligne, indice_colonne;
                                printf("Entrez l'indice de ligne de la valeur recherchee (vous pouvez afficher le CDataframe pour acceder a son indice) :\n>");
                                scanf(" %d", &indice_ligne);
                                if (indice_ligne > recuperer_nombre_lignes(cdataframe) - 1 || indice_ligne < 0) {
                                    printf("L'indice de ligne saisi est trop faible ou trop eleve.\n");
                                    break;
                                }
                                printf("Entrez l'indice de colonne de la valeur recherchee (vous pouvez afficher le CDataframe pour acceder a son indice) :\n>");
                                scanf(" %d", &indice_colonne);

                                if (indice_colonne > cdataframe->nombre_colonnes - 1 || indice_colonne < 0) {
                                    printf("L'indice de colonne saisi est trop faible ou trop eleve.\n");
                                    break;
                                }
                                printf("La valeur d'indice de colonne %d et d'indice de ligne %d est : %d\n", indice_colonne, indice_ligne, acceder_valeur_cellule(cdataframe, indice_colonne, indice_ligne));
                                break;

                            case 8:
                                afficher_noms_colonnes(cdataframe);
                                break;

                            case 9:
                                boucle_1 = 0;
                                break;
                            default:
                                entree_invalide();
                        }
                    }
                    break;
                case 3:
                    boucle_1 = 1;
                    while (boucle_1) {
                        printf("Entrez le numero associe a la fonctionnalite :\n\n"
                            "1 : Afficher le nombre de lignes du CDataframe\n"
                            "2 : Afficher le nombre de colonnes du CDataframe\n"
                            "3 : Nombre de cellules contenant une valeur egale a x\n"
                            "4 : Nombre de cellules contenant une valeur superieure aa x\n"
                            "5 : Nombre de cellules contenant une valeur inferieure a x\n6 : Retour\n\n>");
                        scanf(" %d", &choix_entier);
                        switch (choix_entier) {
                            case 1:
                                resultat = recuperer_nombre_lignes(cdataframe);
                                if (resultat == -1) {
                                    cdataframe_vide();
                                } else {
                                    printf("Le CDataframe contient %d lignes.\n", retourner_nombre_lignes(cdataframe));
                                }
                                break;

                            case 2:
                                printf("Le CDataframe contient %d colonnes.\n", cdataframe->nombre_colonnes);
                                break;

                            case 3:
                                printf("Entrez la valeur que vous recherchez :\n>");
                                scanf(" %d", &choix_entier);
                                resultat = compter_cellules_valeur(cdataframe, choix_entier);
                                if (resultat == -1) {
                                    cdataframe_vide();
                                } else {
                                    printf("Le nombre de cellules contenant la valeur \"%d\" est : %d\n", choix_entier, resultat);
                                }
                                break;

                            case 4:
                                printf("Entrez la valeur que vous voulez comparez :\n>");
                                scanf(" %d", &choix_entier);
                                resultat = compter_cellules_superieures(cdataframe, choix_entier);
                                if (resultat == -1) {
                                    cdataframe_vide();
                                } else {
                                    printf("Le nombre de cellules superieures a la valeur \"%d\" est : %d\n", choix_entier, resultat);
                                }
                                break;

                            case 5:
                                printf("Entrez la valeur que vous voulez comparez :\n>");
                                scanf(" %d", &choix_entier);
                                resultat = compter_cellules_inferieures(cdataframe, choix_entier);
                                if (resultat == -1) {
                                    cdataframe_vide();
                                } else {
                                    printf("Le nombre de cellules inferieures a la valeur \"%d\" est : %d\n", choix_entier, resultat);
                                }
                                break;

                            case 6:
                                boucle_1 = 0;
                                break;
                            default:
                                entree_invalide();
                        }
                    }
                    break;

                case 4:
                    return 0;
                default:
                    entree_invalide();
            }
        }
    }
}
