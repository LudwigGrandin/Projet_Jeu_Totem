#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "libraryProjet.h"
//#include "Gestion_Init_Partie.c"
//#include "Gestion_Main.c"

	/* Définition d'une carte */


        // Test Killian
    /*
        //TODO : selon le nbr de joueurs des cartes seront à retirer
        printf("\nCombien y aura t-il de joueurs ?");
        int nbJoueur = saisir_entre(2,6);

        int taillePioche = 64;
        TPile laPioche;

        init_pile(&laPioche);

        // créer la pioche de TCartes mélangé en utilisant le tableau d'entier et la liste de TCartes
        init_pioche(taillePioche,nbJoueur,&laPioche);
        printf("\n ");
        afficher_pile(laPioche);
        printf("\n debug apres pioche \n");

    */
        //TJoueur* listeJoueur,int nbJoueur
/*****************Test points***********************************/
    /*
        struct TCarte carte1;
        carte1.num = 1;
        strcpy(carte1.effet,"Lorsque Tete de coyote arrive en jeu, vous pouvez voler le totem d'un joueur et lui donner le votre.");
        carte1.type = 1;
        strcpy(carte1.nom,"Tete de Coyote");

        struct TCarte carte2;
        carte2.num = 2;
        strcpy(carte2.effet,"Lorsque Tete de coyote arrive en jeu, vous pouvez voler le totem d'un joueur et lui donner le votre.");
        carte2.type = 1;
        strcpy(carte2.nom,"Tete de Coyote 2");


        struct TCarte carte3;
        carte3.num = 3;
        strcpy(carte3.effet,"Lorsque Tete de coyote arrive en jeu, vous pouvez voler le totem d'un joueur et lui donner le votre.");
        carte3.type = 1;
        strcpy(carte3.nom,"Tete de Coyote 3");


        TJoueur joueur;
        joueur.id = 1;
        joueur.immunite =0;
        joueur.lynx=0;
        strcpy(joueur.nom, "J1");
        joueur.pion = 1;
        init_pile(&joueur.totem);
        empiler( &joueur.totem,&carte1);
        empiler( &joueur.totem,&carte3);

        TJoueur joueur2;
        joueur2.id = 2;
        joueur2.immunite =0;
        joueur2.lynx=0;
        strcpy(joueur2.nom, "J2");
        joueur2.pion = 2;
        init_pile(&joueur2.totem);
        empiler( &joueur2.totem,&carte2);
        //empiler( &joueur2.totem,&carte3);

        TJoueur listeJoueur[2];
        listeJoueur[0] =joueur;
        listeJoueur[1] =joueur2;


        printf("\n debug avant affiche pile \n");
        afficher_pile(listeJoueur[0].totem);
        printf("\n");
        afficher_pile(listeJoueur[1].totem);
        printf("\n debug apres affiche pile \n");


        initialiser_Points(listeJoueur,2);
        ajout_Points(listeJoueur,2);
        affichage_Points(listeJoueur,2);
        printf("\n debug apres affichage points \n");

        liberer_pile(&listeJoueur[0].totem);
        liberer_pile(&listeJoueur[1].totem);
        printf("\n debug apres liberer totem \n");
    */
/********************Fin test points********************************/
/*****************Test init joueurs***********************************/
/*
        struct TCarte carte1;
        carte1.num = 1;
        strcpy(carte1.effet,"Lorsque Tete de coyote arrive en jeu, vous pouvez voler le totem d'un joueur et lui donner le votre.");
        carte1.type = 1;
        strcpy(carte1.nom,"Tete de Coyote");

        struct TCarte carte2;
        carte2.num = 2;
        strcpy(carte2.effet,"Lorsque Tete de coyote arrive en jeu, vous pouvez voler le totem d'un joueur et lui donner le votre.");
        carte2.type = 1;
        strcpy(carte2.nom,"Tete de Coyote 2");


        struct TCarte carte3;
        carte3.num = 3;
        strcpy(carte3.effet,"Lorsque Tete de coyote arrive en jeu, vous pouvez voler le totem d'un joueur et lui donner le votre.");
        carte3.type = 1;
        strcpy(carte3.nom,"Tete de Coyote 3");

        TPile pioche;

        int nbJoueurs = 0;

        empiler(&pioche,&carte1);
        empiler(&pioche,&carte2);
        empiler(&pioche,&carte3);

        afficher_pile(pioche);

        TJoueur listeJoueur[nbJoueurs];
        init_Joueurs(listeJoueur, nbJoueur);

       // empiler( &listeJoueur[0].totem,&carte3);
        empiler( &listeJoueur[0].totem,&carte1);


        empiler( &listeJoueur[1].totem,&carte2);
        empiler( &listeJoueur[1].totem,&carte3);

        printf("\n debug avant affiche totem \n");
        afficher_pile(listeJoueur[0].totem);
        printf("\n");
        afficher_pile(listeJoueur[1].totem);
        printf("\n debug apres affiche totem \n");



        nettoyage_partie(&listeJoueur,nbJoueur,&pioche);
        printf("\n debug apres nettoyage pioche \n");
*/
/********************Fin init joueurs********************************/
       // Ne pas oublier de libérer la mémoire

      // liberer_pile(&laPioche);


/**MainLudwig**/


/*
//test de toutes les procédures.
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

*/
/**Main Lucas**/


//------------------------------TEST MENU------------------------------
/*  VARIABLES */
/**
    TPile pioche;
    int nbJoueurs;
    int nbCartes = 64;
    int premier = 0;
    int gagneManche;
    int gagnePartie = 0;

    nbJoueurs = saisir_entre(2,6);

    TJoueur listeJoueur[nbJoueurs];


/*  INITIALISATIONS */
/*
    init_Joueurs(listeJoueur, nbJoueurs);

    printf("\n3er test Seg fault\n");

    Distribuer_Cartes(listeJoueur, &pioche, nbCartes ,nbJoueurs);

/*  JEU  */

/*
    do
    {
        //INITIALISATION A CHAQUE DEBUT DE MANCHE

        gagneManche = 0;
        init_pioche(64, nbJoueurs, &pioche);
        Distribuer_Cartes(listeJoueur, &pioche, nbCartes ,nbJoueurs);
        premier = Choix_Premier_Joueur(nbJoueurs);

        printf("%d \n", listeJoueur[premier].id);
        do
        {
            tour_joueur(&listeJoueur[premier-1], &pioche, &gagneManche, &gagnePartie);
            premier = premier +1;
            if(premier == nbJoueurs+1)
            {
                premier = 1;
            }
        }while(gagneManche < 1);

        nettoyage_partie(listeJoueur, nbJoueurs, &pioche);

    }while(gagnePartie < 1);

    nettoyage_partie(listeJoueur, nbJoueurs, &pioche);

*/
