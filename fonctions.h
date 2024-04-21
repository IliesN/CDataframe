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


typedef struct {
    COLONNE **colonnes;
    int nb_colonnes;
    int capacite;
} CDataframe;


/**
* Créer une colonne
* @param1 : Titre de la colonne
* @return : Pointeur sur la colonne créée
*/
COLONNE *creer_colonne(char * titre);

/**
* Ajouter une nouvelle valeur à une colonne
* @param1 : Pointeur sur une colonne
* @param2 : La valeur à ajouter
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
/**
* Compte le nombre d'occurrences d'une valeur
* @param1 : Pointeur sur une colonne
* @param2 : La valeur à chercher
* @return : Retourne le nombre d'occurrences de la valeur
*/
int nombre_occurences(COLONNE * col, int valeur);

/**
* Retourne la valeur présente à un indice donné
* @param1 : Pointeur sur une colonne
* @param2 : L'indice
* @return : Retourne la valeur présente à l'indice donné en paramètre
*/
int retourner_pos(COLONNE * col, int indice);

/**
* Compte le nombre de valeurs supérieures à une valeur donnée
* @param1 : Pointeur sur une colonne
* @param2 : La valeur à comparer
* @return : Retourne le nombre de valeurs supérieures à la valeur donnée en paramètre
*/
int retourner_superieur(COLONNE * col, int valeur);

/**
* Compte le nombre de valeurs inférieures à une valeur donnée
* @param1 : Pointeur sur une colonne
* @param2 : La valeur à comparer
* @return : Retourne le nombre de valeurs inférieures à la valeur donnée en paramètre
*/
int retourner_inferieur(COLONNE * col, int valeur);

CDataframe *creer_cdataframe();

int ajouter_colonne(CDataframe *df, COLONNE *col);

void afficher_cdataframe(CDataframe *df);

void afficher_lignes_cdataframe(CDataframe *df, int lim);

void afficher_colonnes_cdataframe(CDataframe *df, int lim);

void supprimer_colonne_cdataframe(CDataframe *df, int indice_colonne);

void renommer_colonne_cdataframe(CDataframe *df, int indice_colonne, const char *nouveau_titre);

void afficher_noms_colonnes(CDataframe *df);

int acceder_valeur_cellule(CDataframe *df, int no_colonne, int no_ligne, int *valeur);

void afficher_nombre_lignes(CDataframe *df);

void afficher_nombre_colonnes(CDataframe *df);

int compter_cellules_valeur(CDataframe *df, int valeur_recherchee);

int compter_cellules_superieures(CDataframe *df, int valeur_limite);

int compter_cellules_inferieures(CDataframe *df, int valeur_limite);

#endif //UNTITLED_FONCTIONS_H