#ifndef _PILE_H_
#define _PILE_H_
#include "modele_donnees.c"


int est_pile_vide(TPile pile);
void empiler(TPile * pile, TCarte * c);
void depiler(TPile * pile);
void init_pile(TPile * pile);
void afficher_pile(TPile pile);
int taille_pile(TPile pile);
void liberer_pile(TPile * pile);
void supprimer_carte_totem(TPile * pile, TMain * main, int num);

#endif