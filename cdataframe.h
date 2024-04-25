//
// Created by ismar on 21/04/2024.
//
#include "colonne.h"

#ifndef UNTITLED_CDATAFRAME_H
#define UNTITLED_CDATAFRAME_H


#define TAILLE_REALLOC 256
#define TAILLE_TITRE (16 + 1)


typedef struct {
    COLONNE **colonnes;
    int nb_colonnes;
    int capacite;
} CDataframe;


CDataframe *creer_cdataframe();


int ajouter_colonne(CDataframe *df, COLONNE *col);

void afficher_cdataframe(CDataframe *df);

void afficher_lignes_cdataframe(CDataframe *df, int lim);

void afficher_colonnes_cdataframe(CDataframe *df, int lim);

void supprimer_colonne_cdataframe(CDataframe *df, int indice_colonne);

void renommer_colonne_cdataframe(CDataframe *df, int indice_colonne, const char *nouveau_titre);

void afficher_noms_colonnes(CDataframe *df);

int acceder_valeur_cellule(CDataframe *df, int no_colonne, int no_ligne, int *valeur);

void afficher_nombre_lignes(CDataframe *df);

void afficher_nombre_colonnes(CDataframe *df);

int compter_cellules_valeur(CDataframe *df, int valeur_recherchee);

int compter_cellules_superieures(CDataframe *df, int valeur_limite);

int compter_cellules_inferieures(CDataframe *df, int valeur_limite);

void supprimer_ligne(CDataframe *df, int index_ligne);


#endif //UNTITLED_CDATAFRAME_H
