#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "libraryProjet.h"

	/* Définition d'une carte */

int main()
{
/** PartieKillian

        //TODO : selon le nbr de joueurs des cartes seront à retirer

        int taillePioche = 64;
        TPile laPioche;
        struct TCarte listeCartes[64];
        // Va contenir le tableau de nombres qui servira à remplir la pioche
        //int *tabNum = malloc((taillePioche)*sizeof(int));

        int tabNum[64];

        //créér un tableau d'entier de 0 à 63 et une liste de TCartes
        init_sans_doublons(tabNum,taillePioche);
        init_ListeCarte(listeCartes,taillePioche,2);
        init_pile(&laPioche);

        // créer la pioche de TCartes mélangé en utilisant le tableau d'entier et la liste de TCartes
        init_pioche(tabNum,taillePioche,listeCartes,&laPioche);
         printf("\n ");
        afficher_pile(laPioche);
        printf("\n debug 4 \n");


       // Ne pas oublier de libérer la mémoire
       //free(tabNum);
       liberer_pile(&laPioche);

/**MainLudwig**/
/**


//test de toutes les procédures.
    TPile pile;
    TPile totem;
	init_pile(&pile);
	init_pile(&totem);
	pile.sommet = NULL;
	totem.sommet = NULL;
	TCarte carte;
	carte.num = 0;
	carte.type = 0;
	int nombreCarte = 2;

	TJoueur listeJoueur[10];
	int nbCarte = 64;
	int nbJoueur = 4;

	TMain mainJoueur;
	mainJoueur.debut = (TPilelem*) malloc(sizeof(TPilelem));
	mainJoueur.debut = NULL;

	listeJoueur[0].id = 1;
	strcpy(listeJoueur[0].nom, "jackie");

	listeJoueur[1].id = 2;
	strcpy(listeJoueur[1].nom,"Michel");

	listeJoueur[2].id = 3;
	strcpy(listeJoueur[2].nom, "Louisa");

	listeJoueur[3].id = 4;
	strcpy(listeJoueur[3].nom, "Perl");


    liberer_main(&mainJoueur);
	liberer_pile(&pile); // libère toute la pile


/**Main Lucas**/


//Pas besoin d'avoir de main ici, décommente juste ta partie. Le début du main est tout ne haut

    //int taille = 0;
	//struct TPile pile;

//test de toutes les procédures.
/*
	int taille = 0;
	struct TPile pile;
	struct TPile piletest;
	init_pile(&pile);
	struct TCarte carte;
	carte.num = 0;
	for(int i = 0; i <= 2; i ++){
		printf("Entrer un nom de carte \n");
		fflush(stdout);
		scanf("%s", carte.nom);

		printf("Entrer un effet de carte \n");
		fflush(stdout);
		scanf("%s", carte.effet);

		carte.num++;
		carte.type = 1;

		empiler(&pile, &carte);
	}

	afficher_pile(pile);		//affiche la pile avant depiler
	pile = depiler(&pile);
	printf("Voici la pile dépilée \n");
	afficher_pile(pile);
//	taille = taille_pile(pile);
//	printf("%d", taille);
	liberer_pile(&pile); // libère toute la pile
	afficher_pile(pile);

*/
//Ne commente pas le return ici, c'est la fin du main(peu importe si c'est celui de ludwig, lucas ou killian
	return 0;
}


/********************************************PIOCHE************************************************/

void init_sans_doublons(int* tableau,int taille){

	//remplit le tableau de façon croissant
	for(int i = 0; i< taille; i++)
    {
		tableau[i]=i;
	}
}

void melanger(int* tableau, int taille){
	// A ne pas oublier !
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

void init_pioche(int nbCarte,int nbJoueur, TPile* pioche){

    int tableau[nbCarte];
    init_sans_doublons(tableau,nbCarte);
    //mélange le tableau d'entier
    melanger(tableau,nbCarte);
    //debug

    TCarte listeCarte[nbCarte];
    init_ListeCarte(listeCarte,nbCarte,nbJoueur);

   /* for(int i =0 ; i< nbCarte ; i++){
            printf(" %d ;", tableau[i]);
        }*/


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
//initialise la liste des cartes mais bien géré les cartes exclus
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

       //printf("\n Numero carte : %i , nom carte: %s \n",carte.num,carte.nom);
       liste[i] = carte;
    }
}


void afficherCartes(TCarte* listeCartes,int taille){
    for(int i = 0; i< taille ; i++){
        printf("\nCarte num: %i , nom: %s\n",listeCartes[i].num,listeCartes[i].nom);
    }
}
//permet la saisie d'un nbr entre deux bornes
int saisir_entre(int min, int max)
{
  //lexique
  int vretour = -1;
  do{
    printf("saisir un nombre entre %d et %d \n",min,max);
    scanf("%d", &vretour);
  }while ((vretour < min) || (vretour > max));
  return vretour;
}
/**  FIN PIOCHE  **/

int est_pile_vide(TPile pile)
{
	int verif = 0;
	if(pile.sommet == NULL){
		verif = 1;
		return verif;
	}

	return verif;
}


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

void init_pile(TPile * pile)
{
	(*pile).sommet = NULL;

}

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

void liberer_pile(TPile * pile)
{

	int verif;
	verif = est_pile_vide(*pile);

	while(verif == 0){
		depiler(pile);
		verif = est_pile_vide(*pile);
	}
}

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

/*
void menu(TJoueur j, int e, int nbJoueurs, TPile *pioche)
{
	int verif = 0;
	int choix = 0;
	int rep = 0;
	int choixCarte = 0;
	printf("C'est au tour du joueur n° %d \n", e);

	// proposer action soit jouer carte / défausser une carte / piocher deux cartes

	printf("Que voulez-vous faire ? 1 pour jouer une carte de votre main / 2 pour piocher deux cartes / 3 pour défausser une carte de votre main")
	do
	{
		scanf("%d", &choix);
	}while(choix < 1 || choix > 3);

	if(choix == 1)
	{
		printf("Indiquez le nom de la carte que vous voulez jouer \n");
		do
		{
			scanf("%d", &choixCarte);
			//verif s'il a bien la carte dans sa main / Création d'une fonction verif_carte()?
			//verif = verif_carte(j.main, choixCarte);/ //prend la main et la carte souhaitée en paramètre
			//Si la vérif = 0 alors il n'a pas la carte dans sa main et doit en jouer une.
			if(verif == 0)
			{
				printf("Vous ne possédez pas cette carte dans votre main veuillez en choisir une nouvelle.\n");
			}
			//Sinon on continue
		}while(verif != 1);

		//proposer aux autres de contrer
		printf("Un joueur ayant la carte 'Faux pas !' peut contrer la carte");
		printf("Entrer le numéro du joueur souhaitant contrer l'action \n");
		scanf("%d", rep);
		if(rep == 1)
		{
			//on verif si le joueur 1 à la carte "Faux Pas"
			//si oui on supprime la carté jouée le joueur e et la carte faux pas du joueur 1
			//sinon on demande à un autre joueur s'il veut contrer
		}
		else if(rep == 2)
		{
			//on verif si le joueur 2 à la carte "Faux Pas"
			//si oui on supprime la carté jouée le joueur e et la carte faux pas du joueur 2
			//sinon on demande à un autre joueur s'il veut contrer
		}
		else if(rep == 3)
		{
			//on verif si le joueur 3 à la carte "Faux Pas"
			//si oui on supprime la carté jouée le joueur e et la carte faux pas du joueur 3
			//sinon on demande à un autre joueur s'il veut contrer
		}
		else if(rep == 4)
		{
			//on verif si le joueur 4 à la carte "Faux Pas"
			//si oui on supprime la carté jouée le joueur e et la carte faux pas du joueur 4
			//sinon on demande à un autre joueur s'il veut contrer
		}
		else{
			//on joue la carte souhaitée par le joueur e
		}
	}
	else if(choix == 2)
	{
		printf("Choisir le numéro de la carte à défausser.");
		scanf("%d", &choixCarte);
		verif = verif_carte(j.main, choixCarte);
		if(verif == 0)
		{
			printf("Vous ne possédez pas cette carte dans votre main veuillez en choisir une nouvelle.\n");
		}
		else
		{
			Defausser_Carte(&j.main, choixCarte);
		}
	}
	else
	{
		piocher(&j.main, &pioche);
		piocher(&j.main, &pioche);
	}

}
*/

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
    	while(aux != NULL || trouve != 1)
    	{
    		if(numCarte == (*aux).carte.num)
    		{
    			trouve = 1;
    		}
    	}
    }
    return trouve;

}

