#include <stdio.h>
#include <stdlib.h>
#include "libraryProjet.h"



void piocher(TMain mainJoueur, TPile pile)
{
    TPilelem *aux = mainJoueur.debut;
    TPilelem *prec = mainJoueur.debut;
    TPilelem *newCell;

    aux = mainJoueur.debut;

    while(aux != NULL)
    {
        prec = aux;
        aux = (*aux).suivant;
    }

    depiler(&pile);
    (*newCell).carte = (*pile.sommet).carte;  //Mettre depiler C
    (*prec).suivant = newCell;
    (*newCell).suivant = aux;
}


void DeposerCarteTotem(TPile totem, int numCarteMain, TMain *main)
{
    TPilelem *emplacementCartePrecedente;
    TPilelem *emplacementCarteActuelle;
    TCarte carte;

    emplacementCarteActuelle = choix_Carte_Main(main,&numCarteMain,emplacementCartePrecedente);
    (*emplacementCartePrecedente).suivant = (*emplacementCarteActuelle).suivant;

    carte = (*emplacementCarteActuelle).carte;

    if((*emplacementCarteActuelle).carte.type == 1)
    {
        empiler(&totem,&carte);
    }
}


TPilelem choix_Emplacement_Carte_Main(TMain *main, int numCarteMain, TPilelem *emplacementCartePrecedente)
{
    int trouve = 0, compteur = 1;
    TPilelem aux;
    aux = (*main).debut;
    emplacementCartePrecedente = (*main).debut;

    while(aux != null && trouve==0)
    {
        if(compteur == numCarteMain)
        {
            trouve = 1;
        }
        else
        {
            prec = aux;
            aux = (aux).suivant;
            compteur ++;
        }
    }

return aux;

}

void JouerCarteCoupBas(TCarte Carte_Joue, TPile pile)
{

}



