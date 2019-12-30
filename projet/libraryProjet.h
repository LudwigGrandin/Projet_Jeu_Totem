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
void JouerCarte(TPile *totem, TPile *pioche, int numCarteMain, TJoueur *joueurQuiJoue, TJoueur *listeJoueur);
TCarte Retrait_Carte_Main(TMain *main, int numCarteMain);
void JouerCarteCoupBas(TCarte carte, TPile *pioche ,TJoueur *joueurQuiJoue, TJoueur *joueurCible, TJoueur listeJoueur, int *gagnePartie);
void Afficher_Main(TMain mainJoueur);//Permet d'afficher une liste chaînée
int verif_carte(TMain mainJoueur, int numCarte); //Vérifie si le joueur a bien la carte qu'il veut jouer en sa possession renvoie 1 si oui sinon renvoie 0
void JouerCarteTotem(TCarte carte, TPile *pioche ,TJoueur *joueurQuiJoue, TJoueur listeJoueur);
void tete_coyote(TJoueur * j1, TJoueur * j2);//échange le totem avec celui d'un autre joueur
void tete_corbeau(TJoueur * j1, TJoueur * j2);//échange la main avec celle d'un autre joueur
void liberer_main(TMain * main);
void Donner_Main_Vers_Voisin_Gauche(TJoueur *listeJoueur, int nbJoueur);
void Donner_Totem_Vers_Voisin_Gauche(TJoueur *listeJoueur, int nbJoueur);


//Pioche

void init_sans_doublons(int* tableau,int taille);
void melanger(int* tableau, int taille);
//void init_pioche(int* tableau,int nbCarte,TCarte* listeCarte, TPile* pioche);
void init_pioche(int nbCarte,int nbJoueur, TPile* pioche);
void init_ListeCarte(TCarte* liste,int nbCarte,int nbJoueur);
void afficherCartes(TCarte* listeCartes,int taille);
int saisir_entre(int min, int max);

//Points
void ajout_Points(TJoueur *joueur, int *gagnePartie);
void initialiser_Points(TJoueur* listeJoueur,int nbJoueur);
void affichage_Points(TJoueur* listeJoueur,int nbJoueur);

//Gestion init partie
//void Distribuer_Cartes(TJoueur *listeJoueur, TPile *listeCartes, int nbCartes, int nbJoueur);
int Choix_Premier_Joueur(int nbJoueur);
void Defausser_Carte(TMain *mainJoueur, int numCarte);
void init_Joueurs(TJoueur* listeJoueur,int nbJoueur);
void tour_joueur(TJoueur *listeJoueur, TPile *pioche, int *gagneManche, int *gagnePartie);

// Libere la mémoire de toutes les piles,listes chainées des joueurs et de la pioche
void nettoyage_partie(TJoueur* listeJoueur,int nbJoueur ,TPile* laPioche);

#endif
