#include "fonctions.h"
#include <stdio.h>

int main() {

    COLONNE *mycol = creer_colonne("My column");
    int val = 5;
    if (inserer_valeur(mycol, val))
        printf("Value added successfully to my column\n");
    else
        printf("Error adding value to my column\n");
    inserer_valeur(mycol, 52);
    inserer_valeur(mycol, 44);
    inserer_valeur(mycol, 15);
    afficher_colonne(mycol);


    return 0;
}



