#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "libraryProjet.h"


int main()
{
    TPile pile;
    TPile totem;
	init_pile(&pile);
	init_pile(&totem);
	pile.sommet = NULL;
	totem.sommet = NULL;
	TCarte carte;
	carte.num = 0;
	carte.type = 0;
	int nombreCarte = 2;
	int rejouer = 0;
	int i;


	int nbCarte = 64;
	int nbJoueur = 4;
	int numCarteJoueur;
	int gagnePartie = 0, gagneManche = 0;
    TJoueur newJoueur;
	TMain mainJoueur;
	int IDJoueur = 0;
	mainJoueur.debut = (TPilelem*) malloc(sizeof(TPilelem));
	mainJoueur.debut = NULL;
	TCarte carteJoue;
	int choixRejouerPartie=0;


	do
    {
        printf("Bienvenue dans le jeu Totem\n");
        printf("Combien de joueur etes vous ? : ");
        scanf("%d", &nbJoueur);
        TJoueur listeJoueur[nbJoueur];
        //creé et mélange la pioche
        init_pioche(nbCarte,nbJoueur,&pile);
        //crée la liste de joueur
        init_Joueurs(listeJoueur, nbJoueur);
        //system("cls");
        printf("nom joueur 0 : %s \n", listeJoueur[0].nom);
        printf("La partie peut commencer\n\n");

       // Début
       Distribuer_Cartes(listeJoueur,&pile,nbCarte,nbJoueur);
       do
       {
           tour_joueur(&listeJoueur[IDJoueur],&pile,&gagneManche, &gagnePartie);

           IDJoueur ++;
           if(IDJoueur == nbJoueur)
           {
               IDJoueur == 0;
           }

       }while(gagnePartie != 1);

       printf("Voulez vous rejouer ? :");
       scanf("%d", &choixRejouerPartie);


    }while(choixRejouerPartie != 1);

    liberer_main(&mainJoueur);
	liberer_pile(&pile); // libère toute la pile

    return 0;
}
