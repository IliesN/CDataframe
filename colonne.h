//
//
//

#ifndef UNTITLED_COLONNE_H
#define UNTITLED_COLONNE_H


#define TAILLE_REALLOC 256
#define LONGUEUR_MAX (32 + 1)  // Titre de 32 caracteres max


typedef enum {
    UINT, INT, CHAR, FLOAT, DOUBLE, STRING
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
    unsigned int taille_reelle; //taille physique
    EnumType type_colonne;
    TypeCol **donnees; // tableau de pointeurs sur les valeurs stockées
    unsigned long long int *indice; // tableau d'entiers
} Colonne;


/**
* Créer une nouvelle colonne
* @param1 : Type de la colonne
* @param2 : Titre de la colonne
* @return : Pointeur sur la colonne créée
*/
Colonne *creer_colonne(EnumType type, char *titre);

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
char *convertir_valeur(Colonne *colonne, unsigned long long int position);

/**
* @brief: Display the content of a column
* @param: Pointer to the column to display
*/
void afficher_colonne(Colonne *colonne);

int comparer_chaines(char *chaine_1, char *chaine_2);

/**
* Retourne le nombre d'occurences d'une valeur
* @param1: Pointeur sur la colonne
* @param2: Type de la valeur recherchée
* @param3: Valeur recherchée
* @return: Nombre d'occurences d'une valeur, -1 si aucune colonne
*/
int retourner_egal(Colonne *colonne, EnumType type, void* valeur_recherchee);

/**
* @brief: Retourne la valeur dans la position donnée
* @param1: Pointeur sur la colonne
* @param2: TPosition recherchée
*/
void *retourner_position(Colonne *colonne, int position);

/**
* Retourne le nombre de valeurs inférieures à x (donné en paramètre)
* @param1: Pointeur sur la colonne
* @param2: Type de la valeur recherchée
* @param3: x
* @return: Nombre de valeurs inférieures, -1 si aucune colonne
*/
int retourner_inferieur(Colonne *colonne, EnumType type, void* valeur_comparee);

/**
* Retourne le nombre de valeurs supérieures à x (donné en paramètre)
* @param1: Pointeur sur la colonne
* @param2: Type de la valeur recherchée
* @param3: x
* @return: Nombre de valeurs supérieures, -1 si aucune colonne
*/
int retourner_superieur(Colonne *colonne, EnumType type, void* valeur_comparee);

#endif //UNTITLED_COLONNE_H
