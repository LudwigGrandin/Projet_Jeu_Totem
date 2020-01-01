#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "libraryProjet.h"


/******************************************** PIOCHE ************************************************/
//proc�dure permettant de remplir un tableau d'entier
void init_sans_doublons(int* tableau,int taille){

	//remplit le tableau de fa�on croissant
	for(int i = 0; i< taille; i++)
    {
		tableau[i]=i;
	}
}


//proc�dure m�langeant de fa�on al�atoire un tableau d'entier
void melanger(int* tableau, int taille){
	//lexique
	// A ne pas oublier ! Permet d'avoir tirage al�atoire
    srand(time(NULL));
	int i=0;
	int nombre_tire=0;
	int temp=0;

	for(i = 0; i< taille;i++)
    {
		nombre_tire= rand()%64+1;
		// On �change les contenus des cases i et nombre_tire
		temp = tableau[i];
		tableau[i] = tableau[nombre_tire];
		tableau[nombre_tire]=temp;
	}
}
// proc�dure qui cr�er la pile/pioche � partir d'un tableau d'entier m�lang� et d'un tableau contenant les TCartes
void init_pioche(int nbCarte,int nbJoueur, TPile* pioche){

   //lexique
    int tableau[nbCarte];
    struct TCarte listeCarte[nbCarte];
    //remplit le tableau d'entier
    init_sans_doublons(tableau,nbCarte);
    //m�lange le tableau d'entier
    melanger(tableau,nbCarte);
    //remplit le tableau de TCarte
    init_ListeCarte(listeCarte,nbCarte,nbJoueur);

   /* for(int i =0 ; i< nbCarte ; i++){
            printf(" %d ;", tableau[i]);
        }*/
    //si le num�ro de la TCarte correspond � l'entier du tableau[i] on empile dans la pioche
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
//initialise la liste des cartes mais ne g�re pas le fait d'exclure des cartes en fonction du nombre de joueur
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
                strcpy(carte.effet,"Aucun Joueur ne peut vous voler votre totem ou des �tages de votre totem.");
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
                strcpy(carte.effet,"A la fin de chacun de vos tours vous pouvez piocher 3 cartes. En choisir une puis d�fausser les 2 autres.");
                carte.type = 1;
                strcpy(carte.nom,"Tete de Lynx");
                break;
            case 25:
            case 26:
            case 27:
            case 28:
            case 29:
                carte.num = i;
                strcpy(carte.effet,"Aucun Joueur ne peut d�truire votre totem ou des etages de votre totem.");
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
                strcpy(carte.effet,"Chaque joueur doit donner son totem au joueur se trouvant � sa gauche.");
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
       //une fois ma TCarte initialis� je la place dans mon tableau
       liste[i] = carte;
    }
}

//proc�dure qui affiche la liste des TCarte contenu dans un tableau
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
//proc�dure qui initialise une liste de TJoueur
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



/**********************************************  NETTOYAGE MEMOIRE **********************************************/
//faire appel � cette proc�dure en fin de partie pour liberer la m�moire
void nettoyage_partie(TJoueur * listeJoueur,int nbJoueur ,TPile * laPioche){

    for(int parcouru = 0 ; parcouru < nbJoueur ; parcouru++){
        liberer_main(&listeJoueur[parcouru].main);
        liberer_pile(&listeJoueur[parcouru].totem);
    }
    liberer_pile(laPioche);
}
/**********************************************  FIN NETTOYAGE MEMOIRE  **********************************************/



/**********************************************  POINTS  **********************************************/

//On gagne autant de point que l'on � d'�tage avec un minima de 1 points
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
        printf("F�licitation vous avez gagn� la partie %s \n",(*joueur).nom);
        *gagnePartie = 1;
    }

}

//Initialise les points de tout les joueurs � 0
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

    //On v�rifie si la pile est vide
	verif = est_pile_vide(*pile);

	aux = (*pile).sommet;


	if(verif == 1) // la pile est vide
	{
		printf("Rien � d�piler, la pile est vide \n");
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
		printf("La pile est vide, rien � afficher \n");
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
		printf("La liste est vide, rien � supprimer");
	}

	while(aux != NULL){

		(*main).debut = (*aux).suivant;
		free(aux);
		aux = (*main).debut;
	}
}



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


void tour_joueur(TJoueur *listeJoueur, TPile *pioche, int *gagneManche, int *gagnePartie)
{
    int verif = 0;
    int choix = 0;
    int numCarte = 0;
    int tailleTotem = 0;
    printf("C'est au joueur n� %d de jouer. \n", (*listeJoueur).id + 1);
    printf("Voici votre main\n");

    //system("cls");
    Afficher_Main((*listeJoueur).main);

    printf("Que voulez-vous faire ? 1 pour jouer une carte de votre main / 2 pour piocher deux cartes / 3 pour d�fausser une carte de votre main : \n");
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
            //verif s'il a bien la carte dans sa main / Cr�ation d'une fonction verif_carte()?
            //verif = verif_carte(j.main, choixCarte);/ //prend la main et la carte souhait�e en param�tre
            //Si la v�rif = 0 alors il n'a pas la carte dans sa main et doit en jouer une.

            verif = verif_carte((*listeJoueur).main, numCarte);

            if(verif == 0)
            {
                printf("Vous ne poss�dez pas cette carte dans votre main veuillez en choisir une nouvelle.\n");
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
            printf("Vous avez gagn� la manche ! \n");
            ajout_Points(listeJoueur, gagnePartie);
            *gagneManche = 1;
        }


    }
    else if(choix == 3)
    {
        printf("Choisir le num de la carte � d�fausser. ");

        scanf("%d", &numCarte);
        verif = verif_carte((*listeJoueur).main, numCarte);
        if(verif == 0)
        {
            printf("Vous ne poss�dez pas cette carte dans votre main veuillez en choisir une nouvelle.\n");
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
