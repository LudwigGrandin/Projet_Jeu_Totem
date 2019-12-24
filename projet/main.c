#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "libraryProjet.h"


struct TCarte listeCartes[64];

int main(){

        /* le paquet fait 64 cartes mais le premier id prendra 0
            pour le moment le paquet sera pleins donc id max = 64-1
            TODO : selon le nbr de joueurs des cartes seront à retirer
        */
        int idCarteMin =0;
        int idCarteMax=63;
        //TPile laPioche;

        // Va contenir le tableau de nombres qui servira à remplir la pioche
        int* tabNum = NULL;

        printf("Affichage de debug 1");
        init_sans_doublons(tabNum,idCarteMin,idCarteMax);
        init_ListeCarte(listeCartes,42,2);

        //affichage pour debug
        printf("Affichage de debug 4");
        //afficherCartes(listeCartes,42);

        //init_pioche(tabNum,idCarteMax-idCarteMin,laPioche);

       // Ne pas oublier de libérer la mémoire
       free(tabNum);
       // depiler(pioche);

     return 0;
}
/*
      if(i>= 0 && i <=4){
        carte.num = i;
        strcpy(carte.effet,"Lorsque Tete de coyote arrive en jeu, vous pouvez voler le totem d'un joueur et lui donner le votre.");
        carte.type = 1;
        strcpy(carte.nom,"Tete de Coyote");
      }
      else if(i>= 5 && i <=9){
        carte.num = i;
        strcpy(carte.effet,"Aucun Joueur ne peut vous voler votre totem ou des étages de votre totem.");
        carte.type = 1;
        strcpy(carte.nom, "Tete d'Aigle");
      }
      else if(i>= 10 && i <= 14){
        carte.num = i;
        strcpy(carte.effet,"Lorsque Tete de loup arrive en jeu, vous pouvez voler 2 cartes au hasard dans la main d'un joueur adverse.");
        carte.type = 1;
        strcpy(carte.nom, "Tete de Loup");
      }
      else if(i>= 15 && i <= 19){
        carte.num = i;
        strcpy(carte.effet,"Lorsque Tete de corbeau arrive en jeu, vous pouvez echanger votre main avec celle d'un autre joueur.");
        carte.type = 1;
        strcpy(carte.nom,"Tete de Corbeau");
      }
      else if(i>= 20 && i <= 24){
        carte.num = i;
        strcpy(carte.effet,"A la fin de chacun de vos tours vous pouvez piocher 3 cartes. En choisir une puis défausser les 2 autres.");
        carte.type = 1;
        strcpy(carte.nom,"Tete de Lynx");
      }
      else if(i>= 25 && i <= 29){
        carte.num = i;
        strcpy(carte.effet,"Aucun Joueur ne peut détruire votre totem ou des etages de votre totem.");
        carte.type = 1;
        strcpy(carte.nom,"Tete de Tortue");
      }
      else if(i>= 30 && i <= 34){
        carte.num = i;
        strcpy(carte.effet,"Lorsque Tete d'ours arrive en jeu, vous pouvez detruire le dernier etage du totem d'un joueur.");
        carte.type = 1;
        strcpy(carte.nom,"Tete d'ours");
      }
      else if(i == 35){
        carte.num = i;
        strcpy(carte.effet,"Vous gagner la partie aussi");
        carte.type = 0;
        strcpy(carte.nom,"On arrive");
      }
      else if(i>= 36 && i <= 39){
        carte.num = i;
        strcpy(carte.effet,"Detruisez le dernier etage d'un totem");
        carte.type = 0;
        strcpy(carte.nom,"Et paf");
      }
      else if(i>= 40 && i <= 42){
        carte.num = i;
        strcpy(carte.effet,"Chaque joueur doit donner son totem au joueur se trouvant à sa gauche.");
        carte.type = 0;
        strcpy(carte.nom,"Esprit Farceur");
      }
      else if(i>= 43 && i <= 47){
        carte.num = i;
        strcpy(carte.effet,"Annuler l'action d'un joueur, si vous annuler un autre Faux Pas piocher 2 cartes, sinon rejouez immediatement.");
        carte.type = 0;
        strcpy(carte.nom,"Faux Pas");
      }
       else if(i>= 48 && i <= 52){
        carte.num = i;
        strcpy(carte.effet,"Volez et mettez dans votre main le dernier etage du totem d'un joueur. Si votre totem possede moins de 4 etages. Rejouez immediatement.");
        carte.type = 0;
        strcpy(carte.nom,"Pillage");
      }
        else if(i>= 53 && i <= 55){
            carte.num = i;
            strcpy(carte.effet,"Detruisez les 2 derniers etages d'un totem.");
            carte.type = 0;
            strcpy(carte.nom,"Bison Dingo");
      }
      else if(i>= 56 && i <= 59){
        carte.num = i;
        strcpy(carte.effet,"Volez une tete au sommet d'un totem pour le placer au sommet d'un totem adverse. Puis piochez 1 carte.");
        carte.type = 0;
        strcpy(carte.nom,"Cadeau");
      }
      else if(i>= 60 && i <= 63){
        carte.num = i;
        strcpy(carte.effet,"Piochez 2 cartes puis rejouez immediatement");
        carte.type = 0;
        strcpy(carte.nom,"Eau de feu");
      }
*/
/*
switch(i){
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

*/

