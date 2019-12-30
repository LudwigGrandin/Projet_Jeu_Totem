#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "libraryProjet.h"

void Distribuer_Cartes(TJoueur *listeJoueur, TPile *listeCartes, int nbCartes, int nbJoueur)
{
    int nbCartesLocales,nbJoueurLocal = 0;
    TPilelem *aux;
    TPilelem *newCell;

    for (nbJoueurLocal = 0; nbJoueurLocal < nbJoueur; nbJoueurLocal ++)
    {

        listeJoueur[nbJoueurLocal].main.debut = (TPilelem*) malloc(sizeof(TPilelem));
        //On met l'adresse de la 1ere carte dans aux
        aux = listeJoueur[nbJoueurLocal].main.debut;
        //On tire la 1ere carte pour le 1er emplacement
        (*aux).carte = (*(*listeCartes).sommet).carte;

        depiler(listeCartes);

        for(nbCartesLocales = 0; nbCartesLocales < 5; nbCartesLocales ++)
        {
            newCell = (TPilelem*) malloc(sizeof(TPilelem));
            (*newCell).carte = (*(*listeCartes).sommet).carte;
            depiler(listeCartes);

            (*aux).suivant = newCell;
             aux = (*aux).suivant;
             (*aux).suivant = NULL;
        }
    }
}


int Choix_Premier_Joueur(int nbJoueur)
{
    srand(time(NULL));
	return rand()%nbJoueur+1;
}


