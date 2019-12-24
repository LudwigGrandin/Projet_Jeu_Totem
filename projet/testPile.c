#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libraryProjet.h"


	/* Définition d'une carte */

int main()
{

/**MainLudwig**/


//test de toutes les procédures.
/*    TPile pile;
	init_pile(&pile);
	TCarte carte;
	carte.num = 0;
	int nombreCarte = 2;


	//fflush(stdout);
    //carte0
    //sprintf(carte.nom, "Carte0");
    strcpy(carte.nom, "carte0");
    //gets(carte.nom);
     printf("nom test = %s\n", carte.nom);
    strcpy(carte.effet, "25");
    carte.num = 1;
    empiler(&pile, &carte);
    //carte1
    strcpy(carte.nom,"carte1");
    strcpy(carte.effet, "26");
    carte.num++;
    empiler(&pile, &carte);
    // carte2
    strcpy(carte.nom, "carte2");
    strcpy(carte.effet, "27");
    carte.num ++;
    empiler(&pile, &carte);

    for(int i = 0; i <= nombreCarte; i ++)
    {
        carte = depiler(&pile);
        printf("le num de la carte est %d \n", carte.num);	//verification des données prises par la carte en param
        printf("le nom de la carte est %s \n", carte.nom);
        printf("l effet de la carte est %s \n", carte.effet);
        printf("\n\n");
    }

//	taille = taille_pile(pile);
//	printf("%d", taille);
	liberer_pile(&pile); // libère toute la pile
	//afficher_pile(pile);*/

/**Main Lucas**/

/*
int main(){

    //int taille = 0;
	//struct TPile pile;

//test de toutes les procédures.

	int taille = 0;
	struct TPile pile;
	struct TCarte *cartest;
	init_pile(&pile);
	struct TCarte carte;
	carte.num = 0;
	for(int i = 0; i <= 2; i ++){
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
	cartest = depiler(&pile);
	printf("le num de la carte est %d \n", (*cartest).num);	//verification des données prises par la carte en param
	printf("le num de la carte est %s \n", (*cartest).nom);
	printf("le num de la carte est %s \n", (*cartest).effet);
	afficher_pile(pile);
//	taille = taille_pile(pile);
//	printf("%d", taille);
	liberer_pile(&pile); // libère toute la pile
	afficher_pile(pile);

	*/

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

TCarte depiler(TPile * pile)
{
	int verif;
	TCarte c;
	struct TPilelem *aux;
	TCarte * c;
	c = (TCarte*) malloc(sizeof(TCarte));
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

		strcpy((*c).nom , (*aux).carte.nom);
		strcpy((*c).effet , (*aux).carte.effet);
		(*c).num = (*aux).carte.num;

		//(*c).type = (*aux).type;
		free(aux);
	}
	return c;
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

void liberer_main(TMain * main)
{
	TPilelem *aux;
	aux = (*main).debut;
	
	if((*main).debut == NULL){		
		printf("La liste est vide, rien à supprimer");
	}

	while(aux != NULL){
	
		(*main).debut = (*aux).suivant;
		free(aux);
		aux = (*main).debut;
	}
}

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

}

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

}
*/



