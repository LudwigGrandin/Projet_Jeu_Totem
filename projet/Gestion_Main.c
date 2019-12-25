#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libraryProjet.h"

void piocher(TMain *mainJoueur, TPile *pile)
{

    TPilelem *aux;
    TPilelem *prec;
    TPilelem *newCell;



    //ALLOUER NewCell
    newCell = (TPilelem*) malloc(sizeof(TPilelem));

    aux = (*mainJoueur).debut;
    prec = (*mainJoueur).debut;

    //Si main vide
   if(est_pile_vide(*pile) != 1)
    {

        while(aux != NULL)
        {
            prec = aux;
            aux = (*aux).suivant;
        }

        //Piocher la carte en haut de la pile

        (*newCell).carte = depiler(pile);

        //Si mainVide
        if(aux == prec)
        {
            (*newCell).suivant = (*mainJoueur).debut;
            (*mainJoueur).debut = newCell;

        }
        else
        {
            (*prec).suivant = newCell;
            (*newCell).suivant = aux;
        }
    }
    else
    {
        printf("il n y a plus de cartes dans la pioche\n");
    }

}


void DeposerCarte(TPile *totem, int numCarteMain, TMain *mainJoueur)
{
    TCarte carte;

    //On récupère l'adresse dans la liste chainée de la carte que le joueur veut jouer
    carte = Retrait_Carte_Main(mainJoueur,numCarteMain);

    //Il faut désallouer l'emplacement qui a été supprimé de la main
    //Si c'est une carte totem alors on l'ajoute à la pile totem
    if(carte.type == 1)
    {
        empiler(totem,&carte);
    }
    else
    {

    }
}

//Fonction Permettant de récupérer l'adresse d'une carte contenue dans la liste chaînée de la main
TCarte Retrait_Carte_Main(TMain *main, int numCarteMain)
{
    int trouve = 0, compteur = 1;

    TCarte carte;
    TPilelem *aux;
    TPilelem *prec;

    aux = (*main).debut;
    prec = (*main).debut;

    carte.type=0;



    while(aux != NULL && trouve == 0)
    {

        if(compteur == numCarteMain)
        {
            trouve = 1;
        }
        else
        {
            prec = aux;
            aux = (*aux).suivant;

            compteur ++;
        }
    }

    if(trouve == 1)
    {
        carte.num = (*aux).carte.num;
        strcpy(carte.nom,(*aux).carte.nom);
        strcpy(carte.effet,(*aux).carte.effet);
        carte.type = (*aux).carte.type;

        (*prec).suivant=(*aux).suivant;
        free(aux);
    }

    return carte;

}

void Afficher_Main(TMain *mainJoueur)
{

    TPilelem *aux;
    aux = (*mainJoueur).debut;

    if(mainJoueur == NULL)
    {
        printf("vous n'avez pas de cartes en main");
    }
    else
    {
        while(aux != NULL)
        {
            printf("\n\n");
            printf("carte num = %d\n", (*aux).carte.num);
            printf("carte nom = %s\n", (*aux).carte.nom);
            printf("carte effet = %s\n", (*aux).carte.effet);
            //Problème pour l'affichage du type
            printf("carte type = %d\n", (*aux).carte.type);
            printf("\n\n");

            aux = (*aux).suivant;
        }
    }

}

void JouerCarteCoupBas(TCarte carte, TPile pile)
{
    //Montrer la carte à jouer
    printf("La carte jouee est : %s ",carte.nom);
    //Plusieurs actions possibles:

    //Carte
    //On arrive
    //Et paf
    //Esprit Farceur
    //Bison Dingo
    //Faux PAs
    //Pillage
    //Eau de Feu
    if(strcmp(carte.nom,"OnArrive"))
    {

    }
    else if(strcmp(carte.nom,"EspritFarceur"))
    {

    }
    else if(strcmp(carte.nom,"BisonDingo"))
    {

    }
    else if(strcmp(carte.nom,"FauxPas"))
    {

    }
    else if(strcmp(carte.nom,"Pillage"))
    {

    }
    else if(strcmp(carte.nom,"EaudeFeu"))
    {

    }


}



