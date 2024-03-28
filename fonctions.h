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


/**
* Créer une colonne
* @param1 : Titre de la colonne
* @return : Pointeur sur la colonne créée
*/
COLONNE *creer_colonne(char * titre);

/**
* Ajouter une nouvelle valeur à une colonne
* @param1 : Pointeur sur une colonne
* @param2 : La valeur a ajouter
* @return : Retourne 1 si la valeur est ajoutée et 0 sinon
*/
int inserer_valeur(COLONNE * col, int valeur);

/**
* Libère la mémoire allouée
* @param1 : Pointeur sur une colonne
*/
void supprimer_colonne(COLONNE **col);

/**
* Afficher le contenu d'une colonne
* @param: Pointeur sur une colonne
*/
void afficher_colonne(COLONNE * col);

//



#endif //UNTITLED_FONCTIONS_H
