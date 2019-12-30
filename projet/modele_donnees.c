#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//modele
typedef struct TCarte
{
	char nom[100];
	char effet[200];
	int num;
	int type;
} TCarte;

typedef struct TPilelem
{
	TCarte carte;
	struct TPilelem *suivant;
}TPilelem;


typedef struct TPile
{
	TPilelem *sommet;
}TPile;


typedef struct TMain
{
	TPilelem *debut;
} TMain;

typedef struct TJoueur
{
	int id;
	char nom[20];
	TPile totem;
	TMain main;
	int points;
	int immunite;//Permet d'empecher de se faire voler ou detruire son totem. immunité =0 : pas d'immunité ; immunité = 2 : contre vol; immunité = 1 : contre destruction
	int lynx;//Permet de piocher 3 carte et d'en chosir une à la fin de chaque tour. C'est un booleen
	int rejouer;//Variable qui définit qui peut jouer
} TJoueur;
