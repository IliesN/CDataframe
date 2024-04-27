#include "colonne.h"
#include "cdataframe.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

COLONNE *creer_colonne(char * titre) {
    COLONNE * colonne = (COLONNE *) malloc(sizeof(COLONNE));

    colonne -> titre = (char *) malloc(strlen(titre) + 1);
    strcpy(colonne -> titre, titre); // Copie le titre dans la mémoire allouée

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
    CDataframe *cdataframe = malloc(sizeof(CDataframe));
    if (!cdataframe) return NULL; // Échec de l'allocation

    cdataframe->colonnes = NULL;
    cdataframe->nombre_colonnes = 0;
    cdataframe->capacite = 0;

    return cdataframe;
}





void ecrire_affichage_fichier(char* nom_fichier, CDataframe* cdataframe) {
    // Ouvre un fichier en mode écriture avec le nom spécifié dans la variable et stocke le pointeur de fichier dans la variable "fichier"
    FILE *fichier = fopen(nom_fichier, "w");

    // Redirige la sortie standard (stdout) vers le fichier spécifié par "nom_fichier". À partir de maintenant, toutes les sorties de printf seront écrites dans le fichier.
    freopen(nom_fichier, "w", stdout);

    // Appelle la fonction "afficher_cdataframe" pour afficher le contenu du CDataframe. Comme la sortie standard a été redirigée, le résultat sera écrit dans le fichier.
    afficher_cdataframe(cdataframe);

    // Restaure la sortie standard (stdout) en la redirigeant vers la console ("CON"). Les sorties de printf reviendront à leur comportement normal (affichage à l'écran).
    freopen("CON", "w", stdout);

    // Ferme le fichier ouvert précédemment.
    fclose(fichier);

    // Appelle à nouveau la fonction "afficher_cdataframe" pour afficher le contenu du CDataframe à l'écran, maintenant que la sortie standard a été restaurée.
    afficher_cdataframe(cdataframe);
}


void remplissage_en_dur(CDataframe *cdataframe) {
    COLONNE *colonne1 = creer_colonne("Titre1_test");
    inserer_valeur(colonne1, 1);
    inserer_valeur(colonne1, 2);
    inserer_valeur(colonne1, 3);
    ajouter_colonne(cdataframe, colonne1);

    COLONNE *colonne2 = creer_colonne("Titre2");
    inserer_valeur(colonne2, 1);
    inserer_valeur(colonne2, 2);
    inserer_valeur(colonne2, 1);
    inserer_valeur(colonne2, 2);
    inserer_valeur(colonne2, 1);
    inserer_valeur(colonne2, 2);
    inserer_valeur(colonne2, 1);
    inserer_valeur(colonne2, 2);
    inserer_valeur(colonne2, 1);
    inserer_valeur(colonne2, 2);
    inserer_valeur(colonne2, 2);
    ajouter_colonne(cdataframe, colonne2);

    COLONNE *colonne3 = creer_colonne("Titre3");
    inserer_valeur(colonne3, 2);
    inserer_valeur(colonne3, 3);
    inserer_valeur(colonne3, 43);
    inserer_valeur(colonne3, 142);
    ajouter_colonne(cdataframe, colonne3);
    /*
    COLONNE *colonne4 = creer_colonne("Titre4");
    inserer_valeur(colonne4, 10);
    inserer_valeur(colonne4, 20);
    inserer_valeur(colonne4, 30);
    inserer_valeur(colonne4, 40);
    ajouter_colonne(cdataframe, colonne4);

    COLONNE *colonne5 = creer_colonne("Titre5");
    inserer_valeur(colonne5, 5);
    inserer_valeur(colonne5, 10);
    inserer_valeur(colonne5, 15);
    inserer_valeur(colonne5, 20);
    inserer_valeur(colonne5, 25);
    ajouter_colonne(cdataframe, colonne5);

    COLONNE *colonne6 = creer_colonne("Titre6");
    inserer_valeur(colonne6, 1);
    inserer_valeur(colonne6, 2);
    inserer_valeur(colonne6, 3);
    inserer_valeur(colonne6, 4);
    inserer_valeur(colonne6, 5);
    inserer_valeur(colonne6, 6);
    inserer_valeur(colonne6, 7);
    inserer_valeur(colonne6, 8);
    inserer_valeur(colonne6, 9);
    inserer_valeur(colonne6, 10);
    ajouter_colonne(cdataframe, colonne6);

    COLONNE *colonne7 = creer_colonne("Titre7");
    inserer_valeur(colonne7, 50);
    inserer_valeur(colonne7, 100);
    inserer_valeur(colonne7, 150);
    inserer_valeur(colonne7, 200);
    inserer_valeur(colonne7, 250);
    inserer_valeur(colonne7, 300);
    ajouter_colonne(cdataframe, colonne7);

    COLONNE *colonne8 = creer_colonne("Titre8");
    inserer_valeur(colonne8, -1);
    inserer_valeur(colonne8, -2);
    inserer_valeur(colonne8, -3);
    inserer_valeur(colonne8, -4);
    inserer_valeur(colonne8, -5);
    ajouter_colonne(cdataframe, colonne8);

    COLONNE *colonne9 = creer_colonne("Titre9");
    inserer_valeur(colonne9, 1000);
    inserer_valeur(colonne9, 2000);
    inserer_valeur(colonne9, 3000);
    inserer_valeur(colonne9, 4000);
    inserer_valeur(colonne9, 5000);
    ajouter_colonne(cdataframe, colonne9);

    COLONNE *colonne10 = creer_colonne("Titre10");
    inserer_valeur(colonne10, 1);
    inserer_valeur(colonne10, 1);
    ajouter_colonne(cdataframe, colonne10);

    COLONNE *colonne11 = creer_colonne("dfsgsdfgsdfgsdfgsdf");
    inserer_valeur(colonne11, 1);
    inserer_valeur(colonne11, 1);
    ajouter_colonne(cdataframe, colonne11);

    COLONNE *colonne12 = creer_colonne("dfsgsdfgsdsdfgsdf");
    inserer_valeur(colonne12, 1);
    inserer_valeur(colonne12, 1);
    ajouter_colonne(cdataframe, colonne12);*/
}

void fermer_tableau(int nombre_colonnes, int longueur_chaine, int longueur_nombre_ligne_max) {
    int i;
    
    printf("|_");
    for (i = 0; i < longueur_nombre_ligne_max; i++)
        printf("_");
    printf("_");
    for (i = 0; i < nombre_colonnes; i++) {
        printf("|_");
        for (int j = 0; j < longueur_chaine; j++)
            printf("_");
        printf("_");
    }
    printf("|\n");
}

void afficher_indice_espaces(int entier, int taille_chaine_maximale) {
    int nombre_espaces = taille_chaine_maximale - longueur_nombre(entier);
    for (int i = 0; i < nombre_espaces; i++)
        printf(" ");
    printf("%d", entier);
}

void afficher_valeur_espaces(int entier, int taille_chaine_maximale) {
    int nombre_espaces = taille_chaine_maximale - longueur_nombre(entier);
    printf("%d", entier);
    for (int i = 0; i < nombre_espaces; i++)
        printf(" ");
}

char* afficher_titre_espaces(char* chaine, int taille_chaine_maximale, int longueur_indice_maximale, int longueur_ajout_titre, int indice_colonne) {
    int taille_chaine = strlen(chaine);
    int taille_restante = taille_chaine_maximale - taille_chaine - longueur_ajout_titre;

    printf("| %s", chaine);
    for (int i = 0; i < taille_restante + longueur_indice_maximale - longueur_nombre(indice_colonne); i++) {
        printf(" ");
    }
    printf("   [%d] ", indice_colonne);
}

int longueur_nombre(int nombre) {
    if (nombre == 0) return 1;

    int taille_nombre = 0;
    if (nombre < 0) taille_nombre += 1;

    while (nombre != 0) {
        nombre /= 10;
        taille_nombre++;
    }

    return taille_nombre;
}

void afficher_cdataframe(CDataframe *cdataframe) {
    if (!cdataframe || cdataframe->nombre_colonnes == 0) {
        cdataframe_vide();
        return;
    }

    int i;

    int longueur_caractere_tableau = 0;
    int nombre_lignes_max = retourner_nombre_lignes(cdataframe);
    int longueur_nombre_ligne_max = longueur_nombre(nombre_lignes_max);
    int longueur_titre_maximale = 0;

    for (i = 0; i < cdataframe->nombre_colonnes; i++) {
        int longueur_titre = strlen(cdataframe->colonnes[i]->titre);
        if (longueur_titre > longueur_titre_maximale)
            longueur_titre_maximale = longueur_titre;
    }
    int ajout_titre = 3 + 1 + longueur_nombre_ligne_max + 1; // + "  [taille indice]"

    longueur_titre_maximale += ajout_titre;

    for (i = 0; i < cdataframe->nombre_colonnes; i++)
        longueur_caractere_tableau += 3 + longueur_titre_maximale;
    longueur_caractere_tableau -= 1;
    
    for (i = 0; i < 2 + longueur_nombre_ligne_max + 2; i++)
        printf(" ");
    for (i = 0; i < longueur_caractere_tableau; i++)
        printf("_");
    printf("\n");
    
    for (i = 0; i < 3 + longueur_nombre_ligne_max; i++)
        printf(" ");
    for (i = 0; i < cdataframe->nombre_colonnes; i++)
        afficher_titre_espaces(cdataframe->colonnes[i]->titre, longueur_titre_maximale, longueur_nombre_ligne_max, ajout_titre, i);
    printf("|\n _");
    for (i = 0; i < longueur_nombre_ligne_max; i++)
        printf("_");
    printf("_");
    for (i = 0; i < cdataframe->nombre_colonnes; i++) {
        printf("|_");
        for (int j = 0; j < longueur_titre_maximale; j++)
            printf("_");
        printf("_");
    }
    printf("|\n");

    for (i = 0; i < nombre_lignes_max; i++) {
        printf("| ");
        afficher_indice_espaces(i, longueur_nombre_ligne_max);
        printf(" ");
        for (int j = 0; j < cdataframe->nombre_colonnes; j++) {
            printf("| ");
            afficher_valeur_espaces(cdataframe->colonnes[j]->donnees[i], longueur_titre_maximale);
            printf(" ");
        }
        printf("|\n");
        fermer_tableau(cdataframe->nombre_colonnes, longueur_titre_maximale, longueur_nombre_ligne_max);
    }
    printf("\n\n");
}




void afficher_lignes_cdataframe(CDataframe *cdataframe, int lim){
    if (!cdataframe || cdataframe->nombre_colonnes == 0) {
        printf("Erreur : le CDataframe est vide ou non initialisé.\n");
        return;
    }
    for (int i = 0; i < lim; i++) {
        for (int j = 0; j < cdataframe->nombre_colonnes; j++) {
            printf("%d\t", cdataframe->colonnes[j]->donnees[i]);
        }
        printf("\n");
    }
}

void afficher_colonnes_cdataframe(CDataframe *cdataframe, int lim) {
    if (!cdataframe || cdataframe->nombre_colonnes == 0) {
        printf("Erreur : le CDataframe est vide ou non initialisé.\n");
        return;
    }
    int nombre_lignes = cdataframe->colonnes[0]->taille_logique;
    for (int i = 0; i < nombre_lignes; i++){
        for(int j = 0; j < lim; j++){
            printf("%d\t", cdataframe->colonnes[j]->donnees[i]);
        }
        printf("\n");
    }
}


void supprimer_ligne(CDataframe *cdataframe, int index_ligne) {
    if (!cdataframe || index_ligne < 0 || index_ligne >= cdataframe->colonnes[0]->taille_logique) {
        printf("Index de ligne invalide ou DataFrame non initialisé.\n");
        return;
    }

    // Supprimer la ligne pour chaque colonne
    for (int i = 0; i < cdataframe->nombre_colonnes; i++) {
        COLONNE *colonne = cdataframe->colonnes[i];
        // Décaler les données des lignes suivantes vers le haut
        for (int j = index_ligne; j < colonne->taille_logique - 1; j++) {
            colonne->donnees[j] = colonne->donnees[j + 1];
        }
        // Mettre à jour la taille logique de la colonne
        colonne->taille_logique--;
    }
}

int ajouter_colonne(CDataframe *cdataframe, COLONNE *col) {
    if (cdataframe->nombre_colonnes == cdataframe->capacite) { // Vérifie si le tableau est plein
        int new_capacite;
        if (cdataframe->capacite == 0) {
            new_capacite = TAILLE_REALLOC;
        } else {
            new_capacite = cdataframe->capacite * 2; // Double la capacité existante
        }
        COLONNE **new_colonnes = realloc(cdataframe->colonnes, new_capacite * sizeof(COLONNE *));
        if (!new_colonnes) {
            return 0;
        }
        cdataframe->colonnes = new_colonnes;
        cdataframe->capacite = new_capacite;
    }

    cdataframe->colonnes[cdataframe->nombre_colonnes] = col;
    cdataframe->nombre_colonnes++;
    return 1;
}


void supprimer_colonne_cdataframe(CDataframe *cdataframe, int indice_colonne) {
    if (!cdataframe || indice_colonne < 0 || indice_colonne >= cdataframe->nombre_colonnes) {
        printf("Indice invalide ou CDataframe non initialisé.\n");
        return;
    }

    // Libérer la mémoire de la colonne spécifiée
    supprimer_colonne(&(cdataframe->colonnes[indice_colonne]));

    // Décaler les pointeurs pour combler le trou
    for (int i = indice_colonne; i < cdataframe->nombre_colonnes - 1; i++) {
        cdataframe->colonnes[i] = cdataframe->colonnes[i+1];
    }

    // Réduire le nombre de colonnes
    cdataframe->nombre_colonnes--;
}

void renommer_colonne_cdataframe(CDataframe *cdataframe, int indice_colonne, const char *nouveau_titre) {
    if (!cdataframe || indice_colonne < 0 || indice_colonne >= cdataframe->nombre_colonnes || !nouveau_titre) {
        printf("Erreur : Paramètre invalide.\n");
        return;
    }

    COLONNE *col = cdataframe->colonnes[indice_colonne];

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

int acceder_valeur_cellule(CDataframe *cdataframe, int no_colonne, int no_ligne, int *valeur) {
    // Vérifier si le DataFrame et l'indice sont valides
    if (!cdataframe || no_colonne < 0 || no_colonne >= cdataframe->nombre_colonnes) {
        printf("Erreur : Index de colonne invalide ou DataFrame non initialisé.\n");
        return 0;  // Échec
    }

    COLONNE *col = cdataframe->colonnes[no_colonne];
    if (no_ligne < 0 || no_ligne >= col->taille_logique) {
        printf("nErreur : Index de ligne invalide.\n");
        return 0;  // Échec
    }

    // Accéder à la valeur
    *valeur = col->donnees[no_ligne];
    return 1;  // Succès
}

void afficher_noms_colonnes(CDataframe *cdataframe) {
    if (!cdataframe || !cdataframe->colonnes) {
        printf("Le CDataFrame n'est pas initialisé ou il n'y a pas de colonnes.\n");
        return;
    }

    printf("Noms des colonnes du CDataframe:\n");
    for (int i = 0; i < cdataframe->nombre_colonnes; i++) {
        printf("%d: %s\n", i + 1, cdataframe->colonnes[i]->titre);
    }
}

int retourner_nombre_lignes(CDataframe *cdataframe) {
    if (!cdataframe || cdataframe->nombre_colonnes == 0 || !cdataframe->colonnes[0]) {
        printf("Le DataFrame est vide ou mal initialisé.\n");
        return -1;
    }  

    int nombre_lignes_max = 0;
    for(int i = 0; i<cdataframe->nombre_colonnes; i++){
        if((cdataframe->colonnes[i]->taille_logique) > nombre_lignes_max){
            nombre_lignes_max = cdataframe->colonnes[i]->taille_logique;
        }
    }
    
    return nombre_lignes_max;
}

void afficher_nombre_colonnes(CDataframe *cdataframe) {
    if (!cdataframe) {
        printf("Le DataFrame n'est pas initialisé.\n");
        return;
    }

    printf("Nombre de colonnes dans le DataFrame : %d\n", cdataframe->nombre_colonnes);
}

int compter_cellules_valeur(CDataframe *cdataframe, int valeur_recherchee) {
    if (!cdataframe || !cdataframe->colonnes) {
        return -1;
    }
    int compteur = 0;
    for (int i = 0; i < cdataframe->nombre_colonnes; i++) {
        COLONNE *colonne = cdataframe->colonnes[i];
        for (int j = 0; j < colonne->taille_logique; j++) {
            if (colonne->donnees[j] == valeur_recherchee) {
                compteur++;
            }
        }
    }

    return compteur;
}

int compter_cellules_superieures(CDataframe *cdataframe, int valeur_limite) {
    if (!cdataframe || !cdataframe->colonnes) {
        return -1;
    }

    int compteur = 0;
    for (int i = 0; i < cdataframe->nombre_colonnes; i++) {
        COLONNE *colonne = cdataframe->colonnes[i];
        for (int j = 0; j < colonne->taille_logique; j++) {
            if (colonne->donnees[j] > valeur_limite) {
                compteur++;
            }
        }
    }

    return compteur;
}

int compter_cellules_inferieures(CDataframe *cdataframe, int valeur_limite) {
    if (!cdataframe || !cdataframe->colonnes) {
        return -1;
    }

    int compteur = 0;
    for (int i = 0; i < cdataframe->nombre_colonnes; i++) {
        COLONNE *colonne = cdataframe->colonnes[i];
        for (int j = 0; j < colonne->taille_logique; j++) {
            if (colonne->donnees[j] < valeur_limite) {
                compteur++;
            }
        }
    }

    return compteur;
}

void cdataframe_vide() {
    printf("Le CDataframe est vide.\n");
}

void entree_invalide() {
    printf("Entree invalide.\n");
}

void remplir_cdataframe(CDataframe* cdataframe) {
    int choix_nombre_colonne;

    printf("Combien de colonnes voulez-vous ajouter au CDataframe ?\n>");
    scanf(" %d", &choix_nombre_colonne);
    printf("\n");

    for (int i = 0; i < choix_nombre_colonne; i++) {
        printf("Veuillez entrer un titre a la colonne d'indice %d :\n>", i);

        char titre[TAILLE_TITRE];
        scanf(" %s", titre);

        COLONNE* colonne = creer_colonne(titre);

        printf("Combien de valeurs voulez vous ajouter a cette colonne ?\n>");
        int choix_nombre_valeurs;
        scanf(" %d", &choix_nombre_valeurs);
        printf("\n");

        for (int i = 0; i < choix_nombre_valeurs; i++) {
            printf("Entrez la valeur d'indice %d :\n>", i);
            int nouvelle_valeur;
            scanf(" %d", &nouvelle_valeur);
            inserer_valeur(colonne, nouvelle_valeur);
        }
        printf("\n");

        ajouter_colonne(cdataframe, colonne);
    }
}
