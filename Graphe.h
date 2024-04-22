#ifndef __GRAPHE_H__
#define __GRAPHE_H__

#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int u, v; /* Numeros des sommets extremite */
} Arete;

typedef struct cellule_arete {
    Arete *a; /* pointeur sur l’arete */
    struct cellule_arete *suiv;
} Cellule_arete;

typedef struct {
    int num; /* Numero du sommet (le meme que dans T_som) */
    double x, y;
    Cellule_arete *L_voisin; /* Liste chainee des voisins */
} Sommet;

typedef struct {
    int e1, e2; /* Les deux extremites de la commodite */
} Commod;

typedef struct {
    int nbsom; /* Nombre de sommets */
    Sommet **T_som; /* Tableau de pointeurs sur sommets */
    int gamma;
    int nbcommod; /* Nombre de commodites */
    Commod *T_commod; /* Tableau des commodites */
} Graphe;

// Structure créee pour le parcours en largeur afin d'avoir la liste des sommets déjà visités
typedef struct cellule_sommet {
    Sommet *s; /* pointeur sur l’arete */
    struct cellule_sommet *suiv;
} Cellule_sommet;

int cherche_sommet(Graphe *g, int x, int y);
void creation_arete(Graphe *g, Sommet *s1, Sommet *s2);
Graphe* creerGraphe(Reseau* r);

#endif
