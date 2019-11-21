#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libraryProjet.h"


	/* Définition d'une carte */



int main(){

	struct TPile pile;
	pile.sommet = NULL;
}

int est_pile_vide(TPile * pile)
{
	if((*pile).sommet == NULL)
		return 1;

	return 0;
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

	verif = est_pile_vide(pile);

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
	verif = est_pile_vide(pile);

	aux = (*pile).sommet;
	if(verif == 1) // la pile est vide
	{
		printf("Rien à dépiler, la pile est vide");
	}
	else
	{
		(*pile).sommet = (*aux).suivant;
		free(aux);
	}

}
