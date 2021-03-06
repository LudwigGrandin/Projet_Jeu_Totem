#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "libraryProjet.h"

//Fonction permettant de piocher
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

//Fonction appel� permettant de jouer une carte
void JouerCarte(TPile *totem, TPile *pioche, int numCarteMain, TJoueur *joueurQuiJoue, TJoueur *listeJoueur)
{

    TCarte carte;

    //On r�cup�re l'adresse dans la liste chain�e de la carte que le joueur veut jouer
    carte = Retrait_Carte_Main(&(*joueurQuiJoue).main,numCarteMain);

    //Il faut d�sallouer l'emplacement qui a �t� supprim� de la main
    //Si c'est une carte totem alors on l'ajoute � la pile totem
    if(carte.type == 1)
    {
        empiler(totem,&carte);
        JouerCarteTotem(carte,pioche,joueurQuiJoue,*listeJoueur);
        //Mettre condition pour immunit� etc ..
    }
    else
    {

    }
}

//Fonction Permettant de r�cup�rer l'adresse d'une carte contenue dans la liste cha�n�e de la main
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

//Fonction permettant d'afficher la main d'un joueur
void Afficher_Main(TMain mainJoueur)
{

    TPilelem *aux;
    aux = mainJoueur.debut;

    if(aux == NULL)
    {
        printf("vous n'avez pas de cartes en main\n");
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

//Proc�dure permettant de jouer une carte Coup Bas. Elle est appell� dans la proc�dure jouer carte
void JouerCarteCoupBas(TCarte carte, TPile *pioche ,TJoueur *joueurQuiJoue, TJoueur listeJoueur, int *gagnePartie)
{
    int i =0;
     TJoueur *joueurCible;
    (*joueurQuiJoue).rejouer = 0;
    (*joueurCible).rejouer = 0;
    //Montrer la carte � jouer
    printf("La carte jouee est : %s \n",carte.nom);
    //Plusieurs actions possibles:

    if(strcmp(carte.nom,"OnArrive") == 0)
    {
        //A jouer en m�me temps qu'un joueur qui gagne
        //EFFET : Vous gagnez la partie aussi.
         ajout_Points(joueurQuiJoue, gagnePartie);
    }
    else if(strcmp(carte.nom,"EtPaf") == 0)
    {
        if((*joueurCible).immunite == 1)
        {
            printf("Ce joueur est immunis� contre le vol de totem\n");
        }
        else if((*joueurCible).immunite == 1)
        {
            printf("Ce joueur est immunis� contre la destruction de totem\n");
        }
        else
        {
            //Destruction du totem adverse
            depiler(&(*joueurCible).totem);
        }
    }
    else if(strcmp(carte.nom,"EspritFarceur") == 0)
    {
        //EFFET : chacun donne son totem � son voisin de gauche
   //     Donner_Totem_Vers_Voisin_Gauche(listeJoueur);         manque un parametre
    }
    else if(strcmp(carte.nom,"BisonDingo") == 0)
    {
        //
        for(i=0; i<2;i++)
        {
            depiler(&(*joueurCible).totem);
        }
    }
    else if(strcmp(carte.nom,"FauxPas") == 0)
    {
        int choix = 0;
        /*Pr�-requis : Jouer cette carte durant le tour d�un autre joueur.
EFFET : Annuler l�action d�un joueur si vous annulez un autre �Faux pas !�. Piochez 2 cartes, sinon rejouez imm�diatement.
*/
        if(carte.nom == "FauxPas")
        {
            printf("Piocher 2 carte en Tapant 1 ou rejouez imm�diatement en tapant 2 : \n");
            scanf("%d", &choix);
            if(choix == 1)
            {
                for(i=0; i<2; i++)
                {
                    piocher(&(*joueurQuiJoue).main,pioche);
                }
            }
            else
            {
                (*joueurQuiJoue).rejouer = 1;
            }
        }


    }
    else if(strcmp(carte.nom,"Pillage") == 0)
    {
        TCarte carteTotemAdverse;
        carteTotemAdverse = (*(*joueurCible).totem.sommet).carte;
        Depot_Carte_Main(&(*joueurQuiJoue).main,carteTotemAdverse,taille_pile((*joueurQuiJoue).totem));
        depiler(&(*joueurCible).totem);


        if(taille_pile((*joueurQuiJoue).totem) <4)
        {
            (*joueurQuiJoue).rejouer = 1;
            //Comment g�rer le fait de rejouer ? Variable dans joueur ?
        }

        /*
         Voler et mettez dans votre main le derni�re
          �tage du totem d�un joueur. Si votre totem poss�de
          moins de 4 �tages . Rejouez imm�diatement.

        */
    }
    else if(strcmp(carte.nom,"EaudeFeu") == 0)
    {
        /*
        EFFET : Piochez 2 cartes puis rejouez imm�diatement.

        */
        for(i=0; i<2;i++)
        {//Voir pour le pointeur
             piocher(&(*joueurQuiJoue).main,pioche);
        }

        (*joueurQuiJoue).rejouer = 1;
        //Comment indiquer de rejouer?

    }


}

//Proc�dure permettant de d�fausser une carte
void Defausser_Carte(TMain *mainJoueur, int numCarte)
{
    Retrait_Carte_Main(mainJoueur,numCarte);
}

//Proc�dure permettant de donner sa main � son voisin de gauche et de le faire pour tous les joueurs
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

//Proc�dure permettant de donner son totem � son voisin de gauche et de le faire pour tous les joueurs
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

// Proc�dure permettant d'�changer les totems de 2 joueurs
void tete_coyote(TJoueur * j1, TJoueur * j2)
{
    TPile totemint;
    totemint = (*j1).totem;
    (*j1).totem = (*j2).totem;
    (*j2).totem = totemint;

}
// Proc�dure permettant d�changer les totems de 2 joueurs
void tete_corbeau(TJoueur * j1, TJoueur * j2)
{
    TMain mainint;
    mainint = (*j1).main;
    (*j1).main = (*j2).main;
    (*j2).main = mainint;

}

//Permet d'�changer les mains de deux TJoueur
void tete_loup(TMain *mainJoueurQuiJoue,TMain *mainJoueurCible)
{
    TMain mainTemp;

    mainTemp = *mainJoueurQuiJoue;
    mainJoueurQuiJoue = mainJoueurCible;
    *mainJoueurCible = mainTemp;


}

void tete_lynx(TJoueur *joueurQuiJoue,TPile *pioche)
{
     int numCarte = 0;
        TMain main3Cartes;
        TPilelem *aux;
        int choix;

        main3Cartes.debut = (TPilelem*) malloc(sizeof(TPilelem*));
        aux = main3Cartes.debut;
        //Prenser � retirer ces propri�t�s quand un autre totem est plac�
        (*joueurQuiJoue).lynx = 1;

        //Permet de tirer 3 cartes
        for(numCarte=0; numCarte == 3; numCarte ++)
        {
            printf("Carte %d : %s", numCarte+1, (*(*pioche).sommet).carte.nom);
            piocher(&main3Cartes,pioche);
        }

        printf("Quelle carte choisissez vous ? :");
        scanf("%d", &choix);

        aux = main3Cartes.debut;

        for(numCarte=0; numCarte<choix-1;numCarte++)
        {
            aux = (*aux).suivant;
        }

        Depot_Carte_Main(&(*joueurQuiJoue).main,(*aux).carte,taille_main((*joueurQuiJoue).main));

        liberer_main(&main3Cartes);
}

void Depot_Carte_Main(TMain *mainJoueur, TCarte carte, int emplacementMain)
{


    TPilelem *aux, *prec, *newCell;
    int emplacementMainLocal = 1, trouve = 0;


    aux = (*mainJoueur).debut;

    while(aux != NULL && trouve != 1)
    {
        if(emplacementMainLocal == emplacementMain)
        {
            trouve = 1;
        }
        else
        {
            prec = aux;
            aux = (*aux).suivant;
            emplacementMainLocal ++;
        }
    }

    if(trouve == 1)
    {
        newCell = (TPilelem*) malloc(sizeof(TPilelem));
        (*newCell).carte = carte;

        (*prec).suivant = newCell;
        (*newCell).suivant = aux;
    }
    else
    {
        printf("veuillez saisir un num�ro de carte valide\n");
    }
}
//fonction qui retourne la taille d'une TMain
int taille_main(TMain mainJoueur)
{
    TPilelem *aux;
    int tailleMain = 0;
    aux = mainJoueur.debut;

    while(aux != NULL)
    {
        aux = (*aux).suivant;
        tailleMain ++;
    }
    return tailleMain;
}
//Permet au diff�rentes TCartes d'�tre jou�es
void JouerCarteTotem(TCarte carte, TPile *pioche ,TJoueur *joueurQuiJoue, TJoueur listeJoueur)
{
    int i = 0;
    TJoueur joueurCible;
    //Montrer la carte � jouer
    printf("La carte jouee est : %s \n",carte.nom);
    //Plusieurs actions possibles:
    empiler(pioche,&carte);
    //TeteCoyote
    //TeteAigle
    //TeteLoup
    //TeteCorbeau
    //TeteLynx
    //TeteTortue
    //TeteOurs

    if(strcmp(carte.nom,"TeteCoyote") == 0)
    {
        tete_coyote(joueurQuiJoue, &joueurCible);
    }
    else if(strcmp(carte.nom,"TeteAigle") == 0)
    {
        (*joueurQuiJoue).immunite = 2;
    }
    else if(strcmp(carte.nom,"TeteLoup") == 0)
    {
        tete_loup(&(*joueurQuiJoue).main,&joueurCible.main);
    }
    else if(strcmp(carte.nom,"TeteCorbeau") == 0)
    {
        tete_corbeau(joueurQuiJoue,&joueurCible);
    }
    else if(strcmp(carte.nom,"TeteLynx") == 0)
    {
        tete_lynx(joueurQuiJoue,pioche);

        //Cr�er une variable dans TJoueur si = 1 alors le joueur piochera 3 fois et d�faussera deux cartes � chaque fin tour ?
    }
    else if(strcmp(carte.nom,"TeteTortue") == 0)
    {
        (*joueurQuiJoue).immunite = 1;
    }
    else if(strcmp(carte.nom,"TeteOurs") == 0)
    {
        if(joueurCible.immunite == 1)
        {
            printf("Ce joueur est immunis� contre la destruction de totem pour l'instant\n");
        }
        else
        {
            //on d�truit un �tage du totem adverse
            depiler(&joueurCible.totem);
        }
    }


}

