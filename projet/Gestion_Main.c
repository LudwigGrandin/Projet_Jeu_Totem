#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libraryProjet.h"

void piocher(TMain *mainJoueur, TPile *pile, TCarte *carte)
{

    TPilelem *aux;
    TPilelem *prec;
    TPilelem *newCell;

    newCell = (TPilelem*) malloc(sizeof(TPilelem));

    (*newCell).suivant = NULL;
    aux = (*mainJoueur).debut;
    prec = (*mainJoueur).debut;

    while(aux != NULL)
    {
        prec = aux;
        aux = (*aux).suivant;
    }

    //On tire une nouvelle carte

    //(*newCell).carte = (*(*pile).sommet).carte;  //On met la carte en haut de la pioche dans newCell
     (*newCell).carte = depiler(pile);
     printf("test1");
    (*prec).suivant = newCell;
    (*newCell).suivant = aux;

    *carte = depiler(&pile);//La pile ne devrait elle pas renvoyer un TPileElem?????
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
    //Si c'est une carte totem alors on l'ajoute à la pile totem
    if((*emplacementCarteActuelle).carte.type == 1)
    {
        empiler(&totem,&carte);
    }
}

//Fonction Permetta,t de récupérer l'adresse d'une carte contenue dans la liste chaînée de la main
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

    while(aux != NULL)
    {
        printf("crate num = %d\n", (*aux).carte.num);
        printf("carte nom = %s\n", (*aux).carte.nom);
        printf("carte effet = %s\n", (*aux).carte.effet);
        printf("carte type = %d\n", (*aux).carte.type);

        aux = (*aux).suivant;
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



