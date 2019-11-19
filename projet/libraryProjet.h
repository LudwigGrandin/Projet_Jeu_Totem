#ifndef _PROTO_H_
#define _PROTO_H_

typedef struct TCarte
{
	char nom[30];
	char effet[100];
	int num;
	int type; 
}TCarte;

typedef struct TPilelem
{
	TCarte carte;
	struct TPileElem *suivant;
}TPilelem, *TPile;

int est_pile_vide(TPile p);
void empiler(TPile, TCarte c);
void depiler(TPile p);




#endif