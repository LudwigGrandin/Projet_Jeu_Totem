#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "libraryProjet.h"


/******************************************** PIOCHE ************************************************/

//procédure permettant de piocher
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

//procédure permettant de remplir un tableau d'entier
void init_sans_doublons(int* tableau,int taille){

	//remplit le tableau de façon croissant
	for(int i = 0; i< taille; i++)
    {
		tableau[i]=i;
	}
}


//procédure mélangeant de façon aléatoire un tableau d'entier
void melanger(int* tableau, int taille){
	//lexique
	// A ne pas oublier ! Permet d'avoir tirage aléatoire
    srand(time(NULL));
	int i=0;
	int nombre_tire=0;
	int temp=0;

	for(i = 0; i< taille;i++)
    {
		nombre_tire= rand()%64+1;
		// On échange les contenus des cases i et nombre_tire
		temp = tableau[i];
		tableau[i] = tableau[nombre_tire];
		tableau[nombre_tire]=temp;
	}
}
// procédure qui créer la pile/pioche à partir d'un tableau d'entier mélangé et d'un tableau contenant les TCartes
void init_pioche(int nbCarte,int nbJoueur, TPile* pioche){

   //lexique
    int tableau[nbCarte];
    struct TCarte listeCarte[nbCarte];
    //remplit le tableau d'entier
    init_sans_doublons(tableau,nbCarte);
    //mélange le tableau d'entier
    melanger(tableau,nbCarte);
    //remplit le tableau de TCarte
    init_ListeCarte(listeCarte,nbCarte,nbJoueur);

   /* for(int i =0 ; i< nbCarte ; i++){
            printf(" %d ;", tableau[i]);
        }*/
    //si le numéro de la TCarte correspond à l'entier du tableau[i] on empile dans la pioche
    for(int i=0 ; i < nbCarte ; i++)
    {
        for(int j = 0; j < nbCarte ; j++)
        {
            if(tableau[i] == listeCarte[j].num)
            {
                empiler(pioche, &listeCarte[j]);
            }
        }
    }

}
//initialise la liste des cartes mais ne gère pas le fait d'exclure des cartes en fonction du nombre de joueur
void init_ListeCarte(TCarte* liste,int nbCarte,int nbJoueur){
    //lexique
   struct TCarte carte;

    //init de toutes les cartes
    for(int i = 0; i < nbCarte;i++)
    {
       switch(i)
       {
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
                carte.num = i;
                strcpy(carte.effet,"Lorsque Tete de coyote arrive en jeu, vous pouvez voler le totem d'un joueur et lui donner le votre.");
                carte.type = 1;
                strcpy(carte.nom,"Tete de Coyote");
                break;
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
                carte.num = i;
                strcpy(carte.effet,"Aucun Joueur ne peut vous voler votre totem ou des étages de votre totem.");
                carte.type = 1;
                strcpy(carte.nom, "Tete d'Aigle");
                break;
            case 10:
            case 11:
            case 12:
            case 13:
            case 14:
                carte.num = i;
                strcpy(carte.effet,"Lorsque Tete de loup arrive en jeu, vous pouvez voler 2 cartes au hasard dans la main d'un joueur adverse.");
                carte.type = 1;
                strcpy(carte.nom, "Tete de Loup");
                break;
            case 15:
            case 16:
            case 17:
            case 18:
            case 19:
                carte.num = i;
                strcpy(carte.effet,"Lorsque Tete de corbeau arrive en jeu, vous pouvez echanger votre main avec celle d'un autre joueur.");
                carte.type = 1;
                strcpy(carte.nom,"Tete de Corbeau");
                break;
            case 20:
            case 21:
            case 22:
            case 23:
            case 24:
                carte.num = i;
                strcpy(carte.effet,"A la fin de chacun de vos tours vous pouvez piocher 3 cartes. En choisir une puis défausser les 2 autres.");
                carte.type = 1;
                strcpy(carte.nom,"Tete de Lynx");
                break;
            case 25:
            case 26:
            case 27:
            case 28:
            case 29:
                carte.num = i;
                strcpy(carte.effet,"Aucun Joueur ne peut détruire votre totem ou des etages de votre totem.");
                carte.type = 1;
                strcpy(carte.nom,"Tete de Tortue");
                break;
            case 30:
            case 31:
            case 32:
            case 33:
            case 34:
                carte.num = i;
                strcpy(carte.effet,"Lorsque Tete d'ours arrive en jeu, vous pouvez detruire le dernier etage du totem d'un joueur.");
                carte.type = 1;
                strcpy(carte.nom,"Tete d'ours");
                break;
            case 35:
                carte.num = i;
                strcpy(carte.effet,"Vous gagner la partie aussi");
                carte.type = 0;
                strcpy(carte.nom,"On arrive");
                break;
            case 36:
            case 37:
            case 38:
            case 39:
                carte.num = i;
                strcpy(carte.effet,"Detruisez le dernier etage d'un totem");
                carte.type = 0;
                strcpy(carte.nom,"Et paf");
                break;
            case 40:
            case 41:
            case 42:
                carte.num = i;
                strcpy(carte.effet,"Chaque joueur doit donner son totem au joueur se trouvant à sa gauche.");
                carte.type = 0;
                strcpy(carte.nom,"Esprit Farceur");
                break;
            case 43:
            case 44:
            case 45:
            case 46:
            case 47:
                carte.num = i;
                strcpy(carte.effet,"Annuler l'action d'un joueur, si vous annuler un autre Faux Pas piocher deux cartes, sinon rejouez immediatement.");
                carte.type = 0;
                strcpy(carte.nom,"Faux Pas");
                break;
            case 48:
            case 49:
            case 50:
            case 51:
            case 52:
                carte.num = i;
                strcpy(carte.effet,"Volez et mettez dans votre main le dernier etage du totem d'un joueur. Si votre totem possede moins de 4 etages. Rejouez immediatement.");
                carte.type = 0;
                strcpy(carte.nom,"Pillage");
                break;
            case 53:
            case 54:
            case 55:
                carte.num = i;
                strcpy(carte.effet,"Detruisez les 2 derniers etages d'un totem.");
                carte.type = 0;
                strcpy(carte.nom,"Bison Dingo");
                break;
            case 56:
            case 57:
            case 58:
            case 59:
                carte.num = i;
                strcpy(carte.effet,"Volez une tete au sommet d'un totem pour le placer au sommet d'un totem adverse. Puis piochez 1 carte.");
                carte.type = 0;
                strcpy(carte.nom,"Cadeau");
                break;
            case 60:
            case 61:
            case 62:
            case 63:
                carte.num = i;
                strcpy(carte.effet,"Piochez 2 cartes puis rejouez immediatement");
                carte.type = 0;
                strcpy(carte.nom,"Eau de feu");
                break;
            default:
                printf("valeur hors cas normal");
                break;

       }
       //une fois ma TCarte initialisé je la place dans mon tableau
       liste[i] = carte;
    }
}

//procédure qui affiche la liste des TCarte contenu dans un tableau
void afficherCartes(TCarte* listeCartes,int taille){
    for(int i = 0; i< taille ; i++){
        printf("\nCarte num: %i , nom: %s\n",listeCartes[i].num,listeCartes[i].nom);
    }
}
//fonction qui permet la saisie d'un nbr entre deux bornes
int saisir_entre(int min, int max)
{
  //lexique
  int vretour = -1;

  do{
    printf("saisir un nombre entre %d et %d \n",min,max);

    scanf("%d", &vretour);
  }while ((vretour < min) || (vretour > max));
  printf("%d",vretour);
  return vretour;
}
/**********************************************  FIN PIOCHE  **********************************************/

/**********************************************  JOUEURS  **********************************************/
//procédure qui initialise une liste de TJoueur
void init_Joueurs(TJoueur * listeJoueur,int nbJoueur){
    for(int parcouru = 0; parcouru < nbJoueur ; parcouru++){
        TJoueur joueur;
        printf("\nSaisir un pseudonyme pour le joueur %d :",parcouru+1);

        scanf("%s", joueur.nom);
        joueur.id = parcouru;
        joueur.points = 0;
        joueur.immunite = 0;
        joueur.lynx = 0;
        init_pile(&joueur.totem);
        joueur.main.debut = NULL;
        joueur.rejouer = 0;
        listeJoueur[parcouru] = joueur;
    }
}


/********************************************** FIN JOUEURS  **********************************************/

/********************************************** GESTION MAIN  **********************************************/
//Fonction appelée permettant au joueur de jouer une carte
void JouerCarte(TPile *totem, TPile *pioche, int numCarteMain, TJoueur *joueurQuiJoue, TJoueur *listeJoueur)
{

    TCarte carte;

    //On récupère l'adresse dans la liste chainée de la carte que le joueur veut jouer
    carte = Retrait_Carte_Main(&(*joueurQuiJoue).main,numCarteMain);

    //Il faut désallouer l'emplacement qui a été supprimé de la main
    //Si c'est une carte totem alors on l'ajoute à la pile totem
    if(carte.type == 1)
    {
        empiler(totem,&carte);
        JouerCarteTotem(carte,pioche,joueurQuiJoue,*listeJoueur);
        //Mettre condition pour immunité etc ..
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

//Procédure permettant de jouer une carte Coup Bas. Elle est appellé dans la procédure jouer carte

void JouerCarteCoupBas(TCarte carte, TPile *pioche ,TJoueur *joueurQuiJoue, TJoueur listeJoueur, int *gagnePartie)
{
    int i =0;
     TJoueur *joueurCible;
    (*joueurQuiJoue).rejouer = 0;
    (*joueurCible).rejouer = 0;
    //Montrer la carte à jouer
    printf("La carte jouee est : %s \n",carte.nom);
    //Plusieurs actions possibles:

    if(strcmp(carte.nom,"OnArrive") == 0)
    {
        //A jouer en même temps qu'un joueur qui gagne
        //EFFET : Vous gagnez la partie aussi.
         ajout_Points(joueurQuiJoue, gagnePartie);
    }
    else if(strcmp(carte.nom,"EtPaf") == 0)
    {
        if((*joueurCible).immunite == 1)
        {
            printf("Ce joueur est immunisé contre le vol de totem\n");
        }
        else if((*joueurCible).immunite == 1)
        {
            printf("Ce joueur est immunisé contre la destruction de totem\n");
        }
        else
        {
            //Destruction du totem adverse
            depiler(&(*joueurCible).totem);
        }
    }
    else if(strcmp(carte.nom,"EspritFarceur") == 0)
    {
        //EFFET : chacun donne son totem à son voisin de gauche
   //     Donner_Totem_Vers_Voisin_Gauche(listeJoueur);      
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
        /*Pré-requis : Jouer cette carte durant le tour d’un autre joueur.
EFFET : Annuler l’action d’un joueur si vous annulez un autre “Faux pas !”. Piochez 2 cartes, sinon rejouez immédiatement.
*/
        if(carte.nom == "FauxPas")
        {
            printf("Piocher 2 carte en Tapant 1 ou rejouez immédiatement en tapant 2 : \n");
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
        }

        /*
         Voler et mettez dans votre main le dernière
          étage du totem d’un joueur. Si votre totem possède
          moins de 4 étages . Rejouez immédiatement.

        */
    }
    else if(strcmp(carte.nom,"EaudeFeu") == 0)
    {
        /*
        EFFET : Piochez 2 cartes puis rejouez immédiatement.

        */
        for(i=0; i<2;i++)
        {
             piocher(&(*joueurQuiJoue).main,pioche);
        }

        (*joueurQuiJoue).rejouer = 1;

    }

}

//Procédure permettant de défausser une carte
void Defausser_Carte(TMain *mainJoueur, int numCarte)
{
    Retrait_Carte_Main(mainJoueur,numCarte);
}

//Procédure permettant de donner sa main à son voisin de gauche et de le faire pour tous les joueurs
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

//Procédure permettant de donner son totem à son voisin de gauche et de le faire pour tous les joueurs
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

// Procédure permettant d'échanger les totems de 2 joueurs
void tete_coyote(TJoueur * j1, TJoueur * j2)
{
    TPile totemint;
    totemint = (*j1).totem;
    (*j1).totem = (*j2).totem;
    (*j2).totem = totemint;

}
// Procédure permettant déchanger les totems de 2 joueurs
void tete_corbeau(TJoueur * j1, TJoueur * j2)
{
    TMain mainint;
    mainint = (*j1).main;
    (*j1).main = (*j2).main;
    (*j2).main = mainint;

}

//Permet d'échanger les mains de deux TJoueur
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
        //Prenser à retirer ces propriétés quand un autre totem est placé
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
        printf("veuillez saisir un numéro de carte valide\n");
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
//Permet au différentes TCartes d'être jouées
void JouerCarteTotem(TCarte carte, TPile *pioche ,TJoueur *joueurQuiJoue, TJoueur listeJoueur)
{
    int i = 0;
    TJoueur joueurCible;
    //Montrer la carte à jouer
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

        //Créer une variable dans TJoueur si = 1 alors le joueur piochera 3 fois et défaussera deux cartes à chaque fin tour ?
    }
    else if(strcmp(carte.nom,"TeteTortue") == 0)
    {
        (*joueurQuiJoue).immunite = 1;
    }
    else if(strcmp(carte.nom,"TeteOurs") == 0)
    {
        if(joueurCible.immunite == 1)
        {
            printf("Ce joueur est immunisé contre la destruction de totem pour l'instant\n");
        }
        else
        {
            //on détruit un étage du totem adverse
            depiler(&joueurCible.totem);
        }
    }
}

//fonction permettant de vérifier la présence dans sa main de la carte joué par un joueur 
int verif_carte(TMain mainJoueur, int numCarte)
{
    TPilelem *aux;
    int trouve = 0;

    aux = mainJoueur.debut;

    if(aux == NULL)
    {
        printf("Vous n'avez aucune carte en main");
    }
    else
    {
        while(aux != NULL && trouve != 1)
        {
            if(numCarte == (*aux).carte.num)
            {
                trouve = 1;
            }
            else
            {
                aux = (*aux).suivant;
            }
        }
    }
    return trouve;

}

// procédure permettant de vider libérer une main de carte entièrement
void liberer_main(TMain * main)
{
    TPilelem *aux;
    aux = (*main).debut;

    if(aux == NULL){
        printf("La liste est vide, rien à supprimer");
    }

    while(aux != NULL){

        (*main).debut = (*aux).suivant;
        free(aux);
        aux = (*main).debut;
    }
}


/********************************************** FIN GESTION MAIN  **********************************************/

/**********************************************  NETTOYAGE MEMOIRE **********************************************/
//faire appel à cette procédure en fin de partie pour liberer la mémoire
void nettoyage_partie(TJoueur * listeJoueur,int nbJoueur ,TPile * laPioche){

    for(int parcouru = 0 ; parcouru < nbJoueur ; parcouru++){
        liberer_main(&listeJoueur[parcouru].main);
        liberer_pile(&listeJoueur[parcouru].totem);
    }
    liberer_pile(laPioche);
}
/**********************************************  FIN NETTOYAGE MEMOIRE  **********************************************/



/**********************************************  POINTS  **********************************************/

//On gagne autant de point que l'on à d'étage avec un minima de 1 points
void ajout_Points(TJoueur *joueur, int *gagnePartie){
    //lexique
    int gainPoints = taille_pile((*joueur).totem);

    if(gainPoints == 0)
    {
        gainPoints = 1;
    }
    (*joueur).points = (*joueur).points + gainPoints;

    //si le joueur cumule 24 points ou plus il gagne la partie
    if((*joueur).points >= 24)
    {
        printf("Félicitation vous avez gagné la partie %s \n",(*joueur).nom);
        *gagnePartie = 1;
    }

}

//Initialise les points de tout les joueurs à 0
void initialiser_Points(TJoueur* listeJoueur,int nbJoueur){
     for(int parcouru = 0 ; parcouru < nbJoueur ; parcouru++){
         listeJoueur[parcouru].points = 0;
    }
}

//affiche pour chaque joueur son nombre de points
void affichage_Points(TJoueur* listeJoueur,int nbJoueur){
    for(int parcouru = 0 ; parcouru < nbJoueur ; parcouru++){
        printf("\n Le joueur numero %d, %s  a %d points.",listeJoueur[parcouru].id,listeJoueur[parcouru].nom ,listeJoueur[parcouru].points);
    }
}

/**********************************************  FIN POINTS **********************************************/

/**********************************************  GESTION PILE **********************************************/

//fonction retournant une valeur entre 0 et 1 permettant de vérifier si la pile entrée en paramètre est vide ou pas.
int est_pile_vide(TPile pile)
{
	int verif = 0;
	if(pile.sommet == NULL){
		verif = 1;
		return verif;
	}

	return verif;
}

// procédure permettant d'empiler une carte sur une pile
void empiler(TPile * pile, TCarte * c)
{
	struct TPilelem *aux;
	struct TPilelem *newC;

	newC = (TPilelem*) malloc(sizeof(TPilelem));
	strcpy((*newC).carte.nom , (*c).nom);
	strcpy((*newC).carte.effet , (*c).effet);
	(*newC).carte.num = (*c).num;
	(*newC).carte.type = (*c).type;

	aux = (*pile).sommet;
	(*newC).suivant = (*pile).sommet;
	(*pile).sommet = newC;

}

// procédure permettant de dépiler le sommet d'une pile

TPile depiler(TPile * pile)
{
	int verif;

	TPilelem *aux;

    //On vérifie si la pile est vide
	verif = est_pile_vide(*pile);

	aux = (*pile).sommet;


	if(verif == 1) // la pile est vide
	{
		printf("Rien à dépiler, la pile est vide \n");
	}
	else
	{
	    (*pile).sommet = (*aux).suivant;
		free(aux);
	}
	return *pile;
}


// procédure permettant d'initialiser une pile
void init_pile(TPile * pile)
{
	(*pile).sommet = NULL;

}

// procédure permettant d'afficher une pile

void afficher_pile(TPile pile)
{
	struct TPilelem *aux;
	int verif;

	verif = est_pile_vide(pile);
	aux = pile.sommet;

	if(verif == 1)
	{
		printf("La pile est vide, rien à afficher \n");
	}
	else
    {
        while(aux != NULL)
        {
            printf("[%d] -- %s\n", (*aux).carte.num, (*aux).carte.nom);
            aux = (*aux).suivant;
        }
    }

}

//fonction retournant la taille d'une pile

int taille_pile(TPile pile)
{
	struct TPilelem *aux;
	int verif;
	int taille = 0;

	verif = est_pile_vide(pile);
	aux = pile.sommet;
	if(verif == 1)
	{
		taille = 0;
	}
		while(aux != NULL)
	{
		taille++;
		aux = (*aux).suivant;
	}
	return taille;
}

//fonction qui dépile une pile jusqu'à ce qu'elle soit vide
void liberer_pile(TPile * pile)
{

	int verif;
	verif = est_pile_vide(*pile);

	while(verif == 0){
		depiler(pile);
		verif = est_pile_vide(*pile);
	}
}

/**********************************************  FIN GESTION PILE **********************************************/

/**********************************************  TOUR JOUEUR **********************************************/

//fonction choisissant le joueur jouant en premier pour la manche en cours.

int Choix_Premier_Joueur(int nbJoueur)
{
    srand(time(NULL));
    return rand()%nbJoueur+1;
}

// procédure permettant de distribuer 5 cartes aux joueurs à chaque début de manche

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

// Procédure gérant le tour d'un joueur

void tour_joueur(TJoueur *listeJoueur, TPile *pioche, int *gagneManche, int *gagnePartie)
{
    int verif = 0;
    int choix = 0;
    int numCarte = 0;
    int tailleTotem = 0;
    printf("C'est au joueur n° %d de jouer. \n", (*listeJoueur).id + 1);
    printf("Voici votre main\n");

    //system("cls");
    Afficher_Main((*listeJoueur).main);

    printf("Que voulez-vous faire ? 1 pour jouer une carte de votre main / 2 pour piocher deux cartes / 3 pour défausser une carte de votre main : \n");
    do
    {
        scanf("%d", &choix);

    }while(choix < 1 || choix > 3);

    if(choix == 1)
    {
        printf("Indiquez le numero de l'emplacement de la carte dans votre main : \n");
        do
        {

            scanf("%d", &numCarte);
            //verif s'il a bien la carte dans sa main / Création d'une fonction verif_carte()?
            //verif = verif_carte(j.main, choixCarte);/ //prend la main et la carte souhaitée en paramètre
            //Si la vérif = 0 alors il n'a pas la carte dans sa main et doit en jouer une.

            verif = verif_carte((*listeJoueur).main, numCarte);

            if(verif == 0)
            {
                printf("Vous ne possédez pas cette carte dans votre main veuillez en choisir une nouvelle.\n");
            }
            else
            {
                verif = 1;
            }

            //verif = 1;
            //Sinon on continue
        }while(verif != 1);

        //Le joueur pose sa carte
        //DeposerCarte(&(*listeJoueur).totem, numCarte, &(*listeJoueur).main);

        JouerCarte(&(*listeJoueur).totem,pioche,numCarte, &listeJoueur[(*listeJoueur).id],listeJoueur);
        printf("test4\n\n");
        //On affiche son totem et sa taille

        printf("Voici votre totem :\n");
        afficher_pile((*listeJoueur).totem);
        printf("De taille :\n");
        tailleTotem = taille_pile((*listeJoueur).totem);

        //Si la taille de son totem est de 6 il gagne la manche
        if(tailleTotem == 6){
            printf("Vous avez gagné la manche ! \n");
            ajout_Points(listeJoueur, gagnePartie);
            *gagneManche = 1;
        }


    }
    else if(choix == 3)
    {
        printf("Choisir le num de la carte à défausser. ");

        scanf("%d", &numCarte);
        verif = verif_carte((*listeJoueur).main, numCarte);
        if(verif == 0)
        {
            printf("Vous ne possédez pas cette carte dans votre main veuillez en choisir une nouvelle.\n");
        }
        else
        {
            Defausser_Carte(&(*listeJoueur).main, numCarte);
        }
    }
    else
    {
        piocher(&(*listeJoueur).main, pioche);
        piocher(&(*listeJoueur).main, pioche);
    }


}


/********************************************** FIN TOUR JOUEUR **********************************************/