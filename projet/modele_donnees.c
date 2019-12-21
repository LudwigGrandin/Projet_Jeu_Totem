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
	struct TCarte *suivant;
} TCarte;

typedef struct TPile
{
	TCarte *sommet;
}TPile;

/*typedef struct Tcellule Tcellule;
typedef struct Tcellule
{
	TCarte cartes;
    Tcellule *suivant;
} Tcellule;*/


typedef struct TMain
{
	TCarte *debut;

} TMain;

typedef struct TJoueur
{
	TPile totem;
	TMain main;
	int pion;
	int points;
} TJoueur;
