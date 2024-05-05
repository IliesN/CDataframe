//
//
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "colonne.h"

Colonne *creer_colonne(char *titre) {
    Colonne * colonne = (Colonne *) malloc(sizeof(Colonne));

    colonne->titre = (char *) malloc(strlen(titre) + 1);

    // Copie le titre dans la memoire allouee caractere par caractere
    int i;
    for (i = 0; titre[i] != '\0'; i++) {
        colonne->titre[i] = titre[i];
    }
    colonne->titre[i] = '\0'; // Ajout du caractere de fin '\0'

    colonne->donnees = NULL;
    colonne->taille_physique = 0;
    colonne->taille_logique = 0;

    return colonne;
}


int inserer_valeur(Colonne *colonne, int valeur) {
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

void supprimer_colonne(Colonne **colonne) {
    free((*colonne)->donnees);
    (*colonne)->donnees = NULL;

    free(colonne);
    colonne = NULL;
}

void afficher_colonne(Colonne *colonne) {
    for (int i = 0; i < colonne->taille_logique; i++) {
        printf("[%d] %d\n", i, colonne->donnees[i]);
    }
}

int retourner_postion(Colonne *colonne, int indice) {
    if (colonne->donnees[indice]) {
        return colonne->donnees[indice];
    } else {
        return -1;
    }
}

int retourner_egal(Colonne *colonne, int valeur) {
    int total = 0;
    for (int i = 0; i < colonne->taille_logique; i++) {
        if(colonne->donnees[i] == valeur) {
            total++;
        }
    }
    return total;
}

int retourner_superieur(Colonne *colonne, int valeur) {
    int total = 0;
    for (int i = 0; i < colonne->taille_logique; i++) {
        if(colonne->donnees[i] > valeur) {
            total++;
        }
    }
    return total;
}

int retourner_inferieur(Colonne *colonne, int valeur) {
    int total = 0;
    for (int i = 0; i < colonne->taille_logique; i++) {
        if (colonne->donnees[i] < valeur) {
            total++;
        }
    }
    return total;
}
