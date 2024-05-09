//
//
//

#include "colonne.h"
#include "cdataframe.h"
#include <stdio.h>
#include <stdlib.h>

int main() {

    printf("Bienvenue sur le CDataFrame de Ilies NASR et Ismael RADOUANE.\n\nEntrez n'importe quelle touche pour creer un CDataframe, entrez \"n\" pour quitter le programme.\n>");
    
    char choix_caractere;
    scanf("%c", &choix_caractere);
    printf("\n");

    if (choix_caractere == 'n') {
        return 0;
    } else {
        Colonne *mycol = creer_colonne(INT, "My column");
        int a = 1, c = 2;
        
        inserer_valeur(mycol, &a);
        inserer_valeur(mycol, NULL);
        inserer_valeur(mycol, NULL);
        inserer_valeur(mycol, &c);
        
        afficher_colonne(mycol);
        
        printf("%d\n", retourner_inferieur(mycol, INT, &c));
    }
}