//
//
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "colonne.h"

COLONNE *creer_colonne(char *titre) {
    COLONNE * colonne = (COLONNE *) malloc(sizeof(COLONNE));

    colonne->titre = (char *) malloc(strlen(titre) + 1);

    // Copie le titre dans la mémoire allouée caractère par caractère
    int i;
    for (i = 0; titre[i] != '\0'; i++) {
        colonne->titre[i] = titre[i];
    }
    colonne->titre[i] = '\0'; // Ajout du caractère de fin '\0'

    colonne-> donnees = NULL;
    colonne->taille_physique = 0;
    colonne->taille_logique = 0;

    return colonne;
}


int inserer_valeur(COLONNE *colonne, int valeur) {
    int *donnees_realloc = NULL;

    if (!colonne) {
        return -1;
    }

    if (colonne->taille_logique == colonne->taille_physique) {
        colonne->taille_physique = TAILLE_REALLOC;
        if (colonne->donnees == NULL) {
            donnees_realloc = (int *) calloc(TAILLE_REALLOC, sizeof(int));
        } else {
            donnees_realloc = realloc(colonne->donnees, colonne->taille_physique);
        }
        if (!donnees_realloc) {
            return -1;
        } else {
            colonne->donnees = donnees_realloc;
        }
    }

    colonne->donnees[(colonne->taille_logique)++] = valeur;

    return 0;
}

void supprimer_colonne(COLONNE **colonne) {
    free((*colonne)->donnees);
    (*colonne)->donnees = NULL;

    free(colonne);
    colonne = NULL;
}

void afficher_colonne(COLONNE *colonne) {
    for (int i = 0; i < colonne->taille_logique; i++) {
        printf("[%d] %d\n", i, colonne->donnees[i]);
    }
}

int nombre_occurences(COLONNE *colonne, int valeur) {
    int total = 0;
    for (int i = 0; i < colonne->taille_logique; i++) {
        if(colonne->donnees[i] == valeur) {
            total++;
        }
    }
    return total;
}

int retourner_postion(COLONNE *colonne, int indice) {
    if (colonne->donnees[indice]) {
        return colonne->donnees[indice];
    } else {
        return -1;
    }
}

int retourner_superieur(COLONNE *colonne, int valeur) {
    int total = 0;
    for (int i = 0; i < colonne->taille_logique; i++) {
        if(colonne->donnees[i] > valeur) {
            total++;
        }
    }
    return total;
}

int retourner_inferieur(COLONNE *colonne, int valeur) {
    int total = 0;
    for (int i = 0; i < colonne->taille_logique; i++) {
        if (colonne->donnees[i] < valeur) {
            total++;
        }
    }
    return total;
}
