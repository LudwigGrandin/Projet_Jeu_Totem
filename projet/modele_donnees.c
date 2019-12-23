#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//modele
typedef struct TCarte
{
	char nom[100];
	char effet[100];
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



/*typedef struct Tcellule Tcellule;
typedef struct Tcellule
{
	TCarte cartes;
    Tcellule *suivant;
} Tcellule;*/


typedef struct TMain
{
	TPilelem *debut;

} TMain;

typedef struct TJoueur
{
	TPile totem;
	TMain main;
	int pion;
	int points;
} TJoueur;
