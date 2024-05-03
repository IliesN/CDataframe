//
//
//

#ifndef UNTITLED_COLONNE_H
#define UNTITLED_COLONNE_H


#define TAILLE_REALLOC 256
#define TAILLE_TITRE (32 + 1)  // Titre de 32 caracteres max


enum enum_type
{
    NULLVAL = 1 , UINT, INT, CHAR, FLOAT, DOUBLE, STRING, STRUCTURE
};

typedef enum enum_type ENUM_TYPE;

union type_colonne{
    unsigned int        uint_value;
    signed int          int_value;
    char                char_value;
    float               float_value;
    double              double_value;
    char*               string_value;
    void*               struct_value;
};
typedef union type_colonne TYPE_COL ;

struct colonne {
    char *titre;
    unsigned int taille_logique; //taille logique
    unsigned int taille_physique; //taille physique
    ENUM_TYPE type_colonne;
    TYPE_COL **donnees; // tableau de pointeurs sur les valeurs stockées
    unsigned long long int *index; // tableau d'entiers
};
typedef struct colonne COLONNE;

/**
* Créer une nouvelle colonne
* @param1 : Type de la colonne
* @param2 : Titre de la colonne
* @return : Pointeur sur la colonne créée
*/
COLONNE *creer_colonne(ENUM_TYPE type, char *title);

/**
* Insère une nouvelle valeur dans une colonne
* @param1: Pointer sur la colonne
* @param2: Pointeur sur la valeur à insérer
* @return: 1 si la valeur est correctement insérée, 0 sinon
*/
int inserer_valeur(COLONNE *colonne, void *valeur);

#endif //UNTITLED_COLONNE_H
