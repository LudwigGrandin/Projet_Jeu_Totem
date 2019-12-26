#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libraryProjet.h"

void Distribuer_Cartes(TJoueur *listeJoueur, TPile *listeCartes, int nbCartes, int nbJoueur)
{
    int nbCartesLocales,nbJoueurLocal = 0;
    TPilelem *aux;

    for (nbJoueurLocal = 0; nbJoueurLocal < nbJoueur; nbJoueurLocal ++)
    {

        listeJoueur[nbJoueurLocal].main.debut = (TPilelem*) malloc(sizeof(TPilelem));
        aux = listeJoueur[nbJoueurLocal].main.debut;


        for(nbCartesLocales = 0; nbCartesLocales < 5; nbCartesLocales ++)
        {

            (*aux).carte = (*(*listeCartes).sommet).carte;
            printf("test");
            depiler(listeCartes);
            aux = (*aux).suivant;
        }
    }
/*
    for (nbJoueurLocal = 0; nbJoueurLocal < nbJoueur; nbJoueurLocal ++)
    {
        aux = listeJoueur[nbJoueurLocal].main.debut;
        printf("Joueur : %s\n", listeJoueur[nbJoueurLocal].nom);

        //Afficher_Main(listeJoueur[nbJoueurLocal].main);
    }
*/
}
