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
    printf("%d\n", nombre_occurences(mycol, 4));
    printf("%d\n", retourner_pos(mycol,89));
    printf("%d\n", retourner_inferieur(mycol, 99999));
    printf("%d\n", retourner_superieur(mycol, 0));

    return 0;
}



