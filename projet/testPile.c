#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libraryProjet.h"

	/* Définition d'une carte */

int main()
{

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

	TJoueur listeJoueur[10];
	int nbCarte = 64;
	int nbJoueur = 2;

	TMain mainJoueur;
	mainJoueur.debut = (TPilelem*) malloc(sizeof(TPilelem));
	mainJoueur.debut = NULL;

	listeJoueur[0].id = 1;
	strcpy(listeJoueur[0].nom, "jackie");

	listeJoueur[1].id = 2;
	strcpy(listeJoueur[1].nom,"Michel");

	listeJoueur[2].id = 3;
	strcpy(listeJoueur[2].nom, "Louisa");


	//fflush(stdout);
    //carte0
    strcpy(carte.nom,"carte1");
    strcpy(carte.effet, "21");
    carte.num = 1;
    carte.type = 1;
    empiler(&pile, &carte);

    //printf("carte.nom=%s\n",(*pile.sommet).carte.nom);
    //carte1
    strcpy(carte.nom,"carte2");
    strcpy(carte.effet, "22");
    carte.num = 2;
    carte.type = 1;
    empiler(&pile, &carte);

   // printf("carte.nom=%s\n",(*pile.sommet).carte.nom);
    // carte2
    strcpy(carte.nom, "carte3");
    strcpy(carte.effet, "23");
    carte.num = 3;
    carte.type = 1;
    empiler(&pile, &carte);

    Distribuer_Cartes(listeJoueur,&pile,nbCarte,nbJoueur);

//   init_ListeCarte(listeCarte, nbCarte, nbJoueur);
//   afficherCartes(&listeCarte,nbCarte);


/*    printf("\n");
    printf("pioche Carte 3 : carte.type = %d\n", (*pile.sommet).carte.type);
    printf("appel de la fonction piocher\n");
    piocher(&mainJoueur,&pile);
    printf("appel de la fonction Afficher Main \n");
    printf("mainJoueur Carte 1 : carte.type = %d", (*mainJoueur.debut).carte.type);
    Afficher_Main(&mainJoueur);
    printf("\n");

    printf("appel de la fonction piocher\n");
    piocher(&mainJoueur,&pile);
    printf("appel de la fonction Afficher Main \n");
    Afficher_Main(&mainJoueur);
    printf("\n");

    printf("appel de la fonction Totem\n");
    DeposerCarte(&totem,1,&mainJoueur);
    DeposerCarte(&totem,2,&mainJoueur);
    printf("appel de la fonction afficher pile\n");
    afficher_pile(totem);
    printf("\n");*/
/*
    liberer_main(&mainJoueur);
	liberer_pile(&pile); // libère toute la pile
*/

/**Main Lucas**/

/*
//Pas besoin d'avoir de main ici, décommente juste ta partie. Le début du main est tout ne haut
int main(){

    //int taille = 0;
	//struct TPile pile;

//test de toutes les procédures.

	int taille = 0;
	struct TPile pile;
	struct TCarte cartest;
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
	printf("le num de la carte est %d \n", cartest.num);	//verification des données prises par la carte en param
	printf("le num de la carte est %s \n", cartest.nom);
	printf("le num de la carte est %s \n", cartest.effet);
	afficher_pile(pile);
//	taille = taille_pile(pile);
//	printf("%d", taille);
	liberer_pile(&pile); // libère toute la pile
	afficher_pile(pile);

*/

//Ne commente pas le return ici, c'est la fin du main(peu importe si c'est celui de ludwig, lucas ou killian
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
	TPilelem *aux;

    //On vérifie si la pile est vide
	verif = est_pile_vide(*pile);

	aux = (*pile).sommet;


	if(verif == 1) // la pile est vide
	{
		printf("Rien à dépiler, la pile est vide \n");
	}
	else
	{
	   (*pile).sommet = (*aux).suivant;

		strcpy(c.nom , (*aux).carte.nom);
		strcpy(c.effet , (*aux).carte.effet);
		c.num = (*aux).carte.num;
		c.type = (*aux).carte.type;

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
	else
    {
        while(aux != NULL)
        {
            printf("[%d] -- %s\n", (*aux).carte.num, (*aux).carte.nom);
            aux = (*aux).suivant;
        }
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

	if(aux == NULL){
		printf("La liste est vide, rien à supprimer");
	}

	while(aux != NULL){

		(*main).debut = (*aux).suivant;
		free(aux);
		aux = (*main).debut;
	}
}

/*
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
*/


