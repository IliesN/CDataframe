//
//
//

#ifndef UNTITLED_COLONNE_H
#define UNTITLED_COLONNE_H


#define TAILLE_REALLOC 256
#define TAILLE_TITRE (16 + 1)  // Titre de 16 caractères max


typedef struct {
    char* titre;
    int taille_physique;
    int taille_logique;
    int* donnees;
} COLONNE;


/**
* Créer une colonne
* @param1 : Titre de la colonne
* @return : Pointeur sur la colonne créée
*/
COLONNE *creer_colonne(char *titre);

/**
* Ajouter une nouvelle valeur à une colonne
* @param1 : Pointeur sur une colonne
* @param2 : La valeur à ajouter
* @return : Retourne 1 si la valeur est ajoutée et 0 sinon
*/
int inserer_valeur(COLONNE *colonne, int valeur);

/**
* Libère la mémoire allouée
* @param1 : Pointeur sur une colonne
*/
void supprimer_colonne(COLONNE **colonne);

/**
* Afficher le contenu d'une colonne
* @param: Pointeur sur une colonne
*/
void afficher_colonne(COLONNE *colonne);

/**
* Compte le nombre d'occurrences d'une valeur
* @param1 : Pointeur sur une colonne
* @param2 : La valeur à chercher
* @return : Retourne le nombre d'occurrences de la valeur
*/
int nombre_occurences(COLONNE *colonne, int valeur);

/**
* Retourne la valeur présente à un indice donné
* @param1 : Pointeur sur une colonne
* @param2 : L'indice
* @return : Retourne la valeur présente à l'indice donné en paramètre
*/
int retourner_postion(COLONNE *colonne, int indice);

/**
* Compte le nombre de valeurs supérieures à une valeur donnée
* @param1 : Pointeur sur une colonne
* @param2 : La valeur à comparer
* @return : Retourne le nombre de valeurs supérieures à la valeur donnée en paramètre
*/
int retourner_superieur(COLONNE *colonne, int valeur);

/**
* Compte le nombre de valeurs inférieures à une valeur donnée
* @param1 : Pointeur sur une colonne
* @param2 : La valeur à comparer
* @return : Retourne le nombre de valeurs inférieures à la valeur donnée en paramètre
*/
int retourner_inferieur(COLONNE *colonne, int valeur);

#endif //UNTITLED_COLONNE_H
