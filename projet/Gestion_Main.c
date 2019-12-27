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

        (*newCell).carte = (*(*pile).sommet).carte;
        depiler(pile);

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

    if((*main).debut == NULL)
    {
        printf("Votre main est vide !\n");
    }
    else
    {

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
    }
    return carte;

}

void Afficher_Main(TMain mainJoueur)
{

    TPilelem *aux;
    aux = mainJoueur.debut;

    if(aux == NULL)
    {
        printf("vous n'avez pas de cartes en main");
    }
    else
    {
        while(aux != NULL)
        {
            printf("\n");
            printf("carte num = %d\n", (*aux).carte.num);
            printf("carte nom = %s\n", (*aux).carte.nom);
            printf("carte effet = %s\n", (*aux).carte.effet);
            printf("carte type = %d\n", (*aux).carte.type);
            printf("\n");

            aux = (*aux).suivant;
        }
    }

}

void JouerCarteCoupBas(TCarte carte, TPile *pioche ,TJoueur *joueurQuiJoue, TJoueur *joueurCible, TJoueur listeJoueur)
{
    int i =0;
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
    if(strcmp(carte.nom,"OnArrive") == 0)
    {

    }
    else if(strcmp(carte.nom,"EtPaf") == 0)
    {
        if((*joueurCible).immunite == 1)    // Attention à bien distinguer vol et destruction de totem, je pensais à protection contre le vol quand immunite = 2 / protection contre la destruction immunite = 1
        {
            printf("Ce joueur est invicible pour l'instant");
        }
        else
        {
            //Destruction du totem adverse
            depiler((*joueurCible).totem.sommet);
        }
    }
    else if(strcmp(carte.nom,"EspritFarceur") == 0)
    {
        Donner_Totem_Vers_Voisin_Gauche(listeJoueur);
    }
    else if(strcmp(carte.nom,"BisonDingo") == 0)
    {


        for(i=0; i<2;i++)
        {
            depiler((*joueurCible).totem.sommet);
        }
    }
    else if(strcmp(carte.nom,"FauxPas") == 0)
    {

    }
    else if(strcmp(carte.nom,"Pillage") == 0)
    {

    }
    else if(strcmp(carte.nom,"EaudeFeu") == 0)
    {
        for(i=0; i<2;i++)
        {//Voir pour le pointeur
            // piocher((*joueurQuiJoue.main),pioche);
        }

    }


}

void Defausser_Carte(TMain *mainJoueur, int numCarte)
{
    Retrait_Carte_Main(mainJoueur,numCarte);
}

void Donner_Main_Vers_Voisin_Gauche(TJoueur *listeJoueur, int nbJoueur)
{
    int nbJoueurLocal;
    TPile totemJoueur0;

    totemJoueur0 = listeJoueur[0].totem;

    for(nbJoueurLocal = 0; nbJoueurLocal < nbJoueur; nbJoueurLocal ++)
    {
            listeJoueur[nbJoueurLocal].totem = listeJoueur[nbJoueurLocal+1].totem;
    }

    listeJoueur[nbJoueur].totem = totemJoueur0;
}

void Donner_Totem_Vers_Voisin_Gauche(TJoueur *listeJoueur, int nbJoueur)
{
    int nbJoueurLocal;
    TMain mainJoueur0;

    mainJoueur0 = listeJoueur[0].main;

    for(nbJoueurLocal = 0; nbJoueurLocal < nbJoueur; nbJoueurLocal ++)
    {
            listeJoueur[nbJoueurLocal].main = listeJoueur[nbJoueurLocal+1].main;
    }

    listeJoueur[nbJoueur].main = mainJoueur0;

}


void tete_coyote(TJoueur * j1, TJoueur * j2) // échange les totems de 2 joueurs
{
    TPile totemint;
    totemint = (*j1).totem;
    (*j1).totem = (*j2).totem;
    (*j2).totem = totemint;

}

void tete_corbeau(TJoueur * j1, TJoueur * j2) // échange les totems de 2 joueurs
{
    TMain mainint;
    mainint = (*j1).main;
    (*j1).main = (*j2).main;
    (*j2).main = mainint;

}

void JouerCarteTotem(TCarte carte, TPile *pioche ,TJoueur *joueurQuiJoue, TJoueur *joueurCible, TJoueur listeJoueur)
{
    int i = 0;
    //Montrer la carte à jouer
    printf("La carte jouee est : %s ",carte.nom);
    //Plusieurs actions possibles:

    //TeteCoyote
    //TeteAigle
    //TeteLoup
    //TeteCorbeau
    //TeteLynx
    //TeteTortue
    //TeteOurs

    if(strcmp(carte.nom,"TeteCoyote") == 0)
    {
        tete_coyote(&joueurQuiJoue.totem, &joueurCible.totem);  
    }
    else if(strcmp(carte.nom,"TeteAigle") == 0)
    {
        (*joueurQuiJoue).immunite = 2;
    }
    else if(strcmp(carte.nom,"TeteLoup") == 0)
    {
        //à faire
    }
    else if(strcmp(carte.nom,"TeteCorbeau") == 0)
    {
        tete_coyote(&joueurQuiJoue.main, &joueurCible.main);      
    }
    else if(strcmp(carte.nom,"TeteLynx") == 0)
    {
        //à faire
    }
    else if(strcmp(carte.nom,"TeteTortue") == 0)
    {
        (*joueurQuiJoue).immunite = 1;
    }
    else if(strcmp(carte.nom,"TeteOurs") == 0)
    {
        if((*joueurCible).immunite == 1)
        {
            printf("Ce joueur est immunisé contre la destruction de totem pour l'instant");
        }
        else
        {
            //on détruit un étage du totem adverse
            depiler((*joueurCible).totem.sommet);
        }
    }


}

