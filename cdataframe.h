//
//
//

#include "colonne.h"

#ifndef UNTITLED_CDATAFRAME_H
#define UNTITLED_CDATAFRAME_H


#define NOM_FICHIER_AFFICHAGE "affichage_cdataframe.txt"


typedef struct {
    COLONNE **colonnes;
    int nombre_colonnes;
    int capacite;
} CDataframe;

// 1. Alimentation
CDataframe *creer_cdataframe();

int ajouter_colonne(CDataframe *cdataframe, COLONNE *colonne);

void remplir_cdataframe_utilisateur(CDataframe *cdataframe);

void remplir_cdataframe_en_dur(CDataframe *cdataframe);


// 2. Affichage
void afficher_cdataframe(CDataframe *cdataframe, int limite_ligne, int limite_colonne);

void affichage_cdataframe_brut(CDataframe *cdataframe, int limite_ligne, int limite_colonne);

void ecrire_cdataframe_fichier(char *nom_fichier, CDataframe *cdataframe, int limite_ligne, int limite_colonne);

void afficher_cdataframe_limite(CDataframe *cdataframe, int limite_ligne, int limite_colonne);


// 3. Operations usuelles
int ajouter_ligne(CDataframe* cdataframe, int* tableau_valeurs);

void supprimer_ligne_indice(CDataframe *cdataframe, int indice_ligne);

void supprimer_colonne_indice(CDataframe *cdataframe, int indice_colonne);

void renommer_colonne(CDataframe *cdataframe, int indice_colonne);

int existence_valeur(CDataframe *cdataframe, int valeur_recherchee);

int acceder_valeur_cellule(CDataframe *cdataframe, int indice_colonne, int indice_ligne);

void afficher_noms_colonnes(CDataframe *cdataframe);


// 4. Analyse et statistiques
int retourner_nombre_lignes(CDataframe *cdataframe);

int compter_cellules_valeur(CDataframe *cdataframe, int valeur_recherchee);

int compter_cellules_superieures(CDataframe *cdataframe, int valeur_comparee);

int compter_cellules_inferieures(CDataframe *cdataframe, int valeur_comparee);



// Fonctions reservees a l'affichage du CDataframe
int longueur_nombre(int nombre);

void afficher_titre_espaces(char *chaine, int taille_chaine_maximale, int longueur_indice_maximale, int longueur_ajout_titre, int indice_colonne);

void afficher_valeur_espaces(int entier, int taille_chaine_maximale, int cote_affichage);

void fermer_tableau(int nombre_colonnes, int longueur_chaine, int longueur_nombre_ligne_max);



// Fonctions affichage d'erreurs
void cdataframe_vide();

void entree_invalide();




#endif //UNTITLED_CDATAFRAME_H
