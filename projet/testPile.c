#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libraryProjet.h"


	/* Définition d'une carte */



/*int main(){

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
	afficher_pile(pile);
	taille = taille_pile(pile);
	printf("%d", taille);
	liberer_pile(&pile);
	afficher_pile(pile);
*/
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
