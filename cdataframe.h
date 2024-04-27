//
// Created by ismar on 21/04/2024.
//
#include "colonne.h"

#ifndef UNTITLED_CDATAFRAME_H
#define UNTITLED_CDATAFRAME_H


#define TAILLE_REALLOC 256
#define TAILLE_TITRE (16 + 1)  // Titre de 16 caractères max

#define NOM_FICHIER_AFFICHAGE "affichage_cdataframe.txt"


typedef struct {
    COLONNE **colonnes;
    int nombre_colonnes;
    int capacite;
} CDataframe;


CDataframe *creer_cdataframe();


int ajouter_colonne(CDataframe *cdataframe, COLONNE *col);

void afficher_cdataframe(CDataframe *cdataframe);

void afficher_lignes_cdataframe(CDataframe *cdataframe, int lim);

void afficher_colonnes_cdataframe(CDataframe *cdataframe, int lim);

void supprimer_colonne_cdataframe(CDataframe *cdataframe, int indice_colonne);

void renommer_colonne_cdataframe(CDataframe *cdataframe, int indice_colonne, const char *nouveau_titre);

void afficher_noms_colonnes(CDataframe *cdataframe);

int acceder_valeur_cellule(CDataframe *cdataframe, int no_colonne, int no_ligne, int *valeur);

int retourner_nombre_lignes(CDataframe *cdataframe);

void afficher_nombre_colonnes(CDataframe *cdataframe);

int compter_cellules_valeur(CDataframe *cdataframe, int valeur_recherchee);

int compter_cellules_superieures(CDataframe *cdataframe, int valeur_limite);

int compter_cellules_inferieures(CDataframe *cdataframe, int valeur_limite);

void supprimer_ligne(CDataframe *cdataframe, int index_ligne);


char* afficher_titre_espaces(char* chaine, int taille_chaine_maximale, int longueur_indice_maximale, int longueur_ajout_titre, int indice_colonne);

void afficher_valeur_espaces(int entier, int taille_chaine_maximale);

void fermer_tableau(int nombre_colonnes, int longueur_chaine, int longueur_nombre_ligne_max);

void cdataframe_vide();

void remplissage_en_dur(CDataframe *cdataframe);

void entree_invalide();

void remplir_cdataframe(CDataframe* cdataframe);

int longueur_nombre(int nombre);

void afficher_indice_espaces(int entier, int taille_chaine_maximale);

void ecrire_affichage_fichier(char* nom_fichier, CDataframe* cdataframe);

#endif //UNTITLED_CDATAFRAME_H
