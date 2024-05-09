//
//
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "colonne.h"

Colonne *creer_colonne(EnumType type, char *titre) {
    Colonne *colonne = (Colonne *) malloc(sizeof(Colonne));

    colonne->titre = (char *) malloc(strlen(titre) + 1);

    // Copie le titre dans la memoire allouee caractere par caractere
    int i;
    for (i = 0; titre[i] != '\0'; i++) {
        colonne->titre[i] = titre[i];
    }
    colonne->titre[i] = '\0'; // Ajout du caractere de fin '\0'

    colonne->type_colonne = type;
    colonne->taille_logique = 0;
    colonne->taille_physique = 0;
    colonne->donnees = NULL;
    colonne->index = NULL;

    return colonne;
}

int inserer_valeur(Colonne *colonne, void *valeur) {
    void *donnees_realloc = NULL;
    unsigned int taille_octets;

    if (!colonne) {
        return 0;
    }

    if (colonne->taille_logique == colonne->taille_physique) {
        colonne->taille_physique += TAILLE_REALLOC;
        switch (colonne->type_colonne) {
            case INT:
                taille_octets = colonne->taille_physique * sizeof(int);
                break;
            case CHAR:
                taille_octets = colonne->taille_physique * sizeof(char);
                break;
            case FLOAT:
                taille_octets = colonne->taille_physique * sizeof(float);
                break;
            case UINT:
                taille_octets = colonne->taille_physique * sizeof(unsigned int);
                break;
            case DOUBLE:
                taille_octets = colonne->taille_physique * sizeof(double);
                break;
            case STRING:
                taille_octets = colonne->taille_physique * sizeof(char *);
                break;
            default:
                return 0; 
        }

        donnees_realloc = realloc(colonne->donnees, taille_octets);
        if (!donnees_realloc) {
            return 0;
        }
        colonne->donnees = donnees_realloc;
    }

    switch (colonne->type_colonne) {
        case INT:
            ((int *)colonne->donnees)[colonne->taille_logique] = *(int *)valeur;
            break;
        case CHAR:
            ((char *)colonne->donnees)[colonne->taille_logique] = *(char *)valeur;
            break;
        case FLOAT:
            ((float *)colonne->donnees)[colonne->taille_logique] = *(float *)valeur;
            break;
        case UINT:
            ((unsigned int *)colonne->donnees)[colonne->taille_logique] = *(unsigned int *)valeur;
            break;
        case DOUBLE:
            ((double *)colonne->donnees)[colonne->taille_logique] = *(double *)valeur;
            break;
        case STRING:
            ((char **)colonne->donnees)[colonne->taille_logique] = (char *)valeur;
            break;
        default:
            return -1; 
    }
    colonne->taille_logique++;
    return 1;
}

void supprimer_colonne(Colonne **colonne) {

    free((*colonne)->donnees);
    free((*colonne)->index);
    (*colonne)->donnees = NULL;
    (*colonne)->index = NULL;

    free(colonne);
    colonne = NULL;

}

void convertir_valeur(Colonne *colonne, unsigned long long int i, char *str, int size){

    switch (colonne->type_colonne) {
        case INT:
            snprintf(str, size, "%d", ((int*)colonne->donnees)[i]);
            break;
        case CHAR:
            snprintf(str, size, "%c", ((char*)colonne->donnees)[i]);
            break;
        case FLOAT:
            snprintf(str, size, "%f", ((float*)colonne->donnees)[i]);
            break;
        case UINT:
            snprintf(str, size, "%u", ((unsigned int*)colonne->donnees)[i]);
            break;
        case DOUBLE:
            snprintf(str, size, "%lf", ((double*)colonne->donnees)[i]);
            break;
        case STRING:
            snprintf(str, size, "%s", ((char**)colonne->donnees)[i]);
            break;
    }

    printf(" %s", str);
}

void afficher_colonne(Colonne *colonne) {
    for (unsigned int i = 0; i < colonne->taille_logique; i++) {
        char str[TAILLE_TITRE];
        printf("%d ", colonne->taille_logique);
        printf("[%d]", i);
        convertir_valeur(colonne, i, str, TAILLE_TITRE);
        printf("\n");
    }
}

int retourner_egal(Colonne *colonne, EnumType type, void* valeur){
    int compteur = 0;
    if (!colonne) {
        return -1;
    }
    if(colonne->type_colonne == type){
        for(unsigned int i = 0; i < colonne->taille_logique; i++){
            if((colonne->donnees[i]) == valeur){
                compteur++;
            }
        }
    }
    return compteur;
}

void retourner_postion(Colonne *colonne, unsigned int pos) {
    if (colonne->donnees[pos]) {
        char str[TAILLE_TITRE];
        convertir_valeur(colonne, pos, str, TAILLE_TITRE);
    }
}

int retourner_inferieur(Colonne *colonne, EnumType type, void* valeur){
    int compteur = 0;
    if (!colonne) {
        return -1;
    }
    if(colonne->type_colonne == type){
        for(unsigned int i = 0; i < colonne->taille_logique; i++){
            if((colonne->donnees[i]) < valeur){
                compteur++;
            }
        }
    }
    return compteur;
}

int retourner_superieur(Colonne *colonne, EnumType type, void* valeur){
    int compteur = 0;
    if (!colonne) {
        return -1;
    }
    if(colonne->type_colonne == type){
        for(unsigned int i = 0; i < colonne->taille_logique; i++){
            if((colonne->donnees[i]) > valeur){
                compteur++;
            }
        }
    }
    return compteur;
}


/*
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
*/