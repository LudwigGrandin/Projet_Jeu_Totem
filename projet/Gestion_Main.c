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
        printf("nom Carte : %s \n", (*newCell).carte.nom);
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


void DeposerCarteTotem(TPile totem, int numCarteMain, TMain *main)
{
    TPilelem *emplacementCartePrecedente;
    TPilelem *emplacementCarteActuelle;
    TCarte carte;

    //On r�cup�re l'adresse dans la liste chain�e de la carte que le joueur veut jouer
     choix_Emplacement_Carte_Main(main,numCarteMain,emplacementCartePrecedente,emplacementCarteActuelle);
    //Supprime la carte de la main du joueur
    (*emplacementCartePrecedente).suivant = (*emplacementCarteActuelle).suivant;
    //Sauvegarde de la carte de la main
    carte = (*emplacementCarteActuelle).carte;
    //Il faut d�sallouer l'emplacement qui a �t� supprim� de la main
    //Si c'est une carte totem alors on l'ajoute � la pile totem
    if((*emplacementCarteActuelle).carte.type == 1)
    {
        empiler(&totem,&carte);
    }
}

//Fonction Permetta,t de r�cup�rer l'adresse d'une carte contenue dans la liste cha�n�e de la main
void choix_Emplacement_Carte_Main(TMain *main, int numCarteMain, TCarte *emplacementCartePrecedente,TCarte *emplacementCarteActuelle)
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

void Afficher_Main(TMain *mainJoueur)
{

    TPilelem *aux;
    aux = (*mainJoueur).debut;

    if(mainJoueur == NULL)
    {
        printf("vous n'avez pas de cartes en main");
    }

    while(aux != NULL)
    {
        printf("\n\n");
        printf("carte num = %d\n", (*aux).carte.num);
        printf("carte nom = %s\n", (*aux).carte.nom);
        printf("carte effet = %s\n", (*aux).carte.effet);
        //Probl�me pour l'affichage du type
        printf("carte type = %d\n", (*aux).carte.type);
        printf("\n\n");

        aux = (*aux).suivant;
    }

}

void JouerCarteCoupBas(TCarte carte, TPile pile)
{
    //Montrer la carte � jouer
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



