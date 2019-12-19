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

    //On récupère l'adresse dans la liste chainée de la carte que le joueur veut jouer
     choix_Emplacement_Carte_Main(main,numCarteMain,emplacementCartePrecedente,emplacementCarteActuelle);
    //Supprime la carte de la main du joueur
    (*emplacementCartePrecedente).suivant = (*emplacementCarteActuelle).suivant;
    //Sauvegarde de la carte de la main
    carte = (*emplacementCarteActuelle).carte;
    //Il faut désallouer l'emplacement qui a été supprimé de la main
    if((*emplacementCarteActuelle).carte.type == 1)
    {
        empiler(&totem,&carte);
    }
}

//Fonction Permetta,t de récupérer l'adresse d'une carte contenue dans la liste chaînée de la main
void  choix_Emplacement_Carte_Main(TMain *main, int numCarteMain, TPilelem *emplacementCartePrecedente,TPilelem *emplacementCarteActuelle)
{
    int trouve = 0, compteur = 1;
    TPilelem *aux;
    aux = (*main).debut;
    emplacementCartePrecedente = (*main).debut;

    while(aux != NULL && trouve == 0)
    {
        if(compteur == numCarteMain)
        {
            trouve = 1;
        }
        else
        {
            emplacementCartePrecedente = aux;
            aux = (*aux).suivant;
            compteur ++;
        }
    }

}

void JouerCarteCoupBas(TCarte Carte_Joue, TPile pile)
{

}



