//
//
//

#ifndef UNTITLED_COLONNE_H
#define UNTITLED_COLONNE_H


#define TAILLE_REALLOC 256
#define TAILLE_TITRE (32 + 1)  // Titre de 32 caracteres max


typedef struct {
    char* titre;
    int taille_physique;
    int taille_logique;
    int* donnees;
} Colonne;


/**
* Creer une colonne
* @param1 : Titre de la colonne
* @return : Pointeur sur la colonne creee
*/
Colonne *creer_colonne(char *titre);

/**
* Ajouter une nouvelle valeur a une colonne
* @param1 : Pointeur sur une colonne
* @param2 : La valeur a ajouter
* @return : Retourne 1 si la valeur est ajoutee et 0 sinon
*/
int inserer_valeur(Colonne *colonne, int valeur);

/**
* Libere la memoire allouee
* @param1 : Pointeur sur une colonne
*/
void supprimer_colonne(Colonne **colonne);

/**
* Afficher le contenu d'une colonne
* @param: Pointeur sur une colonne
*/
void afficher_colonne(Colonne *colonne);

/**
* Retourne la valeur presente a un indice donne
* @param1 : Pointeur sur une colonne
* @param2 : L'indice
* @return : Retourne la valeur presente a l'indice donne en parametre
*/
int retourner_postion(Colonne *colonne, int indice);

/**
* Compte le nombre de valeurs égales a une valeur donnee
* @param1 : Pointeur sur une colonne
* @param2 : La valeur a comparer
* @return : Retourne le nombre de valeurs égales a la valeur donnee en parametre
*/
int retourner_egal(Colonne *colonne, int valeur);

/**
* Compte le nombre de valeurs superieures a une valeur donnee
* @param1 : Pointeur sur une colonne
* @param2 : La valeur a comparer
* @return : Retourne le nombre de valeurs superieures a la valeur donnee en parametre
*/
int retourner_superieur(Colonne *colonne, int valeur);

/**
* Compte le nombre de valeurs inferieures a une valeur donnee
* @param1 : Pointeur sur une colonne
* @param2 : La valeur a comparer
* @return : Retourne le nombre de valeurs inferieures a la valeur donnee en parametre
*/
int retourner_inferieur(Colonne *colonne, int valeur);

#endif //UNTITLED_COLONNE_H
