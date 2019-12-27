#ifndef _PILE_H_
#define _PILE_H_
#include "modele_donnees.c"

//Piles
int est_pile_vide(TPile pile);
void empiler(TPile * pile, TCarte * c);
TPile depiler(TPile * pile);
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
void Afficher_Main(TMain mainJoueur);//Permet d'afficher une liste chaînée

//Killian
void init_sans_doublons(int* tableau,int taille);
void melanger(int* tableau, int taille);
//void init_pioche(int* tableau,int nbCarte,TCarte* listeCarte, TPile* pioche);
void init_pioche(int nbCarte,int nbJoueur, TPile* pioche);
void init_ListeCarte(TCarte* liste,int nbCarte,int nbJoueur);
void afficherCartes(TCarte* listeCartes,int taille);
int saisir_entre(int min, int max);

//Gestion init partie
void Distribuer_Cartes(TJoueur *listeJoueur, TPile *listeCartes, int nbCartes, int nbJoueur);
int Choix_Premier_Joueur(int nbJoueur);


#endif
