#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libraryProjet.h"
	/* Définition d'une carte */

int main(){

	struct TPilelem p;
}

int est_pile_vide(TPile p)
{
	if(p == NULL)
		return 1;

	return 0;
}

//test commit

//test merge

void empiler(TPile p, TCarte c)
{
	int verif;
	struct TPilelem *aux;
	struct TPilelem *newC;

	newC = malloc(sizeof(*newC));
	strcpy((*newC).carte.nom , c.nom);
	strcpy((*newC).carte.effet , c.effet);
	(*newC).carte.num = c.num;
	(*newC).carte.type = c.type;

	verif = est_pile_vide(p);

	aux = p;
	if(verif == 1) // la pile est vide
	{
		p = newC;
	}
	else{
		p = (*aux).suivant;
		aux = newC;
	}
}

void depiler(TPile p)
{
	int verif;
	struct TPilelem *aux;
	verif = est_pile_vide(p);

	aux = p;
	if(verif == 1) // la pile est vide
	{
		printf("Rien à dépiler, la pile est vide");
	}
	else
	{
		p = (*aux).suivant;
		free(aux);
	}

}
