#ifndef _PILE_H_
#define _PILE_H_
#include "modele_donnees.c"

//Piles
int est_pile_vide(TPile pile);
void empiler(TPile * pile, TCarte * c);
TCarte depiler(TPile * pile);
void init_pile(TPile * pile);
void afficher_pile(TPile pile);
int taille_pile(TPile pile);
void liberer_pile(TPile * pile);
void supprimer_carte_totem(TPile * pile, TMain * main, int num);

//Gestion Main

void piocher(TMain *mainJoueur, TPile *pile);
void DeposerCarte(TPile *totem, int numCarteMain, TMain *main);
TCarte Retrait_Carte_Main(TMain *main, int numCarteMain);
void JouerCarteCoupBas(TCarte carte, TPile pile);

//Killian
void afficherCartes(TCarte* listeCartes,int taille);
void init_ListeCarte(TCarte* liste,int nbCarte,int nbJoueur);

//Gestion init partie
void Distribuer_Cartes(TJoueur *listeJoueur, TPile *listeCartes, int nbCartes, int nbJoueur);


#endif
