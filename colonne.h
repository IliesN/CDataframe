//
//
//

#ifndef UNTITLED_COLONNE_H
#define UNTITLED_COLONNE_H


#define TAILLE_REALLOC 256
#define TAILLE_TITRE (32 + 1)  // Titre de 32 caracteres max


typedef enum {
    NULLVAL = 1 , UINT, INT, CHAR, FLOAT, DOUBLE, STRING, STRUCTURE
} EnumType;

typedef union {
    unsigned int        uint_value;
    signed int          int_value;
    char                char_value;
    float               float_value;
    double              double_value;
    char*               string_value;
    void*               struct_value;
} TypeCol;

typedef struct {
    char *titre;
    unsigned int taille_logique; //taille logique
    unsigned int taille_physique; //taille physique
    EnumType type_colonne;
    TypeCol **donnees; // tableau de pointeurs sur les valeurs stockées
    unsigned long long int *index; // tableau d'entiers
} Colonne;


/**
* Créer une nouvelle colonne
* @param1 : Type de la colonne
* @param2 : Titre de la colonne
* @return : Pointeur sur la colonne créée
*/
Colonne *creer_colonne(EnumType type, char *title);

/**
* Insère une nouvelle valeur dans une colonne
* @param1: Pointer sur la colonne
* @param2: Pointeur sur la valeur à insérer
* @return: 1 si la valeur est correctement insérée, 0 sinon
*/
int inserer_valeur(Colonne *colonne, void *valeur);

/**
* @brief: Libère l'espace alloué à une colonne
* @param1: Pointeur sur la colonne
*/
void supprimer_colonne(Colonne **colonne);

/**
* @brief: Convertit une valeur en une chaîne de caractères
* @param1: Pointeur sur la colonne
* @param2: Position de la valeur dans le tableau de données
* @param3: La chaîne de caractères dans laquelle la valeur sera écrite
* @param4: Taille maximale de la chaîne de caractères
*/
void convertir_valeur(Colonne *colonne, unsigned long long int i, char *str, int size);

/**
* @brief: Display the content of a column
* @param: Pointer to the column to display
*/
void afficher_colonne(Colonne *colonne);

#endif //UNTITLED_COLONNE_H
