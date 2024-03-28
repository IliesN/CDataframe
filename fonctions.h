#ifndef UNTITLED_FONCTIONS_H
#define UNTITLED_FONCTIONS_H

#include <stdlib.h>

#define TAILLE_REALLOC 256

typedef struct {
    char * titre;
    int taille_physique;
    int taille_logique;
    int * donnees;
} COLONNE;

COLONNE *creer_colonne(char * titre);


#endif //UNTITLED_FONCTIONS_H
