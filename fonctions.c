#include"fonctions.h"


//    ------------  Initialisation du plateau  ------------------//

void initialiser_plateau(plateau init)
{
	int i,j;
	  for (i = 0; i < 8; i++){
	    for (j = 0; j < 8; j++){
	      init[i][j] = VIDE;
	    }
	  }

  init[3][4] = init[4][3] = NOIR;
  init[3][3] = init[4][4] = BLANC; //Placement des pions de depart

}

//------------------------------------------------------------//


//    ------------  Verification des coordonnes dans le plateau  ------//

int coup_interieur_plateau(coup_saisi *coup){
		int resultat;
			resultat = ((coup->x>=0 && coup->x<8) && (coup->y>=0 && coup->y<8));
	return resultat;
}

// ---------------------------------------------------------------//


//    ------------  Changement de joueur  -------------------//

int changement_joueur (int joueur) {
       if(joueur ==NOIR)
       		 return BLANC;
       		else
       		 return NOIR;
}
//-----------------------------------------------------------//



//    ---------------  Verification s'il existe un coup possible  -----------------//

int coup_possible (plateau exemple,int joueur) {

				 int i, j,ok = 0;
   			 	coup_saisi *coup_temp;
   			 	coup_temp = malloc(sizeof(coup_saisi));

			 for (i=0; i<8; i++){
   		 		coup_temp->x = i;
       	   for (j=0; j<8; j++){
       	   		coup_temp->y = j;

       	     		if (coup_legale(exemple,coup_temp,joueur)){
       	     					ok =1;
									}
					 }
			  }

		if(ok == 1){
				free(coup_temp);
					return 1;
			}
				else{
					free(coup_temp);
					return 0;
				}

}
//------------------------------------------------------------------------//



//    ---------------  Verification si la partie est finit  ------------------------//

int partie_finit (plateau finit) {

    for (int i=0; i<8; i++){
        for (int j=0; j<8; j++){
            if (finit[i][j] == VIDE && (coup_possible(finit,NOIR) || coup_possible(finit,BLANC)))
                return 0;
        }
    }
       return 1;
}

//------------------------------------------------------------------------------------//


//--------------------------  Permet de saisir un coup  ------------------------------//

coup_saisi * entrer_coup(plateau othellier,coup_saisi *coup,int joueur){

	int i,j;
	char coordonne[4]; //Pour eviter un probleme de stack si jamais cordonne saisie contiens plus que 2 caracteres

		do {

			printf("Saisir le coup (ex. A1)  :  ");
			scanf("%s",coordonne);
			i = coordonne[1] - 49;
			j = coordonne[0] - 65;

				coup->x = i;
				coup->y = j;

			if(!coup_legale(othellier,coup,joueur))
				printf("Erreur le coup n'est pas legal\n");

		}while(!coup_legale(othellier,coup,joueur));

		return coup;

}

//-------------------------------------------------------------------------//


//------------Fonction demandant de saisir le niveau de dificulté de IA -----------//
	int difficulte(void){
		int profondeur=0;

			do{
				printf("\nSaisir la dificulté de IA de 2-6 (4 conseillé)  :");
				scanf("%d",&profondeur);
			}while(profondeur<2 || profondeur>6);

	return profondeur;
	}

//--------------------------------------------------------------------------------//
