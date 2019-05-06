//fonctions.h
#include<stdio.h>
#include<stdlib.h>

#define NOIR   0
#define BLANC  1
#define VIDE   2

//   ----------------------  Structures et Varibales  -----------------------

typedef int plateau[8][8];
int nombre_pions_joueur[2];

struct coup
{
	int x,y;
} ;

typedef  struct coup coup_saisi;

//--------------------------------------------------------------------------


//   ----------------------  Affichage.c  ----------------------//

void regles_jeu(void);

void menu(void);

int choix_menu(void);

int score(plateau,int);

void affichage_plateau(plateau);

void aff_coup_possible (plateau,int);

void affichage_gagnant(plateau);

//------------------------------------------------------


//    ----------- Fonctions Verification et retournement de coup.c  -------------//

int coup_legale(plateau,coup_saisi (*),int);

int retourner_pions(plateau,coup_saisi (*),int );

//----------------------------------------------------------------------------//


//   ----------------------  Fonctions Basiques   fonctions.c  ----------------------//

void initialiser_plateau(plateau);

int coup_interieur_plateau(coup_saisi (*));

int changement_joueur (int);

int coup_possible (plateau,int);

int partie_finit(plateau);

coup_saisi * entrer_coup(plateau ,coup_saisi (*), int);

	int difficulte(void);

//----------------------------------------------------------------------------------//


// ---------------------------  Partie IA ---------------------//


void clone_plateau(plateau,plateau);

int eval(plateau);

int minmax (plateau,int,int,coup_saisi (*) );

//--------------------------------------------------------------//
