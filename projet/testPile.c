#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libraryProjet.h"


int main(){

/**MainLudwig**/

/**Main Lucas**/
//test de toutes les procédures.


	//int taille = 0;
/*	struct TPile pile;
	init_pile(&pile);
	struct TCarte carte;
	struct TCarte cartest;
	carte.num = 0;
	for(int i = 0; i <= 2; i ++){				// saisie des données à la main pour tester empiler
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
	struct TCarte *aux;
	struct TCarte *newC;

	newC = (TCarte*) malloc(sizeof(TCarte));
	strcpy((*newC).nom , (*c).nom);
	strcpy((*newC).effet , (*c).effet);
	(*newC).num = (*c).num;
	(*newC).type = (*c).type;

	aux = (*pile).sommet;
	(*newC).suivant = (*pile).sommet;
	(*pile).sommet = newC;
}

void depiler(TPile * pile, TCarte * c)
{
	int verif;
	struct TCarte *aux;
	verif = est_pile_vide(*pile);

	aux = (*pile).sommet;

	strcpy((*c).nom , (*aux).nom);
	strcpy((*c).effet , (*aux).effet);
	(*c).num = (*aux).num;
	(*c).type = (*aux).type;

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
	struct TCarte *aux;
	int verif;

	verif = est_pile_vide(pile);
	aux = pile.sommet;
	if(verif == 1)
	{
		printf("La pile est vide, rien à afficher \n");
	}
		while(aux != NULL)
	{
		printf("[%d]", (*aux).num);
		printf("[%s]", (*aux).nom);
		aux = (*aux).suivant;
	}
}

int taille_pile(TPile pile)
{
	struct TCarte *aux;
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

void liberer_pile(TPile * pile, TCarte * c)
{

	int verif;
	verif = est_pile_vide(*pile);

	while(verif == 0){
		depiler(pile, c);
		verif = est_pile_vide(*pile);
	}
}

/*
void supprimer_carte_totem(TPile * pile, TMain * main, int num)
{


}


//effet cartes
void tete_coyote(TJoueur * j1, TJoueur * j2, TJoueur * jint) // créer un joueur jint dans le main ?
{

	(*jint).totem = (*j1).totem;
	(*j1).totem = (*j2).totem;
	(*j2).totem = (*jint).totem;

}

void cadeau(TPile * totem1, TPile * totem2)
{
	struct TCarte *aux;

	depiler(totem2);

	empiler(totem1, (*(*totem2).sommet).carte);

}

//suivant la carte que le joueur joue
void immunite_totem(TJoueur * j)
{


}



void DeposerCarteTotem(TPile *totem,TMain *mainJoueur ,int IDCarte)
{
    int trouve = 0;
    TCarte *aux =  (*mainJoueur).debut;
    TCarte *prec =  (*mainJoueur).debut;

    while(aux != NULL && trouve == 0 )
    {
        if( (*aux).carte.num  == IDCarte)
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

}
*/
