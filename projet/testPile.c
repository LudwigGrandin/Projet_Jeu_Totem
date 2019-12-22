#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libraryProjet.h"


	/* Définition d'une carte */


/**MainLudwig**/
/*

//test de toutes les procédures.
    TPile pile;
	init_pile(&pile);
	TCarte carte;
	carte.num = 0;
	int nombreCarte = 2;

	//fflush(stdout);
    /** carte0 **/
/*    (*carte.nom) = "Carte0";
    printf("nom test = %s\n", (&carte.nom));
    (*carte.effet) = "25";
    carte.num = 1;
    empiler(&pile, &carte);
    /** carte1 **/
 /*   (*carte.nom) = "carte1";
    (*carte.effet) = "26";
    carte.num++;
    empiler(&pile, &carte);
    /** carte2 **/
/*    (*carte.nom) = "carte2";
    (*carte.effet) = "27";
    carte.num ++;
    empiler(&pile, &carte);*/


	/*for(int i = 0; i <= nombreCarte; i ++){				// saisie des données à la main pour tester empiler

		printf("Carte numéro : %d \n",i);

		printf("Entrer un nom de carte \n");
		fflush(stdout);
		scanf("%s", carte.nom);

		printf("Entrer un effet de carte \n");
		fflush(stdout);
		scanf("%s", carte.effet);

		carte.num++;
		carte.type = 1;

		empiler(&pile, &carte);
	}*/
	//afficher_pile(pile);
    //system("cls");
    //affiche la pile avant depiler

    //char nom[1000] = "";
/*    for(int i = 0; i <= nombreCarte; i ++)
    {
        //depiler(&pile, &carte);
       // nom = (*carte).(*nom);
        printf("le num de la carte est %d \n", carte.num);	//verification des données prises par la carte en param
        printf("le nom de la carte est %s \n", carte.nom);
        printf("l effet de la carte est %d \n", carte.effet);
        printf("\n\n");
    }

//	taille = taille_pile(pile);
//	printf("%d", taille);
	liberer_pile(&pile, &carte); // libère toute la pile
	//afficher_pile(pile);*/

/**Main Lucas**/





int main(){

    //int taille = 0;
	//struct TPile pile;

//test de toutes les procédures.
/*
	int taille = 0;
	struct TPile pile;

	init_pile(&pile);
	struct TCarte carte;
	carte.num = 0;
	for(int i = 0; i <= 3; i ++){
		printf("Entrer un nom de carte \n");
		fflush(stdout);
		scanf("%s", carte.nom);

		printf("Entrer un effet de carte \n");
		fflush(stdout);
		scanf("%s", carte.effet);

		carte.num++;
		carte.type = 1;

		empiler(&pile, &carte);
	}

	afficher_pile(pile);		//affiche la pile avant depiler
	depiler(&pile, &cartest);
	printf("le num de la carte est %d \n", cartest.num);	//verification des données prises par la carte en param
	printf("le num de la carte est %s \n", cartest.nom);
	printf("le num de la carte est %s \n", cartest.effet);
//	taille = taille_pile(pile);
//	printf("%d", taille);
	liberer_pile(&pile, &cartest); // libère toute la pile
	afficher_pile(pile);*/

	return 0;
}

/*	afficher_pile(pile);
	taille = taille_pile(pile);
	printf("%d", taille);
	liberer_pile(&pile);
	afficher_pile(pile);*/

//	return 0;
//}

int est_pile_vide(TPile pile)
{
	int verif = 0;
	if(pile.sommet == NULL){
		verif = 1;
		return verif;
	}

	return verif;
}


void empiler(TPile * pile, TCarte * c)
{
	struct TPilelem *aux;
	struct TPilelem *newC;

	newC = (TPilelem*) malloc(sizeof(TPilelem));
	strcpy((*newC).carte.nom , (*c).nom);
	strcpy((*newC).carte.effet , (*c).effet);
	(*newC).carte.num = (*c).num;
	(*newC).carte.type = (*c).type;

	aux = (*pile).sommet;
	(*newC).suivant = (*pile).sommet;
	(*pile).sommet = newC;
}

void depiler(TPile * pile)
{
	int verif;
	struct TPilelem *aux;
	verif = est_pile_vide(*pile);

	aux = (*pile).sommet;
	if(verif == 1) // la pile est vide
	{
		printf("Rien à dépiler, la pile est vide \n");
	}
	else
	{
		(*pile).sommet = (*aux).suivant;
		free(aux);
	}

}

void init_pile(TPile * pile)
{
	(*pile).sommet = NULL;

}

void afficher_pile(TPile pile)
{
	struct TPilelem *aux;
	int verif;

	verif = est_pile_vide(pile);
	aux = pile.sommet;
	if(verif == 1)
	{
		printf("La pile est vide, rien à afficher \n");
	}
		while(aux != NULL)
	{
		printf("[%d]\n", (*aux).carte.num);
		aux = (*aux).suivant;
	}
}

int taille_pile(TPile pile)
{
	struct TPilelem *aux;
	int verif;
	int taille = 0;

	verif = est_pile_vide(pile);
	aux = pile.sommet;
	if(verif == 1)
	{
		taille = 0;
	}
		while(aux != NULL)
	{
		taille++;
		aux = (*aux).suivant;
	}
	return taille;
}

void liberer_pile(TPile * pile)
{

	int verif;
	verif = est_pile_vide(*pile);

	while(verif == 0){
		depiler(pile);
		verif = est_pile_vide(*pile);
	}
}

void ajout_totem(TPile * pile, TMain * main)
{


}



//effet cartes
void tete_coyote(TJoueur * j1, TJoueur * j2, TJoueur * jint) // créer un joueur jint dans le main ?
{

	(*jint).totem = (*j1).totem;
	(*j1).totem = (*j2).totem;
	(*j2).totem = (*jint).totem;

}

/*void cadeau(TPile * totem1, TPile * totem2)
{
	struct TCarte *aux;

	depiler(totem2);

	empiler(totem1, (*(*totem2).sommet).carte);

}*/

//suivant la carte que le joueur joue
void immunite_totem(TJoueur * j)
{


}



/*void DeposerCarteTotem(TPile totem, int numCarteMain, TMain *mainJoueur)
{
    int trouve = 0;
    TPilelem *aux;
    TPilelem *prec;

    aux =  (*mainJoueur).debut;
    prec = (*mainJoueur).debut;

    while(aux != NULL && trouve == 0 )
    {
        if( (*aux).carte.num  == )
        {
            //si la carte est une tête
            if((*aux).carte.type = 1)
            {
                trouve = 1;
                empiler(*totem, aux);
            }


       }
       prec = aux;
       aux = (*aux).suivant;
    }

}*/



