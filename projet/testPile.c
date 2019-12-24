#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libraryProjet.h"
#include <time.h>

	/* Définition d'une carte */
/*
int main(){
        // A ne pas oublier !
        srand(time(NULL));

        // le paquet fait 64 cartes mais le premier id prendra 0
        // pour le moment le paquet sera pleins donc id max = 64-1
        // TODO : selon le nbr de joueurs des cartes seront à retirer

        int idCarteMin =0;
        int idCarteMax=63;
        //TPile laPioche;

        // Va contenir le tableau de nombres qui servira à remplir la pioche
        int* tabNum ;
        TCarte listeCartes[64];

        init_sans_doublons(tabNum,idCarteMin,idCarteMax);
        init_ListeCarte(listeCartes,64,2);
        //affichage pour debug
        printf("Affichage de debug");
        afficherCartes(listeCartes,64);

        //init_pioche(tabNum,idCarteMax-idCarteMin,laPioche);

       // Ne pas oublier de libérer la mémoire
       free(tabNum);
       // depiler(pioche);

      printf("\n Entree une touche pour sortir");
      getchar();

     return 0;
}
*/
/**MainLudwig**/
/*

//test de toutes les procédures.
    TPile pile;
	init_pile(&pile);
	TCarte carte;
	carte.num = 0;
	int nombreCarte = 2;

	//fflush(stdout);
    /** carte0 **/
/*    (*carte.nom) = "Carte0";
    printf("nom test = %s\n", (&carte.nom));
    (*carte.effet) = "25";
    carte.num = 1;
    empiler(&pile, &carte);
    /** carte1 **/
 /*   (*carte.nom) = "carte1";
    (*carte.effet) = "26";
    carte.num++;
    empiler(&pile, &carte);
    /** carte2 **/
/*    (*carte.nom) = "carte2";
    (*carte.effet) = "27";
    carte.num ++;
    empiler(&pile, &carte);*/


	/*for(int i = 0; i <= nombreCarte; i ++){				// saisie des données à la main pour tester empiler

		printf("Carte numéro : %d \n",i);

		printf("Entrer un nom de carte \n");
		fflush(stdout);
		scanf("%s", carte.nom);

		printf("Entrer un effet de carte \n");
		fflush(stdout);
		scanf("%s", carte.effet);

		carte.num++;
		carte.type = 1;

		empiler(&pile, &carte);
	}*/
	//afficher_pile(pile);
    //system("cls");
    //affiche la pile avant depiler

    //char nom[1000] = "";
/*    for(int i = 0; i <= nombreCarte; i ++)
    {
        //depiler(&pile, &carte);
       // nom = (*carte).(*nom);
        printf("le num de la carte est %d \n", carte.num);	//verification des données prises par la carte en param
        printf("le nom de la carte est %s \n", carte.nom);
        printf("l effet de la carte est %d \n", carte.effet);
        printf("\n\n");
    }

//	taille = taille_pile(pile);
//	printf("%d", taille);
	liberer_pile(&pile, &carte); // libère toute la pile
	//afficher_pile(pile);*/

/**Main Lucas**/
/*
int main(){

    //int taille = 0;
	//struct TPile pile;

//test de toutes les procédures.

	int taille = 0;
	struct TPile pile;
	struct TCarte *cartest;
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
	cartest = depiler(&pile);
	printf("le num de la carte est %d \n", (*cartest).num);	//verification des données prises par la carte en param
	printf("le num de la carte est %s \n", (*cartest).nom);
	printf("le num de la carte est %s \n", (*cartest).effet);
	afficher_pile(pile);
//	taille = taille_pile(pile);
//	printf("%d", taille);
	liberer_pile(&pile); // libère toute la pile
	afficher_pile(pile);

	return 0;
}
*/
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

TCarte * depiler(TPile * pile)
{
	int verif;
	TCarte * c;
	c = (TCarte*) malloc(sizeof(TCarte));
	struct TPilelem *aux;
	verif = est_pile_vide(*pile);

	aux = (*pile).sommet;
	if(verif == 1) // la pile est vide
	{
		printf("Rien à dépiler, la pile est vide \n");
	}
	else
	{
		(*pile).sommet = (*aux).suivant;
		strcpy((*c).nom , (*aux).carte.nom);
		strcpy((*c).effet , (*aux).carte.effet);
		(*c).num = (*aux).carte.num;
		//(*c).type = (*aux).type;
		free(aux);
	}
	return c;
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
		while(aux != NULL)
	{
		printf("[%d]\n", (*aux).carte.num);
		aux = (*aux).suivant;
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

	if((*main).debut == NULL){
		printf("La liste est vide, rien à supprimer");
	}

	while(aux != NULL){

		(*main).debut = (*aux).suivant;
		free(aux);
		aux = (*main).debut;
	}
}

void tete_coyote(TJoueur * j1, TJoueur * j2, TJoueur * jint) // créer un joueur jint dans le main ?
{

	(*jint).totem = (*j1).totem;
	(*j1).totem = (*j2).totem;
	(*j2).totem = (*jint).totem;

}

/*void cadeau(TPile * totem1, TPile * totem2)
{
	struct TCarte *aux;

	depiler(totem2);

	empiler(totem1, (*(*totem2).sommet).carte);

}

//suivant la carte que le joueur joue
void immunite_totem(TJoueur * j)
{


}



/*void DeposerCarteTotem(TPile totem, int numCarteMain, TMain *mainJoueur)
{
    int trouve = 0;
    TPilelem *aux;
    TPilelem *prec;

    aux =  (*mainJoueur).debut;
    prec = (*mainJoueur).debut;

    while(aux != NULL && trouve == 0 )
    {
        if( (*aux).carte.num  == )
        {
            //si la carte est une tête
            if((*aux).carte.type = 1)
            {
                trouve = 1;
                empiler(*totem, aux);
            }


       }
       prec = aux;
       aux = (*aux).suivant;
    }

}
*/

/********************************************PIOCHE************************************************/

void init_sans_doublons(int* tableau,int a, int b){
	int taille = b-a;
    //printf("\nTaille du paquet: %d \n",taille);

    tableau = malloc((taille)*sizeof (int));
	int i=0;
	//remplit le tableau de façon croissant
	for(i = 0; i< taille; i++){
		tableau[i]=i+a;
	}
}

void melanger(int* tableau, int taille){
	// A ne pas oublier !
    srand(time(NULL));
	int i=0;
	int nombre_tire=0;
	int temp=0;

	for(i = 0; i< taille;i++){
		nombre_tire= rand()%64+1;
		// On échange les contenus des cases i et nombre_tire
		temp = tableau[i];
		tableau[i] = tableau[nombre_tire];
		tableau[nombre_tire]=temp;
	}
}
//a completer
void init_pioche(int* tableau,int taille, TPile pioche){

   // init_pile(pioche);
    melanger(tableau,taille);
    //init_ListeCarte(nbCarte,nbJoueur);

    for(int i=0;i<taille;i++){

    }

}
//initialise la liste des cartes mais bien géré les cartes exclus
void init_ListeCarte(TCarte* liste,int nbCarte,int nbJoueur){
    //lexique
    TCarte carte;

    //init de toutes les cartes
    for(int i = 0; i < nbCarte;i++){

       switch(i){
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
                strcpy(carte.effet,"Lorsque Tete de coyote arrive en jeu, vous pouvez voler le totem d'un joueur et lui donner le votre.");
                carte.type = 1;
                strcpy(carte.nom,"Tete de Coyote");
                break;
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
                strcpy(carte.effet,"Aucun Joueur ne peut vous voler votre totem ou des étages de votre totem.");
                carte.type = 1;
                strcpy(carte.nom, "Tete d'Aigle");
                break;
            case 10:
            case 11:
            case 12:
            case 13:
            case 14:
                strcpy(carte.effet,"Lorsque Tete de loup arrive en jeu, vous pouvez voler 2 cartes au hasard dans la main d'un joueur adverse.");
                carte.type = 1;
                strcpy(carte.nom, "Tete de Loup");
                break;
            case 15:
            case 16:
            case 17:
            case 18:
            case 19:
                strcpy(carte.effet,"Lorsque Tete de corbeau arrive en jeu, vous pouvez echanger votre main avec celle d'un autre joueur.");
                carte.type = 1;
                strcpy(carte.nom,"Tete de Corbeau");
                break;
            case 20:
            case 21:
            case 22:
            case 23:
            case 24:
                strcpy(carte.effet,"A la fin de chacun de vos tours vous pouvez piocher 3 cartes. En choisir une puis défausser les 2 autres.");
                carte.type = 1;
                strcpy(carte.nom,"Tete de Lynx");
                break;
            case 25:
            case 26:
            case 27:
            case 28:
            case 29:
                strcpy(carte.effet,"Aucun Joueur ne peut détruire votre totem ou des etages de votre totem.");
                carte.type = 1;
                strcpy(carte.nom,"Tete de Tortue");
                break;
            case 30:
            case 31:
            case 32:
            case 33:
            case 34:
                strcpy(carte.effet,"Lorsque Tete d'ours arrive en jeu, vous pouvez detruire le dernier etage du totem d'un joueur.");
                carte.type = 1;
                strcpy(carte.nom,"Tete d'ours");
                break;
            case 35:
                strcpy(carte.effet,"Vous gagner la partie aussi");
                carte.type = 0;
                strcpy(carte.nom,"On arrive");
                break;
            case 36:
            case 37:
            case 38:
            case 39:
                strcpy(carte.effet,"Detruisez le dernier etage d'un totem");
                carte.type = 0;
                strcpy(carte.nom,"Et paf");
            case 40:
            case 41:
            case 42:
                strcpy(carte.effet,"Chaque joueur doit donner son totem au joueur se trouvant à sa gauche.");
                carte.type = 0;
                strcpy(carte.nom,"Esprit Farceur");
            case 43:
            case 44:
            case 45:
            case 46:
            case 47:
                strcpy(carte.effet,"Annuler l'action d'un joueur. Si vous annuler un autre Faux Pas piocher 2 cartes, sinon rejouez immediatement.");
                carte.type = 0;
                strcpy(carte.nom,"Faux Pas");
            case 48:
            case 49:
            case 50:
            case 51:
            case 52:
                strcpy(carte.effet,"Volez et mettez dans votre main le dernier etage du totem d'un joueur. Si votre totem possede moins de 4 etages. Rejouez immediatement.");
                carte.type = 0;
                strcpy(carte.nom,"Pillage");
            case 53:
            case 54:
            case 55:
                strcpy(carte.effet,"Detruisez les 2 derniers etages d'un totem.");
                carte.type = 0;
                strcpy(carte.nom,"Bison Dingo");
            case 56:
            case 57:
            case 58:
            case 59:
                strcpy(carte.effet,"Volez une tete au sommet d'un totem pour le placer au sommet d'un totem adverse. Puis piochez 1 carte.");
                carte.type = 0;
                strcpy(carte.nom,"Cadeau");
            case 60:
            case 61:
            case 62:
            case 63:
                strcpy(carte.effet,"Piochez 2 cartes puis rejouez immediatement");
                carte.type = 0;
                strcpy(carte.nom,"Eau de feu");
       }
       carte.num = i;
       liste[i] = carte;
    }
}


void afficherCartes(TCarte* listeCartes,int taille){
    for(int i = 0; i< taille ; i++){
        printf("\nCarte num: %d , nom: %s\n",listeCartes[i].num,listeCartes[i].nom);
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


