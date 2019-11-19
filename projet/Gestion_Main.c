#include <stdio.h>
#include <stdlib.h>

typedef struct Tcellule
{
	TCarte cartes;
	struct Tcellule * suivant;
} Tcellule;

typedef struct TCarte
{
	char nom[100];
	int num;
	char effet[100];
	int type;

} TCarte;

typedef struct TMain
{
	TCellule debut;

} TMain;



void piocher(TMain mainJoueur, TPile pile)
{
    Tcellule *aux = mainJoueur.debut;
    Tcellule *prec = mainJoueur.debut;
    Tcellule *newCell;

    aux = mainJoueur;

    while(aux != NULL)
    {
        prec = aux;
        aux = (*aux).suivant;
    }

    (*newCell).cartes = depiler(pile); //Mettre depiler C
    (*prec).suivant = newCell;
    (*newCell).suivant = aux;
}

void DeposerCarteTotem(TPile totem,TMain *mainJoueur ,int IDCarte)
{
    int trouve = 0;
    Tcellule *aux =  (*mainJoueur).debut;
    Tcellule *prec =  (*mainJoueur).debut;

    while(aux != NULL && trouve == 0 )
    {
        if( (*aux).cartes.num  == IDCarte)
        {
            //si la carte est une tête
            if((*aux).cartes.type = 1)
            {
                trouve = 1;
                empiler()
            }


       }
       prec = aux;
       aux = (*aux).suivant;
    }

}

void JouerCarteCoupBas(Tcellule *mainJoueur, TPile pile, )
{

}



