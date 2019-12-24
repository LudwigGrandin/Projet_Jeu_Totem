#ifndef _PILE_H_
#define _PILE_H_
#include "modele_donnees.c"

//Piles
int est_pile_vide(TPile pile);
void empiler(TPile * pile, TCarte * c);
TCarte * depiler(TPile * pile);
void init_pile(TPile * pile);
void afficher_pile(TPile pile);
int taille_pile(TPile pile);
void liberer_pile(TPile * pile);
void supprimer_carte_totem(TPile * pile, TMain * main, int num);

//Gestion Main

void piocher(TMain *mainJoueur, TPile *pile, TCarte *carte);
void DeposerCarteTotem(TPile totem, int numCarteMain, TMain *main);
void choix_Emplacement_Carte_Main(TMain *main, int numCarteMain, TCarte *emplacementCartePrecedente,TCarte *emplacementCarteActuelle);
void JouerCarteCoupBas(TCarte carte, TPile pile);

//pioche
void afficherCartes(TCarte* listeCartes,int taille);
void init_ListeCarte(TCarte* liste,int nbCarte,int nbJoueur);
void init_pioche(int* tableau,int taille, TPile pioche);
void melanger(int* tableau, int taille);
void init_sans_doublons(int* tableau,int a, int b);


int saisir_entre(int min, int max);
#endif
