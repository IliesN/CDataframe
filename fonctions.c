#include "fonctions.h"
#include <stdio.h>
#include <stdlib.h>

COLONNE *creer_colonne(char * titre) {
    COLONNE * colonne = (COLONNE *) malloc(sizeof(COLONNE));

    colonne -> titre = titre;
    colonne -> donnees = NULL;
    colonne -> taille_physique = 0;
    colonne -> taille_logique = 0;

    return colonne;
}


int inserer_valeur(COLONNE * col, int value) {
    int * donnees_realloc = NULL;

    if (!col) return 0;

    if (col -> taille_logique == col -> taille_physique) {
        col -> taille_physique = TAILLE_REALLOC;
        if (col -> donnees == NULL) {
            donnees_realloc = (int *) calloc(TAILLE_REALLOC, sizeof(int));
        } else {
            donnees_realloc = realloc(col -> donnees, col -> taille_physique);
        }
        if (!donnees_realloc) {
            return 0;
        } else {
            col -> donnees = donnees_realloc;
        }
    }

    col -> donnees[(col -> taille_logique)++] = value;

    return 1;
}

void supprimer_colonne(COLONNE **col) {
    free((* col) -> donnees);
    (* col) -> donnees = NULL;

    free(col);
    col = NULL;
}

void afficher_colonne(COLONNE * col) {
    for (int i = 0; i < col -> taille_logique; i++)
        printf("[%d] %d\n", i, col -> donnees[i]);
}

// ILIES 4.1.5 page 11
