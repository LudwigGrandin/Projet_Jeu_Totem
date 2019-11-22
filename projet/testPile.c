#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libraryProjet.h"


	/* Définition d'une carte */



int main(){

	struct TPile pile;
	pile.sommet = NULL;
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


void empiler(TPile * pile, TCarte c)
{
	int verif;
	struct TPilelem *aux;
	struct TPilelem *newC;

	newC = malloc(sizeof(*newC));
	strcpy((*newC).carte.nom , c.nom);
	strcpy((*newC).carte.effet , c.effet);
	(*newC).carte.num = c.num;
	(*newC).carte.type = c.type;

	verif = est_pile_vide(*pile);

	aux = (*pile).sommet;
	if(verif == 1) // la pile est vide
	{
		(*pile).sommet = newC;
	}
	else{
		(*newC).suivant = aux;
		(*pile).sommet = newC;
	}
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
		while(verif == 0)
	{
		printf("[%d]\n", (*aux).carte.num);
		aux = (*aux).suivant;
		verif = est_pile_vide(pile);
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
		while(verif == 0)
	{
		taille++;
		aux = (*aux).suivant;
		verif = est_pile_vide(pile);
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