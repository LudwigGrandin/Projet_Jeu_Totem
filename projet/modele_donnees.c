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
	int pion;
	int points;
	int immunite;//Permet d'empecher de se faire voler son totem. Bool?n
} TJoueur;
