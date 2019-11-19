#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//modele
typedef struct TCarte
{
	char nom[30];
	char effet[100];
	int num;
	int type; 
}TCarte;

typedef struct TPilelem
{
	TCarte carte;
	struct TPileElem *suivant;
	struct TPileElem *premier;
}TPilelem, *TPile;