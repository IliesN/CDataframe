//
//
//

#include "colonne.h"
#include "cdataframe.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


CDataframe *creer_cdataframe() {
    CDataframe *cdataframe = malloc(sizeof(CDataframe));
    if (!cdataframe) {
        return NULL; // Échec de l'allocation
    }

    cdataframe->colonnes = NULL;
    cdataframe->nombre_colonnes = 0;
    cdataframe->capacite = 0;

    return cdataframe;
}

int ajouter_colonne(CDataframe *cdataframe, COLONNE *colonne) {
    if (cdataframe->nombre_colonnes == cdataframe->capacite) { // Vérifie si le tableau est plein
        int new_capacite;
        if (!cdataframe->capacite) {
            new_capacite = TAILLE_REALLOC;
        } else {
            new_capacite = cdataframe->capacite * 2; // Double la capacité existante
        }
        COLONNE **new_colonnes = realloc(cdataframe->colonnes, new_capacite * sizeof(COLONNE *));
        if (!new_colonnes) {
            return -1;
        }

        cdataframe->colonnes = new_colonnes;
        cdataframe->capacite = new_capacite;
    }

    cdataframe->colonnes[cdataframe->nombre_colonnes] = colonne;
    cdataframe->nombre_colonnes++;
    return 0;
}

void remplir_cdataframe_utilisateur(CDataframe *cdataframe) {
    int choix_nombre_colonne;

    printf("Combien de colonnes voulez-vous ajouter au CDataframe ?\n>");
    scanf(" %d", &choix_nombre_colonne);
    printf("\n");

    for (int i = 0; i < choix_nombre_colonne; i++) {
        printf("Veuillez entrer un titre a la colonne d'indice %d :\n>", i);

        char titre[TAILLE_TITRE];
        scanf(" %s", titre);

        COLONNE *colonne = creer_colonne(titre);

        printf("Combien de valeurs voulez vous ajouter a cette colonne ?\n>");
        int choix_nombre_valeurs;
        scanf(" %d", &choix_nombre_valeurs);
        printf("\n");

        for (int i = 0; i < choix_nombre_valeurs; i++) {
            printf("Entrez la valeur d'indice %d :\n>", i);
            int nouvelle_valeur;
            scanf(" %d", &nouvelle_valeur);
            inserer_valeur(colonne, nouvelle_valeur);
        }
        printf("\n");

        ajouter_colonne(cdataframe, colonne);
    }
}

void remplir_cdataframe_en_dur(CDataframe *cdataframe) {
    COLONNE *colonne1 = creer_colonne("Titre1_test");
    inserer_valeur(colonne1, 1);
    inserer_valeur(colonne1, 2);
    inserer_valeur(colonne1, 3);
    ajouter_colonne(cdataframe, colonne1);

    COLONNE *colonne2 = creer_colonne("Titre2");
    inserer_valeur(colonne2, 1);
    inserer_valeur(colonne2, 2);
    inserer_valeur(colonne2, 1);
    inserer_valeur(colonne2, 2);
    inserer_valeur(colonne2, 1);
    inserer_valeur(colonne2, 2);
    inserer_valeur(colonne2, 1);
    inserer_valeur(colonne2, 2);
    inserer_valeur(colonne2, 1);
    inserer_valeur(colonne2, 2);
    inserer_valeur(colonne2, 2);
    ajouter_colonne(cdataframe, colonne2);

    COLONNE *colonne3 = creer_colonne("Titre3");
    inserer_valeur(colonne3, 2);
    inserer_valeur(colonne3, 3);
    inserer_valeur(colonne3, 43);
    inserer_valeur(colonne3, 142);
    ajouter_colonne(cdataframe, colonne3);
    /*
    COLONNE *colonne4 = creer_colonne("Titre4");
    inserer_valeur(colonne4, 10);
    inserer_valeur(colonne4, 20);
    inserer_valeur(colonne4, 30);
    inserer_valeur(colonne4, 40);
    ajouter_colonne(cdataframe, colonne4);

    COLONNE *colonne5 = creer_colonne("Titre5");
    inserer_valeur(colonne5, 5);
    inserer_valeur(colonne5, 10);
    inserer_valeur(colonne5, 15);
    inserer_valeur(colonne5, 20);
    inserer_valeur(colonne5, 25);
    ajouter_colonne(cdataframe, colonne5);

    COLONNE *colonne6 = creer_colonne("Titre6");
    inserer_valeur(colonne6, 1);
    inserer_valeur(colonne6, 2);
    inserer_valeur(colonne6, 3);
    inserer_valeur(colonne6, 4);
    inserer_valeur(colonne6, 5);
    inserer_valeur(colonne6, 6);
    inserer_valeur(colonne6, 7);
    inserer_valeur(colonne6, 8);
    inserer_valeur(colonne6, 9);
    inserer_valeur(colonne6, 10);
    ajouter_colonne(cdataframe, colonne6);

    COLONNE *colonne7 = creer_colonne("Titre7");
    inserer_valeur(colonne7, 50);
    inserer_valeur(colonne7, 100);
    inserer_valeur(colonne7, 150);
    inserer_valeur(colonne7, 200);
    inserer_valeur(colonne7, 250);
    inserer_valeur(colonne7, 300);
    ajouter_colonne(cdataframe, colonne7);

    COLONNE *colonne8 = creer_colonne("Titre8");
    inserer_valeur(colonne8, -1);
    inserer_valeur(colonne8, -2);
    inserer_valeur(colonne8, -3);
    inserer_valeur(colonne8, -4);
    inserer_valeur(colonne8, -5);
    ajouter_colonne(cdataframe, colonne8);

    COLONNE *colonne9 = creer_colonne("Titre9");
    inserer_valeur(colonne9, 1000);
    inserer_valeur(colonne9, 2000);
    inserer_valeur(colonne9, 3000);
    inserer_valeur(colonne9, 4000);
    inserer_valeur(colonne9, 5000);
    ajouter_colonne(cdataframe, colonne9);

    COLONNE *colonne10 = creer_colonne("Titre10");
    inserer_valeur(colonne10, 1);
    inserer_valeur(colonne10, 1);
    ajouter_colonne(cdataframe, colonne10);

    COLONNE *colonne11 = creer_colonne("dfsgsdfgsdfgsdfgsdf");
    inserer_valeur(colonne11, 1);
    inserer_valeur(colonne11, 1);
    ajouter_colonne(cdataframe, colonne11);

    COLONNE *colonne12 = creer_colonne("dfsgsdfgsdsdfgsdf");
    inserer_valeur(colonne12, 1);
    inserer_valeur(colonne12, 1);
    ajouter_colonne(cdataframe, colonne12);*/
}



void afficher_cdataframe(CDataframe *cdataframe) {
    if (!cdataframe->nombre_colonnes) {
        cdataframe_vide();
        return;
    }

    int i;

    int longueur_caractere_tableau = 0;
    int nombre_lignes_max = retourner_nombre_lignes(cdataframe);
    int longueur_nombre_ligne_max = longueur_nombre(nombre_lignes_max);
    int longueur_titre_maximale = 0;

    for (i = 0; i < cdataframe->nombre_colonnes; i++) {
        int longueur_titre = strlen(cdataframe->colonnes[i]->titre);
        if (longueur_titre > longueur_titre_maximale) {
            longueur_titre_maximale = longueur_titre;
        }
    }
    int ajout_titre = 3 + 1 + longueur_nombre_ligne_max + 1; // + "  [taille indice]"

    longueur_titre_maximale += ajout_titre;

    for (i = 0; i < cdataframe->nombre_colonnes; i++) {
        longueur_caractere_tableau += 3 + longueur_titre_maximale;
    }
    longueur_caractere_tableau -= 1;
    
    for (i = 0; i < 2 + longueur_nombre_ligne_max + 2; i++) {
        printf(" ");
    }
    for (i = 0; i < longueur_caractere_tableau; i++) {
        printf("_");
    }
    printf("\n");
    
    for (i = 0; i < 3 + longueur_nombre_ligne_max; i++) {
        printf(" ");
    }
    for (i = 0; i < cdataframe->nombre_colonnes; i++) {
        afficher_titre_espaces(cdataframe->colonnes[i]->titre, longueur_titre_maximale, longueur_nombre_ligne_max, ajout_titre, i);
    }
    printf("|\n _");
    for (i = 0; i < longueur_nombre_ligne_max; i++) {
        printf("_");
    }
    printf("_");
    for (i = 0; i < cdataframe->nombre_colonnes; i++) {
        printf("|_");
        for (int j = 0; j < longueur_titre_maximale; j++)
            printf("_");
        printf("_");
    }
    printf("|\n");

    for (i = 0; i < nombre_lignes_max; i++) {
        printf("| ");
        afficher_valeur_espaces(i, longueur_nombre_ligne_max, 1);
        printf(" ");
        for (int j = 0; j < cdataframe->nombre_colonnes; j++) {
            printf("| ");
            afficher_valeur_espaces(cdataframe->colonnes[j]->donnees[i], longueur_titre_maximale, 0);
            printf(" ");
        }
        printf("|\n");
        fermer_tableau(cdataframe->nombre_colonnes, longueur_titre_maximale, longueur_nombre_ligne_max);
    }
    printf("\n\n");
}

void ecrire_dataframe_fichier(char *nom_fichier, CDataframe *cdataframe) {
    // Ouvre un fichier en mode écriture avec le nom spécifié dans la variable et stocke le pointeur de fichier dans la variable "fichier"
    FILE *fichier = fopen(nom_fichier, "w");

    // Redirige la sortie standard (stdout) vers le fichier spécifié par "nom_fichier". À partir de maintenant, toutes les sorties de printf seront écrites dans le fichier.
    freopen(nom_fichier, "w", stdout);

    // Appelle la fonction "afficher_cdataframe" pour afficher le contenu du CDataframe. Comme la sortie standard a été redirigée, le résultat sera écrit dans le fichier.
    afficher_cdataframe(cdataframe);

    // Restaure la sortie standard (stdout) en la redirigeant vers la console ("CON"). Les sorties de printf reviendront à leur comportement normal (affichage à l'écran).
    freopen("CON", "w", stdout);

    // Ferme le fichier ouvert précédemment.
    fclose(fichier);
}

void afficher_lignes_cdataframe(CDataframe *cdataframe, int limite){
    if (!retourner_nombre_lignes(cdataframe)) {
        printf("Le CDataframe est vide ou ne contient aucune lignes.\n");
        return;
    }
    for (int i = 0; i < limite; i++) {
        for (int j = 0; j < cdataframe->nombre_colonnes; j++) {
            printf("%d\t", cdataframe->colonnes[j]->donnees[i]);
        }
        printf("\n");
    }
}

void afficher_colonnes_cdataframe(CDataframe *cdataframe, int limite) {
    if (!cdataframe->nombre_colonnes) {
        cdataframe_vide();
        return;
    }
    int nombre_lignes = cdataframe->colonnes[0]->taille_logique;
    for (int i = 0; i < nombre_lignes; i++) {
        for (int j = 0; j < limite; j++) {
            printf("%d\t", cdataframe->colonnes[j]->donnees[i]);
        }
        printf("\n");
    }
}



// ajouter_ligne | FONCTION A AJOUTER !

void supprimer_ligne_indice(CDataframe *cdataframe, int indice_ligne) {
    // Supprimer la ligne pour chaque colonne
    for (int i = 0; i < cdataframe->nombre_colonnes; i++) {
        COLONNE *colonne = cdataframe->colonnes[i];
        // Décaler les données des lignes suivantes vers le haut
        for (int j = indice_ligne; j < colonne->taille_logique - 1; j++) {
            colonne->donnees[j] = colonne->donnees[j + 1];
        }
        // Mettre à jour la taille logique de la colonne
        colonne->taille_logique--;
    }
}

void supprimer_colonne_indice(CDataframe *cdataframe, int indice_colonne) {
    // Libérer la mémoire de la colonne spécifiée
    supprimer_colonne(&(cdataframe->colonnes[indice_colonne]));

    // Décaler les pointeurs pour combler le trou
    for (int i = indice_colonne; i < cdataframe->nombre_colonnes - 1; i++) {
        cdataframe->colonnes[i] = cdataframe->colonnes[i + 1];
    }

    // Réduire le nombre de colonnes
    cdataframe->nombre_colonnes--;
}

void renommer_colonne(CDataframe *cdataframe, int indice_colonne, char *nouveau_titre) {
    COLONNE *colonne = cdataframe->colonnes[indice_colonne];

    if (colonne->titre) {
        free(colonne->titre);
    }

    // Allocation du nouveau titre
    colonne->titre = malloc(strlen(nouveau_titre) + 1); // + 1 pour le caractère de fin '\0'

    int i;
        
    for (i = 0; nouveau_titre[i] != '\0'; i++) {
        colonne->titre[i] = nouveau_titre[i];
    }
    colonne->titre[i] = '\0'; // Ajout du caractère de fin '\0'
}

int existence_valeur(CDataframe *cdataframe, int valeur_recherchee) {
    if (!cdataframe->nombre_colonnes) {
        return -1;
    }

    for (int i = 0; i < cdataframe->nombre_colonnes; i++) {
        COLONNE *colonne = cdataframe->colonnes[i];
        for (int j = 0; j < colonne->taille_logique; j++) {
            if (colonne->donnees[j] > valeur_recherchee) {
                return 1;
            }
        }
    }
    
    return 0;
}

int acceder_valeur_cellule(CDataframe *cdataframe, int indice_colonne, int indice_ligne, int *valeur) {
    COLONNE *colonne = cdataframe->colonnes[indice_colonne];
    return colonne->donnees[indice_ligne];
}

void afficher_noms_colonnes(CDataframe *cdataframe) {
    if (!cdataframe->colonnes) {
        cdataframe_vide();
        return;
    }

    printf("Noms des colonnes du CDataframe:\n");
    for (int i = 0; i < cdataframe->nombre_colonnes; i++) {
        printf("Colonne d'indice %d: %s\n", i, cdataframe->colonnes[i]->titre);
    }
}



int retourner_nombre_lignes(CDataframe *cdataframe) {
    if (!cdataframe->nombre_colonnes) {
        return 0;
    }  

    int nombre_lignes_max = 0;
    for (int i = 0; i < cdataframe->nombre_colonnes; i++) {
        if (cdataframe->colonnes[i]->taille_logique > nombre_lignes_max) {
            nombre_lignes_max = cdataframe->colonnes[i]->taille_logique;
        }
    }
    
    return nombre_lignes_max;
}

int compter_cellules_valeur(CDataframe *cdataframe, int valeur_recherchee) {
    if (!cdataframe->colonnes) {
        return -1;
    }

    int compteur = 0;
    for (int i = 0; i < cdataframe->nombre_colonnes; i++) {
        COLONNE *colonne = cdataframe->colonnes[i];
        for (int j = 0; j < colonne->taille_logique; j++) {
            if (colonne->donnees[j] == valeur_recherchee) {
                compteur++;
            }
        }
    }

    return compteur;
}

int compter_cellules_superieures(CDataframe *cdataframe, int valeur_comparee) {
    if (!cdataframe->colonnes) {
        return -1;
    }

    int compteur = 0;
    for (int i = 0; i < cdataframe->nombre_colonnes; i++) {
        COLONNE *colonne = cdataframe->colonnes[i];
        for (int j = 0; j < colonne->taille_logique; j++) {
            if (colonne->donnees[j] > valeur_comparee) {
                compteur++;
            }
        }
    }

    return compteur;
}

int compter_cellules_inferieures(CDataframe *cdataframe, int valeur_comparee) {
    if (!cdataframe->colonnes) {
        return -1;
    }

    int compteur = 0;
    for (int i = 0; i < cdataframe->nombre_colonnes; i++) {
        COLONNE *colonne = cdataframe->colonnes[i];
        for (int j = 0; j < colonne->taille_logique; j++) {
            if (colonne->donnees[j] < valeur_comparee) {
                compteur++;
            }
        }
    }

    return compteur;
}




int longueur_nombre(int nombre) {
    if (!nombre) {
        return 1;
    }

    int taille_nombre = 0;
    if (nombre < 0) {
        taille_nombre += 1;
    }

    while (nombre != 0) {
        nombre /= 10;
        taille_nombre++;
    }

    return taille_nombre;
}

void afficher_titre_espaces(char *chaine, int taille_chaine_maximale, int longueur_indice_maximale, int longueur_ajout_titre, int indice_colonne) {
    int taille_chaine = strlen(chaine);
    int taille_restante = taille_chaine_maximale - taille_chaine - longueur_ajout_titre;

    printf("| %s", chaine);
    for (int i = 0; i < taille_restante + longueur_indice_maximale - longueur_nombre(indice_colonne); i++) {
        printf(" ");
    }
    printf("   [%d] ", indice_colonne);
}

void afficher_valeur_espaces(int entier, int taille_chaine_maximale, int cote_affichage) {
    int nombre_espaces = taille_chaine_maximale - longueur_nombre(entier);
    if (!cote_affichage) {
        printf("%d", entier);
        for (int i = 0; i < nombre_espaces; i++) {
            printf(" ");
        }
    } else {
        for (int i = 0; i < nombre_espaces; i++) {
            printf(" ");
        }
        printf("%d", entier);
    }
}

void fermer_tableau(int nombre_colonnes, int longueur_chaine, int longueur_nombre_ligne_max) {
    int i;
    
    printf("|_");
    for (i = 0; i < longueur_nombre_ligne_max; i++) {
        printf("_");
    }
    printf("_");
    for (i = 0; i < nombre_colonnes; i++) {
        printf("|_");
        for (int j = 0; j < longueur_chaine; j++) {
            printf("_");
        }
        printf("_");
    }
    printf("|\n");
}




void cdataframe_vide() {
    printf("Le CDataframe est vide.\n");
}

void entree_invalide() {
    printf("Entree invalide.\n");
}
