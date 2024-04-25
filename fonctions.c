#include "colonne.h"
#include "cdataframe.h"
#include <stdio.h>
#include <stdlib.h>

COLONNE *creer_colonne(char * titre) {
    COLONNE * colonne = (COLONNE *) malloc(sizeof(COLONNE));

    colonne -> titre = titre;
    colonne -> donnees = NULL;
    colonne -> taille_physique = 0;
    colonne -> taille_logique = 0;

    return colonne;
}


int inserer_valeur(COLONNE * col, int value) {
    int * donnees_realloc = NULL;

    if (!col) return 0;

    if (col -> taille_logique == col -> taille_physique) {
        col -> taille_physique = TAILLE_REALLOC;
        if (col -> donnees == NULL) {
            donnees_realloc = (int *) calloc(TAILLE_REALLOC, sizeof(int));
        } else {
            donnees_realloc = realloc(col -> donnees, col -> taille_physique);
        }
        if (!donnees_realloc) {
            return 0;
        } else {
            col -> donnees = donnees_realloc;
        }
    }

    col -> donnees[(col -> taille_logique)++] = value;

    return 1;
}

void supprimer_colonne(COLONNE **col) {
    free((* col) -> donnees);
    (* col) -> donnees = NULL;

    free(col);
    col = NULL;
}

void afficher_colonne(COLONNE * col) {
    for (int i = 0; i < col -> taille_logique; i++)
        printf("[%d] %d\n", i, col -> donnees[i]);
}

// ILIES 4.1.5 page 11

int nombre_occurences(COLONNE * col, int valeur){
    int total = 0;
    for(int i=0; i < col -> taille_logique; i++){
        if(col->donnees[i]==valeur){
            total++;
        }
    }
    return total;
}

int retourner_pos(COLONNE * col, int indice){
    if(col->donnees[indice]) {
        return col->donnees[indice];
    }
    else
        return -1;
}

int retourner_superieur(COLONNE * col, int valeur){
    int total = 0;
    for(int i=0; i < col -> taille_logique; i++){
        if(col->donnees[i]>valeur){
            total++;
        }
    }
    return total;
}

int retourner_inferieur(COLONNE * col, int valeur){
    int total = 0;
    for(int i=0; i < col -> taille_logique; i++){
        if(col->donnees[i]<valeur){
            total++;
        }
    }
    return total;
}

CDataframe *creer_cdataframe() {
    CDataframe *df = malloc(sizeof(CDataframe));
    if (!df) return NULL; // Échec de l'allocation

    df->colonnes = NULL;
    df->nb_colonnes = 0;
    df->capacite = 0;

    return df;
}

void afficher_cdataframe(CDataframe *df) {
    if (!df || df->nb_colonnes == 0) {
        printf("\nErreur : le CDataframe vide ou non initialisé.\n");
        return;
    }

    printf("CDataframe contient %d colonnes:\n", df->nb_colonnes);
    for (int j = 0; j < df->nb_colonnes; j++) {
        printf("%s\t", df->colonnes[j]->titre);
    }
    printf("\n");

    // Trouver le nombre de lignes maximal
    int nombre_lignes_max = 0;
    for(int i = 0; i<df->nb_colonnes; i++){
        if((df->colonnes[i]->taille_logique) > nombre_lignes_max){
            nombre_lignes_max = df->colonnes[i]->taille_logique;
        }
    }

    // Afficher les lignes
    for (int i = 0; i < nombre_lignes_max; i++) {
        for (int j = 0; j < df->nb_colonnes; j++) {
            printf("%d\t", df->colonnes[j]->donnees[i]);
        }
        printf("\n");
    }
}

void afficher_lignes_cdataframe(CDataframe *df, int lim){
    if (!df || df->nb_colonnes == 0) {
        printf("\nErreur : le CDataframe est vide ou non initialisé.\n");
        return;
    }
    for (int i = 0; i < lim; i++) {
        for (int j = 0; j < df->nb_colonnes; j++) {
            printf("%d\t", df->colonnes[j]->donnees[i]);
        }
        printf("\n");
    }
}

void afficher_colonnes_cdataframe(CDataframe *df, int lim) {
    if (!df || df->nb_colonnes == 0) {
        printf("\nErreur : le CDataframe est vide ou non initialisé.\n");
        return;
    }
    int nombre_lignes = df->colonnes[0]->taille_logique;
    for (int i = 0; i < nombre_lignes; i++){
        for(int j = 0; j < lim; j++){
            printf("%d\t", df->colonnes[j]->donnees[i]);
        }
        printf("\n");
    }
}


void supprimer_ligne(CDataframe *df, int index_ligne) {
    if (!df || index_ligne < 0 || index_ligne >= df->colonnes[0]->taille_logique) {
        printf("Index de ligne invalide ou DataFrame non initialisé.\n");
        return;
    }

    // Supprimer la ligne pour chaque colonne
    for (int i = 0; i < df->nb_colonnes; i++) {
        COLONNE *colonne = df->colonnes[i];
        // Décaler les données des lignes suivantes vers le haut
        for (int j = index_ligne; j < colonne->taille_logique - 1; j++) {
            colonne->donnees[j] = colonne->donnees[j + 1];
        }
        // Mettre à jour la taille logique de la colonne
        colonne->taille_logique--;
    }
}

int ajouter_colonne(CDataframe *df, COLONNE *col) {
    if (df->nb_colonnes == df->capacite) { // Vérifie si le tableau est plein
        int new_capacite;
        if (df->capacite == 0) {
            new_capacite = TAILLE_REALLOC;
        } else {
            new_capacite = df->capacite * 2; // Double la capacité existante
        }
        COLONNE **new_colonnes = realloc(df->colonnes, new_capacite * sizeof(COLONNE *));
        if (!new_colonnes) {
            return 0;
        }
        df->colonnes = new_colonnes;
        df->capacite = new_capacite;
    }

    df->colonnes[df->nb_colonnes] = col;
    df->nb_colonnes++;
    return 1;
}


void supprimer_colonne_cdataframe(CDataframe *df, int indice_colonne) {
    if (!df || indice_colonne < 0 || indice_colonne >= df->nb_colonnes) {
        printf("Indice invalide ou CDataframe non initialisé.\n");
        return;
    }

    // Libérer la mémoire de la colonne spécifiée
    supprimer_colonne(&(df->colonnes[indice_colonne]));

    // Décaler les pointeurs pour combler le trou
    for (int i = indice_colonne; i < df->nb_colonnes - 1; i++) {
        df->colonnes[i] = df->colonnes[i+1];
    }

    // Réduire le nombre de colonnes
    df->nb_colonnes--;
}

void renommer_colonne_cdataframe(CDataframe *df, int indice_colonne, const char *nouveau_titre) {
    if (!df || indice_colonne < 0 || indice_colonne >= df->nb_colonnes || !nouveau_titre) {
        printf("\nErreur : Paramètre invalide.\n");
        return;
    }

    COLONNE *col = df->colonnes[indice_colonne];

    if (col->titre) {
        free(col->titre);
    }

    // Calcul de la longueur du nouveau titre pour l'allocation
    const char *ptr = nouveau_titre;
    int longueur = 0;
    while (*ptr++) {
        longueur++;
    }

    // Allocation du nouveau titre
    col->titre = malloc(longueur + 1); // +1 pour le caractère de fin '\0'


    // Copie du nouveau titre
    ptr = nouveau_titre;
    char *dest = col->titre;
    while (*ptr) {
        *dest++ = *ptr++;
    }
    *dest = '\0'; // S'assurer que la chaîne est correctement terminée
}

int acceder_valeur_cellule(CDataframe *df, int no_colonne, int no_ligne, int *valeur) {
    // Vérifier si le DataFrame et l'indice sont valides
    if (!df || no_colonne < 0 || no_colonne >= df->nb_colonnes) {
        printf("\nErreur : Index de colonne invalide ou DataFrame non initialisé.\n");
        return 0;  // Échec
    }

    COLONNE *col = df->colonnes[no_colonne];
    if (no_ligne < 0 || no_ligne >= col->taille_logique) {
        printf("\nErreur : Index de ligne invalide.\n");
        return 0;  // Échec
    }

    // Accéder à la valeur
    *valeur = col->donnees[no_ligne];
    return 1;  // Succès
}

void afficher_noms_colonnes(CDataframe *df) {
    if (!df || !df->colonnes) {
        printf("Le CDataFrame n'est pas initialisé ou il n'y a pas de colonnes.\n");
        return;
    }

    printf("Noms des colonnes du CDataframe:\n");
    for (int i = 0; i < df->nb_colonnes; i++) {
        printf("%d: %s\n", i + 1, df->colonnes[i]->titre);
    }
}

void afficher_nombre_lignes(CDataframe *df) {
    if (!df || df->nb_colonnes == 0 || !df->colonnes[0]) {
        printf("Le DataFrame est vide ou mal initialisé.\n");
        return;
    }

    int nombre_lignes = df->colonnes[0]->taille_logique;
    printf("\nNombre de lignes dans le DataFrame : %d\n", nombre_lignes);
}

void afficher_nombre_colonnes(CDataframe *df) {
    if (!df) {
        printf("Le DataFrame n'est pas initialisé.\n");
        return;
    }

    printf("\nNombre de colonnes dans le DataFrame : %d\n", df->nb_colonnes);
}

int compter_cellules_valeur(CDataframe *df, int valeur_recherchee) {
    if (!df || !df->colonnes) {
        printf("Le DataFrame n'est pas initialisé ou il n'y a pas de colonnes.\n");
        return -1;
    }
    int compteur = 0;
    for (int i = 0; i < df->nb_colonnes; i++) {
        COLONNE *colonne = df->colonnes[i];
        for (int j = 0; j < colonne->taille_logique; j++) {
            if (colonne->donnees[j] == valeur_recherchee) {
                compteur++;
            }
        }
    }

    return compteur;
}

int compter_cellules_superieures(CDataframe *df, int valeur_limite) {
    if (!df || !df->colonnes) {
        printf("Le DataFrame n'est pas initialisé ou il n'y a pas de colonnes.\n");
        return -1;
    }

    int compteur = 0;
    for (int i = 0; i < df->nb_colonnes; i++) {
        COLONNE *colonne = df->colonnes[i];
        for (int j = 0; j < colonne->taille_logique; j++) {
            if (colonne->donnees[j] > valeur_limite) {
                compteur++;
            }
        }
    }

    return compteur;
}

int compter_cellules_inferieures(CDataframe *df, int valeur_limite) {
    if (!df || !df->colonnes) {
        printf("Le DataFrame n'est pas initialisé ou il n'y a pas de colonnes.\n");
        return -1;
    }

    int compteur = 0;
    for (int i = 0; i < df->nb_colonnes; i++) {
        COLONNE *colonne = df->colonnes[i];
        for (int j = 0; j < colonne->taille_logique; j++) {
            if (colonne->donnees[j] < valeur_limite) {
                compteur++;
            }
        }
    }

    return compteur;
}

