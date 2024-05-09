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
    colonne->indice = NULL;

    return colonne;
}

int inserer_valeur(Colonne *colonne, void *valeur) {
    void *donnees_realloc = NULL;
    int taille_octets;
    
    if (!colonne) {
        return 0;
    }
    
    if (colonne->taille_logique == colonne->taille_physique) {
        colonne->taille_physique += TAILLE_REALLOC;
        
        taille_octets = colonne->taille_physique * sizeof(void *);
        donnees_realloc = realloc(colonne->donnees, colonne->taille_physique * sizeof(void *));

        if (!donnees_realloc) {
            return -1;
        } else {
            colonne->donnees = donnees_realloc;
        }
    }

    if (valeur == NULL) {
        colonne->donnees[(colonne->taille_logique)++] = NULL;
    } else {
        switch (colonne->type_colonne) {
            case INT:
                colonne->donnees[colonne->taille_logique] = malloc(sizeof(int));
                *((int *)colonne->donnees[(colonne->taille_logique)++]) = *((int *)valeur);
                break;
            case CHAR:
                colonne->donnees[colonne->taille_logique] = malloc(sizeof(char));
                *((char *)colonne->donnees[(colonne->taille_logique)++]) = *((char *)valeur);
                break;
            case FLOAT:
                colonne->donnees[colonne->taille_logique] = malloc(sizeof(float));
                *((float *)colonne->donnees[(colonne->taille_logique)++]) = *((float *)valeur);
                break;
            case UINT:
                colonne->donnees[colonne->taille_logique] = malloc(sizeof(unsigned int));
                *((unsigned int *)colonne->donnees[(colonne->taille_logique)++]) = *((unsigned int *)valeur);
                break;
            case DOUBLE:
                colonne->donnees[colonne->taille_logique] = malloc(sizeof(double));
                *((double *)colonne->donnees[(colonne->taille_logique)++]) = *((double *)valeur);
                break;
            case STRING:
                colonne->donnees[colonne->taille_logique] = malloc(sizeof(char));
                *((char **)colonne->donnees[(colonne->taille_logique)++]) = *((char **)valeur);
                break;
        }
    }

    return 0;
}

void supprimer_colonne(Colonne **colonne) {
    for (int i = 0; i < (*colonne)->taille_logique; i++) {
        if ((*colonne)->donnees[i] != NULL) {
            free((*colonne)->donnees[i]);
            (*colonne)->donnees[i] = NULL;
        }
    }
    free((*colonne)->donnees);
    free((*colonne)->indice);
    (*colonne)->donnees = NULL;
    (*colonne)->indice = NULL;

    free(*colonne);
    *colonne = NULL;
}

void convertir_valeur(Colonne *colonne, unsigned long long int position, char *chaine, int taille){
    if (colonne->donnees[position] == NULL) {
        printf("NULL");
    } else {
        switch (colonne->type_colonne) {
            case INT:
                snprintf(chaine, taille, "%d", *((int*)colonne->donnees[position]));
                break;
            case CHAR:
                snprintf(chaine, taille, "%c", *((char*)colonne->donnees[position]));
                break;
            case FLOAT:
                snprintf(chaine, taille, "%f", *((float*)colonne->donnees[position]));
                break;
            case UINT:
                snprintf(chaine, taille, "%u", *((unsigned int*)colonne->donnees[position]));
                break;
            case DOUBLE:
                snprintf(chaine, taille, "%lf", *((double*)colonne->donnees[position]));
                break;
            case STRING:
                snprintf(chaine, taille, "%s", *((char**)colonne->donnees[position]));
                break;
        }
        printf("%s", chaine);
    }
    
}

void afficher_colonne(Colonne *colonne) {
    for (int i = 0; i < colonne->taille_logique; i++) {
        char chaine[LONGUEUR_MAX];
        printf("[%d] ", i);
        convertir_valeur(colonne, i, chaine, LONGUEUR_MAX);
        printf("\n");
    }
}

int retourner_egal(Colonne *colonne, EnumType type, void* valeur){
    int compteur = 0;

    if(colonne->type_colonne == type){
        for(int i = 0; i < colonne->taille_logique; i++){
            if (colonne->donnees[i] != NULL)
            switch(type) {
                case INT:
                    if(*(int*)colonne->donnees[i] == *(int*)valeur) {
                        compteur++;
                    }
                    break;
                case CHAR:
                    if(*(char*)colonne->donnees[i] == *(char*)valeur) {
                        compteur++;
                    }
                    break;
                case FLOAT:
                    if(*(float*)colonne->donnees[i] == *(float*)valeur) {
                        compteur++;
                    }
                    break;
                case UINT:
                    if(*(unsigned int*)colonne->donnees[i] == *(unsigned int*)valeur) {
                        compteur++;
                    }
                    break;
                case DOUBLE:
                    if(*(double*)colonne->donnees[i] == *(double*)valeur) {
                        compteur++;
                    }
                    break;
                case STRING:
                    if(strcmp(*(char**)colonne->donnees[i], *(char**)valeur) == 0) {
                        compteur++;
                    }
                    break;
            }
        }
    }

    return compteur;
}

void *retourner_position(Colonne *colonne, int position) {
    if (colonne->donnees[position]) {
        return colonne->donnees[position];
    } else {
        return NULL;
    }
}

int retourner_inferieur(Colonne *colonne, EnumType type, void* valeur){
    int compteur = 0;

    if(colonne->type_colonne == type){
        for(int i = 0; i < colonne->taille_logique; i++){
            if (colonne->donnees[i] != NULL)
            switch(type) {
                case INT:
                    if(*(int*)colonne->donnees[i] < *(int*)valeur) {
                        compteur++;
                    }
                    break;
                case CHAR:
                    if(*(char*)colonne->donnees[i] < *(char*)valeur) {
                        compteur++;
                    }
                    break;
                case FLOAT:
                    if(*(float*)colonne->donnees[i] < *(float*)valeur) {
                        compteur++;
                    }
                    break;
                case UINT:
                    if(*(unsigned int*)colonne->donnees[i] < *(unsigned int*)valeur) {
                        compteur++;
                    }
                    break;
                case DOUBLE:
                    if(*(double*)colonne->donnees[i] < *(double*)valeur) {
                        compteur++;
                    }
                    break;
                case STRING:
                    if(strcmp(*(char**)colonne->donnees[i], *(char**)valeur) == 0) {
                        compteur++;
                    }
                    break;
            }
        }
    }

    return compteur;
}

int retourner_superieur(Colonne *colonne, EnumType type, void* valeur){
    int compteur = 0;

    if(colonne->type_colonne == type){
        for(int i = 0; i < colonne->taille_logique; i++){
            if (colonne->donnees[i] != NULL)
            switch(type) {
                case INT:
                    if(*(int*)colonne->donnees[i] > *(int*)valeur) {
                        compteur++;
                    }
                    break;
                case CHAR:
                    if(*(char*)colonne->donnees[i] > *(char*)valeur) {
                        compteur++;
                    }
                    break;
                case FLOAT:
                    if(*(float*)colonne->donnees[i] > *(float*)valeur) {
                        compteur++;
                    }
                    break;
                case UINT:
                    if(*(unsigned int*)colonne->donnees[i] > *(unsigned int*)valeur) {
                        compteur++;
                    }
                    break;
                case DOUBLE:
                    if(*(double*)colonne->donnees[i] > *(double*)valeur) {
                        compteur++;
                    }
                    break;
                case STRING:
                    if(strcmp(*(char**)colonne->donnees[i], *(char**)valeur) == 0) {
                        compteur++;
                    }
                    break;
            }
        }
    }

    return compteur;
}
