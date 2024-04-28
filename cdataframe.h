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
void afficher_cdataframe(CDataframe *cdataframe);

void ecrire_dataframe_fichier(char *nom_fichier, CDataframe *cdataframe);

void afficher_lignes_cdataframe(CDataframe *cdataframe, int limite);

void afficher_colonnes_cdataframe(CDataframe *cdataframe, int limite);


// 3. Opérations usuelles
// ajouter_ligne | FONCTION A AJOUTER !

void supprimer_ligne_indice(CDataframe *cdataframe, int indice_ligne);

void supprimer_colonne_indice(CDataframe *cdataframe, int indice_colonne);

void renommer_colonne(CDataframe *cdataframe, int indice_colonne, char *nouveau_titre);

int existence_valeur(CDataframe *cdataframe, int valeur_recherchee);

int acceder_valeur_cellule(CDataframe *cdataframe, int indice_colonne, int indice_ligne, int *valeur);

void afficher_noms_colonnes(CDataframe *cdataframe);


// 4. Analyse et statistiques
int retourner_nombre_lignes(CDataframe *cdataframe);

int compter_cellules_valeur(CDataframe *cdataframe, int valeur_recherchee);

int compter_cellules_superieures(CDataframe *cdataframe, int valeur_comparee);

int compter_cellules_inferieures(CDataframe *cdataframe, int valeur_comparee);



// Fonctions réservées à l'affichage du CDataframe
int longueur_nombre(int nombre);

void afficher_titre_espaces(char *chaine, int taille_chaine_maximale, int longueur_indice_maximale, int longueur_ajout_titre, int indice_colonne);

void afficher_valeur_espaces(int entier, int taille_chaine_maximale, int cote_affichage);

void fermer_tableau(int nombre_colonnes, int longueur_chaine, int longueur_nombre_ligne_max);



// Fonctions affichage d'erreurs
void cdataframe_vide();

void entree_invalide();




#endif //UNTITLED_CDATAFRAME_H
