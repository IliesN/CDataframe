//
//
//

#include "colonne.h"
#include "cdataframe.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


Cdataframe *creer_cdataframe() {
    Cdataframe *cdataframe = malloc(sizeof(Cdataframe));
    if (!cdataframe) {
        return NULL; // echec de l'allocation
    }

    cdataframe->colonnes = NULL;
    cdataframe->nombre_colonnes = 0;
    cdataframe->capacite = 0;

    return cdataframe;
}

int ajouter_colonne(Cdataframe *cdataframe, Colonne *colonne) {
    if (cdataframe->nombre_colonnes == cdataframe->capacite) { // Verifie si le tableau est plein
        int new_capacite;
        if (!cdataframe->capacite) {
            new_capacite = TAILLE_REALLOC;
        } else {
            new_capacite = cdataframe->capacite * 2; // Double la capacite existante
        }
        Colonne **new_colonnes = realloc(cdataframe->colonnes, new_capacite * sizeof(Colonne *));
        if (!new_colonnes) {
            return -1;
        }

        cdataframe->colonnes = new_colonnes;
        cdataframe->capacite = new_capacite;
    }

    cdataframe->colonnes[cdataframe->nombre_colonnes] = colonne;
    cdataframe->nombre_colonnes++;
    return 0;
}

void completer_cdataframe_zeros(Cdataframe *cdataframe) {
    int nombre_lignes_max = retourner_nombre_lignes(cdataframe);
    for (int i = 0; i < cdataframe->nombre_colonnes; i++) {
        Colonne *colonne = cdataframe->colonnes[i];

        int j = colonne->taille_logique;
        for (int k = j; k < nombre_lignes_max; k++) {
            inserer_valeur(colonne, 0);
        }
    }
}

void remplir_cdataframe_utilisateur(Cdataframe *cdataframe) {
    int choix_nombre_colonne;

    do {
        printf("Combien de colonnes voulez-vous ajouter au CDataframe ?\n>");
        scanf(" %d", &choix_nombre_colonne);
        printf("\n");
        if (choix_nombre_colonne < 1) {
            printf("Veuillez entrer un nombre correct de colonnes.\n\n");
        }
    } while (choix_nombre_colonne < 1);

    for (int i = 0; i < choix_nombre_colonne; i++) {
        printf("Veuillez entrer un titre a la colonne d'indice %d :\n>", i);

        char titre[TAILLE_TITRE];
        scanf(" %s", titre);

        Colonne *colonne = creer_colonne(titre);

        int choix_nombre_valeurs;

        do {
            printf("Combien de valeurs voulez vous ajouter a cette colonne ?\n>");
            scanf(" %d", &choix_nombre_valeurs);
            printf("\n");
            if (choix_nombre_valeurs < 1) {
                printf("Veuillez entrer un nombre correct de valeurs.\n\n");
            }
        } while (choix_nombre_valeurs < 1);

        for (int i = 0; i < choix_nombre_valeurs; i++) {
            printf("Entrez la valeur d'indice %d :\n>", i);
            int nouvelle_valeur;
            scanf(" %d", &nouvelle_valeur);
            inserer_valeur(colonne, nouvelle_valeur);
        }
        printf("\n");

        ajouter_colonne(cdataframe, colonne);
    }
    completer_cdataframe_zeros(cdataframe);
}

void remplir_cdataframe_en_dur(Cdataframe *cdataframe) {
    Colonne *colonne1 = creer_colonne("premiere_colonne");
    inserer_valeur(colonne1, 11);
    inserer_valeur(colonne1, 12);
    inserer_valeur(colonne1, 13);
    ajouter_colonne(cdataframe, colonne1);

    Colonne *colonne2 = creer_colonne("deuxieme_colonne");
    inserer_valeur(colonne2, 21);
    inserer_valeur(colonne2, 22);
    inserer_valeur(colonne2, 23);
    inserer_valeur(colonne2, 24);
    inserer_valeur(colonne2, 25);
    inserer_valeur(colonne2, 26);
    ajouter_colonne(cdataframe, colonne2);

    Colonne *colonne3 = creer_colonne("troisieme_colonne");
    inserer_valeur(colonne3, 31);
    inserer_valeur(colonne3, 32);
    inserer_valeur(colonne3, 33);
    inserer_valeur(colonne3, 34);
    ajouter_colonne(cdataframe, colonne3);
    /*
    Colonne *colonne4 = creer_colonne("Titre4");
    inserer_valeur(colonne4, 10);
    inserer_valeur(colonne4, 20);
    inserer_valeur(colonne4, 30);
    inserer_valeur(colonne4, 40);
    ajouter_colonne(cdataframe, colonne4);

    Colonne *colonne5 = creer_colonne("Titre5");
    inserer_valeur(colonne5, 5);
    inserer_valeur(colonne5, 10);
    inserer_valeur(colonne5, 15);
    inserer_valeur(colonne5, 20);
    inserer_valeur(colonne5, 25);
    ajouter_colonne(cdataframe, colonne5);

    Colonne *colonne6 = creer_colonne("Titre6");
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

    Colonne *colonne7 = creer_colonne("Titre7");
    inserer_valeur(colonne7, 50);
    inserer_valeur(colonne7, 100);
    inserer_valeur(colonne7, 150);
    inserer_valeur(colonne7, 200);
    inserer_valeur(colonne7, 250);
    inserer_valeur(colonne7, 300);
    ajouter_colonne(cdataframe, colonne7);

    Colonne *colonne8 = creer_colonne("Titre8");
    inserer_valeur(colonne8, -1);
    inserer_valeur(colonne8, -2);
    inserer_valeur(colonne8, -3);
    inserer_valeur(colonne8, -4);
    inserer_valeur(colonne8, -5);
    ajouter_colonne(cdataframe, colonne8);

    Colonne *colonne9 = creer_colonne("Titre9");
    inserer_valeur(colonne9, 1000);
    inserer_valeur(colonne9, 2000);
    inserer_valeur(colonne9, 3000);
    inserer_valeur(colonne9, 4000);
    inserer_valeur(colonne9, 5000);
    ajouter_colonne(cdataframe, colonne9);

    Colonne *colonne10 = creer_colonne("Titre10");
    inserer_valeur(colonne10, 1);
    inserer_valeur(colonne10, 1);
    ajouter_colonne(cdataframe, colonne10);

    Colonne *colonne11 = creer_colonne("dfsgsdfgsdfgsdfgsdf");
    inserer_valeur(colonne11, 1);
    inserer_valeur(colonne11, 1);
    ajouter_colonne(cdataframe, colonne11);

    Colonne *colonne12 = creer_colonne("dfsgsdfgsdsdfgsdf");
    inserer_valeur(colonne12, 1);
    inserer_valeur(colonne12, 1);
    ajouter_colonne(cdataframe, colonne12);

    /*
    */
    completer_cdataframe_zeros(cdataframe);
}



void afficher_cdataframe(Cdataframe *cdataframe, int limite_ligne, int limite_colonne) {
    if (!cdataframe->nombre_colonnes) {
        cdataframe_vide();
        return;
    }

    int i;

    int nombre_lignes_affichage;
    if (limite_ligne != 0) {
        nombre_lignes_affichage = limite_ligne;
    } else {
        nombre_lignes_affichage = retourner_nombre_lignes(cdataframe);
    }

    int nombre_colonnes_affichage;
    if (limite_colonne != 0) {
        nombre_colonnes_affichage = limite_colonne;
    } else {
        nombre_colonnes_affichage = cdataframe->nombre_colonnes;
    }

    int longueur_caractere_tableau = 0;
    int longueur_nombre_ligne_max = longueur_nombre(nombre_lignes_affichage);
    int longueur_titre_maximale = 0;

    for (i = 0; i < nombre_colonnes_affichage; i++) {
        int longueur_titre = strlen(cdataframe->colonnes[i]->titre);
        if (longueur_titre > longueur_titre_maximale) {
            longueur_titre_maximale = longueur_titre;
        }
    }
    int ajout_titre = 3 + 1 + longueur_nombre_ligne_max + 1; // + "  [taille indice]"

    longueur_titre_maximale += ajout_titre;

    for (i = 0; i < nombre_colonnes_affichage; i++) {
        longueur_caractere_tableau += 3 + longueur_titre_maximale;
    }
    longueur_caractere_tableau -= 1;
    
    for (i = 0; i < 2 + longueur_nombre_ligne_max + 2; i++) {
        printf(" ");
    }
    for (i = 0; i < longueur_caractere_tableau; i++) {
        printf("_");
    }
    printf("\n");
    
    for (i = 0; i < 3 + longueur_nombre_ligne_max; i++) {
        printf(" ");
    }
    for (i = 0; i < nombre_colonnes_affichage; i++) {
        afficher_titre_espaces(cdataframe->colonnes[i]->titre, longueur_titre_maximale, longueur_nombre_ligne_max, ajout_titre, i);
    }
    printf("|\n");

    if (!retourner_nombre_lignes(cdataframe)) {
        printf("    ");
        for (i = 0; i < nombre_colonnes_affichage; i++) {
            printf("|_");
            for (int j = 0; j < longueur_titre_maximale; j++)
                printf("_");
            printf("_");
        }
        printf("|\n");

        printf("    | Le CDataframe ne contient aucune ligne.\n"
               "    |");
        for (i = 0; i < longueur_caractere_tableau; i++) {
            printf("_");
        }

    } else {
        printf(" _");
        for (i = 0; i < longueur_nombre_ligne_max; i++) {
            printf("_");
        }
        printf("_");
        for (i = 0; i < nombre_colonnes_affichage; i++) {
            printf("|_");
            for (int j = 0; j < longueur_titre_maximale; j++)
                printf("_");
            printf("_");
        }
        printf("|\n");

        for (i = 0; i < nombre_lignes_affichage; i++) {
            printf("| ");
            afficher_valeur_espaces(i, longueur_nombre_ligne_max, 1);
            printf(" ");
            for (int j = 0; j < nombre_colonnes_affichage; j++) {
                printf("| ");
                afficher_valeur_espaces(cdataframe->colonnes[j]->donnees[i], longueur_titre_maximale, 0);
                printf(" ");
            }
            printf("|\n");
            fermer_tableau(nombre_colonnes_affichage, longueur_titre_maximale, longueur_nombre_ligne_max);
        }
    }
    printf("\n\n");
}

void affichage_cdataframe_brut(Cdataframe *cdataframe, int limite_ligne, int limite_colonne) {
    if (!cdataframe->nombre_colonnes) {
        cdataframe_vide();
        return;
    }

    int nombre_lignes_affichage;
    if (limite_ligne != 0) {
        nombre_lignes_affichage = limite_ligne;
    } else {
        nombre_lignes_affichage = retourner_nombre_lignes(cdataframe);
    }

    int nombre_colonnes_affichage;
    if (limite_colonne != 0) {
        nombre_colonnes_affichage = limite_colonne;
    } else {
        nombre_colonnes_affichage = cdataframe->nombre_colonnes;
    }

    for (int j = 0; j < nombre_colonnes_affichage; j++) {
        printf("%s\t", cdataframe->colonnes[j]->titre);
    }
    printf("\n");
    
    for (int i = 0; i < nombre_lignes_affichage; i++) {
        for (int j = 0; j < nombre_colonnes_affichage; j++) {
            printf("%d\t", cdataframe->colonnes[j]->donnees[i]);
        }
        printf("\n");
    }
    printf("\n");
}

void ecrire_cdataframe_fichier(char *nom_fichier, Cdataframe *cdataframe, int limite_ligne, int limite_colonne) {
    // Ouvre un fichier en mode ecriture avec le nom specifie dans la variable et stocke le pointeur de fichier dans la variable "fichier"
    FILE *fichier = fopen(nom_fichier, "w");

    // Redirige la sortie standard (stdout) vers le fichier specifie par "nom_fichier". a partir de maintenant, toutes les sorties de printf seront ecrites dans le fichier.
    freopen(nom_fichier, "w", stdout);

    // Appelle la fonction "afficher_cdataframe" pour afficher le contenu du CDataframe. Comme la sortie standard a ete redirigee, le resultat sera ecrit dans le fichier.
    afficher_cdataframe(cdataframe, limite_ligne, limite_colonne);

    // Restaure la sortie standard (stdout) en la redirigeant vers la console ("CON"). Les sorties de printf reviendront a leur comportement normal (affichage a l'ecran).
    freopen("CON", "w", stdout);

    // Ferme le fichier ouvert precedemment.
    fclose(fichier);

    printf("L'affichage du CDataframe a ete exporte dans un fichier \"affichage_cdataframe.txt\".\n\n");
}

void afficher_cdataframe_limite(Cdataframe *cdataframe, int limite_ligne, int limite_colonne) {
    if (!cdataframe->nombre_colonnes) {
        cdataframe_vide();
        return;
    } if (limite_ligne > retourner_nombre_lignes(cdataframe) || limite_ligne < 0) {
        printf("Nombre de lignes saisi trop faible ou trop eleve.\n\n");
        return;
    } if (limite_colonne > cdataframe->nombre_colonnes || limite_colonne < 0) {
        printf("Nombre de colonnes saisi trop faible ou trop eleve.\n\n");
        return;
    }
    afficher_cdataframe(cdataframe, limite_ligne, limite_colonne);
}



int ajouter_ligne(Cdataframe *cdataframe, int* tableau_valeurs) {
    int* nouvelles_donnees;
    for (int i = 0; i < cdataframe->nombre_colonnes; i++) {
        nouvelles_donnees = realloc(cdataframe->colonnes[i]->donnees, (cdataframe->colonnes[i]->taille_logique + 1) * sizeof(int));
        if (nouvelles_donnees == NULL) {
            return -1;
        }
        cdataframe->colonnes[i]->donnees = nouvelles_donnees;
    }

    for (int i = 0; i < cdataframe->nombre_colonnes; i++) {
        cdataframe->colonnes[i]->donnees[cdataframe->colonnes[i]->taille_logique] = tableau_valeurs[i];
        cdataframe->colonnes[i]->taille_logique++;
    }

    return 0;
}

void supprimer_ligne_indice(Cdataframe *cdataframe, int indice_ligne) {
    if (!cdataframe->nombre_colonnes) {
        cdataframe_vide();
        return;
    } if (indice_ligne > retourner_nombre_lignes(cdataframe) - 1 || indice_ligne < 0) {
        printf("L'indice de ligne saisi est trop faible ou trop eleve.\n\n");
        return;
    }
    
    // Supprimer la ligne pour chaque colonne
    for (int i = 0; i < cdataframe->nombre_colonnes; i++) {
        Colonne *colonne = cdataframe->colonnes[i];
        // Decaler les donnees des lignes suivantes vers le haut
        for (int j = indice_ligne; j < colonne->taille_logique - 1; j++) {
            colonne->donnees[j] = colonne->donnees[j + 1];
        }
        // Mettre a jour la taille logique de la colonne
        colonne->taille_logique--;
    }
    printf("La suppression de la ligne a bien eu lieu.\n\n");
}

void supprimer_colonne_indice(Cdataframe *cdataframe, int indice_colonne) {
    if (!cdataframe->nombre_colonnes) {
        cdataframe_vide();
        return;
    } if (indice_colonne > cdataframe->nombre_colonnes - 1 || indice_colonne < 0) {
        printf("L'indice de colonne saisi est trop faible ou trop eleve.\n\n");
        return;
    }

    // Liberer la memoire de la colonne specifiee
    supprimer_colonne(&(cdataframe->colonnes[indice_colonne]));

    // Decaler les pointeurs pour combler le trou
    for (int i = indice_colonne; i < cdataframe->nombre_colonnes - 1; i++) {
        cdataframe->colonnes[i] = cdataframe->colonnes[i + 1];
    }

    // Reduire le nombre de colonnes
    cdataframe->nombre_colonnes--;

    printf("La suppression de la colonne a bien eu lieu.\n\n");
}

void renommer_colonne(Cdataframe *cdataframe, int indice_colonne) {
    if (!cdataframe->nombre_colonnes) {
        cdataframe_vide();
        return;
    } if (indice_colonne > cdataframe->nombre_colonnes - 1 || indice_colonne < 0) {
        printf("L'indice de colonne saisi est trop faible ou trop eleve.\n\n");
        return;
    }
    
    Colonne *colonne = cdataframe->colonnes[indice_colonne];

    if (colonne->titre) {
        free(colonne->titre);
    }

    char nouveau_titre[TAILLE_TITRE];
    printf("Entrez le nouveau titre que vous souhaitez donner a cette colonne :\n>");
    scanf(" %s", nouveau_titre);

    // Allocation du nouveau titre
    colonne->titre = malloc(strlen(nouveau_titre) + 1); // + 1 pour le caractere de fin '\0'

    int i;
        
    for (i = 0; nouveau_titre[i] != '\0'; i++) {
        colonne->titre[i] = nouveau_titre[i];
    }
    colonne->titre[i] = '\0'; // Ajout du caractere de fin '\0'

    printf("Le titre de la colonne d'indice %d a bien ete change.\n\n", indice_colonne);
}

int existence_valeur(Cdataframe *cdataframe, int valeur_recherchee) {
    if (!cdataframe->nombre_colonnes) {
        return -1;
    }

    for (int i = 0; i < cdataframe->nombre_colonnes; i++) {
        Colonne *colonne = cdataframe->colonnes[i];
        for (int j = 0; j < colonne->taille_logique; j++) {
            if (colonne->donnees[j] == valeur_recherchee) {
                return 1;
            }
        }
    }
    
    return 0;
}

int acceder_valeur_cellule(Cdataframe *cdataframe, int indice_colonne, int indice_ligne) {
    Colonne *colonne = cdataframe->colonnes[indice_colonne];
    return colonne->donnees[indice_ligne];
}

void afficher_noms_colonnes(Cdataframe *cdataframe) {
    if (!cdataframe->colonnes) {
        cdataframe_vide();
        return;
    }

    printf("Noms des colonnes du CDataframe :\n");
    for (int i = 0; i < cdataframe->nombre_colonnes; i++) {
        printf("   - Nom de la colonne d'indice %d : \"%s\"\n", i, cdataframe->colonnes[i]->titre);
    }
    printf("\n");
}



int retourner_nombre_lignes(Cdataframe *cdataframe) {
    if (!cdataframe->nombre_colonnes) {
        return -1;
    }  

    int nombre_lignes_max = 0;
    for (int i = 0; i < cdataframe->nombre_colonnes; i++) {
        if (cdataframe->colonnes[i]->taille_logique > nombre_lignes_max) {
            nombre_lignes_max = cdataframe->colonnes[i]->taille_logique;
        }
    }
    
    return nombre_lignes_max;
}

int compter_cellules_valeur(Cdataframe *cdataframe, int valeur_recherchee) {
    if (!cdataframe->nombre_colonnes) {
        return -1;
    }

    int compteur = 0;
    for (int i = 0; i < cdataframe->nombre_colonnes; i++) {
        Colonne *colonne = cdataframe->colonnes[i];
        compteur += retourner_egal(colonne, valeur_recherchee);
    }

    return compteur;
}

int compter_cellules_superieures(Cdataframe *cdataframe, int valeur_comparee) {
    if (!cdataframe->nombre_colonnes) {
        return -1;
    }

    int compteur = 0;
    for (int i = 0; i < cdataframe->nombre_colonnes; i++) {
        Colonne *colonne = cdataframe->colonnes[i];
        compteur += retourner_superieur(colonne, valeur_comparee);
    }

    return compteur;
}

int compter_cellules_inferieures(Cdataframe *cdataframe, int valeur_comparee) {
    if (!cdataframe->nombre_colonnes) {
        return -1;
    }

    int compteur = 0;
    for (int i = 0; i < cdataframe->nombre_colonnes; i++) {
        Colonne *colonne = cdataframe->colonnes[i];
        compteur += retourner_inferieur(colonne, valeur_comparee);
    }

    return compteur;
}




int longueur_nombre(int nombre) {
    if (!nombre) {
        return 1;
    }

    int taille_nombre = 0;
    if (nombre < 0) {
        taille_nombre += 1;
    }

    while (nombre != 0) {
        nombre /= 10;
        taille_nombre++;
    }

    return taille_nombre;
}

void afficher_titre_espaces(char *chaine, int taille_chaine_maximale, int longueur_indice_maximale, int longueur_ajout_titre, int indice_colonne) {
    int taille_chaine = strlen(chaine);
    int taille_restante = taille_chaine_maximale - taille_chaine - longueur_ajout_titre;

    printf("| %s", chaine);
    for (int i = 0; i < taille_restante + longueur_indice_maximale - longueur_nombre(indice_colonne); i++) {
        printf(" ");
    }
    printf("   [%d] ", indice_colonne);
}

void afficher_valeur_espaces(int entier, int taille_chaine_maximale, int cote_affichage) {
    int nombre_espaces = taille_chaine_maximale - longueur_nombre(entier);
    if (!cote_affichage) {
        printf("%d", entier);
        for (int i = 0; i < nombre_espaces; i++) {
            printf(" ");
        }
    } else {
        for (int i = 0; i < nombre_espaces; i++) {
            printf(" ");
        }
        printf("%d", entier);
    }
}

void fermer_tableau(int nombre_colonnes, int longueur_chaine, int longueur_nombre_ligne_max) {
    int i;
    
    printf("|_");
    for (i = 0; i < longueur_nombre_ligne_max; i++) {
        printf("_");
    }
    printf("_");
    for (i = 0; i < nombre_colonnes; i++) {
        printf("|_");
        for (int j = 0; j < longueur_chaine; j++) {
            printf("_");
        }
        printf("_");
    }
    printf("|\n");
}




void cdataframe_vide() {
    printf("Le CDataframe est vide.\n\n");
}

void entree_invalide() {
    printf("Entree invalide.\n\n");
}
