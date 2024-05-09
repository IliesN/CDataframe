//
//
//

#include "colonne.h"

#ifndef UNTITLED_CDATAFRAME_H
#define UNTITLED_CDATAFRAME_H


#define NOM_FICHIER_AFFICHAGE "affichage_cdataframe.txt"


typedef struct {
    Colonne **colonnes;
    int nombre_colonnes;
    int capacite;
} Cdataframe;


// 1. Alimentation
Cdataframe *creer_cdataframe();

int ajouter_colonne(Cdataframe *cdataframe, Colonne *colonne);

void completer_cdataframe_zeros(Cdataframe *cdataframe);

void remplir_cdataframe_utilisateur(Cdataframe *cdataframe);

void remplir_cdataframe_en_dur(Cdataframe *cdataframe);


// 2. Affichage
void afficher_cdataframe(Cdataframe *cdataframe, int limite_ligne, int limite_colonne);

void affichage_cdataframe_brut(Cdataframe *cdataframe, int limite_ligne, int limite_colonne);

void ecrire_cdataframe_fichier(char *nom_fichier, Cdataframe *cdataframe, int limite_ligne, int limite_colonne);

void afficher_cdataframe_limite(Cdataframe *cdataframe, int limite_ligne, int limite_colonne);


// 3. Operations usuelles
int ajouter_ligne(Cdataframe *cdataframe, int* tableau_valeurs);

void supprimer_ligne_indice(Cdataframe *cdataframe, int indice_ligne);

void supprimer_colonne_indice(Cdataframe *cdataframe, int indice_colonne);

void renommer_colonne(Cdataframe *cdataframe, int indice_colonne);

int existence_valeur(Cdataframe *cdataframe, int valeur_recherchee);

int acceder_valeur_cellule(Cdataframe *cdataframe, int indice_colonne, int indice_ligne);

void afficher_noms_colonnes(Cdataframe *cdataframe);


// 4. Analyse et statistiques
int retourner_nombre_lignes(Cdataframe *cdataframe);

int compter_cellules_valeur(Cdataframe *cdataframe, int valeur_recherchee, EnumType type);

int compter_cellules_superieures(Cdataframe *cdataframe, int valeur_comparee, EnumType type);

int compter_cellules_inferieures(Cdataframe *cdataframe, int valeur_comparee, EnumType type);



// Fonctions reservees a l'affichage du CDataframe
int longueur_nombre(int nombre);

void afficher_titre_espaces(char *chaine, int taille_chaine_maximale, int longueur_indice_maximale, int longueur_ajout_titre, int indice_colonne);

void afficher_valeur_espaces(int entier, int taille_chaine_maximale, int cote_affichage);

void fermer_tableau(int nombre_colonnes, int longueur_chaine, int longueur_nombre_ligne_max);



// Fonctions affichage d'erreurs
void cdataframe_vide();

void entree_invalide();




#endif //UNTITLED_CDATAFRAME_H
