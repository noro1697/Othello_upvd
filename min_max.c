#include"fonctions.h"



// ----- Clonage d'un plateau pour annuler un coup dans la fonction minmax ----//

		void clone_plateau(plateau copie,plateau origine){
			for(int i=0;i<8;i++)
			for(int j=0;j<8;j++)
			copie[i][j]=origine[i][j];

		}

//----------------------------------------------------------------------------//


//--------------  Fonction d'evaluation pour min_max  --------------------------//

int eval(plateau evaluation){
  return score(evaluation,BLANC) - score(evaluation,NOIR);
}


//--------------------------------------------------------------------------------//



//---------------------------------  Min_Max -----------------------//

int minmax (plateau exemple,int profondeur,int joueur,coup_saisi * final)
{

      if (partie_finit(exemple) || profondeur == 0){
            return eval(exemple);
          }


  int meilleur_score;

   coup_saisi *coup_Best;
   coup_Best = malloc(sizeof(coup_saisi));



            if (joueur == BLANC) {

                  coup_saisi * coup_IAI;
                  coup_IAI = malloc(sizeof(coup_saisi));

                  meilleur_score = -100000;

              for(int i=0;i<8;i++){
                      coup_IAI->x = i;
                  for(int j=0;j<8;j++){
                      coup_IAI->y = j;

                          if (coup_legale(exemple,coup_IAI,joueur)){
                                  plateau copie;
                                  clone_plateau(copie,exemple);

                                  //  printf(" BLANC coup[%d][%d]\n",i+1,j+1);
                                  retourner_pions(copie,coup_IAI,joueur); //Jouer coup legale

                                  int score = minmax(copie,profondeur-1,NOIR,coup_Best);
                                  clone_plateau(copie,exemple);         //Annuler coup

                                  if(score>meilleur_score){
                                    meilleur_score = score;
                                    coup_Best->x = coup_IAI->x;
                                    coup_Best->y = coup_IAI->y;
                                    final->x = coup_Best->x;
                                    final->y = coup_Best->y;//Notre variable qui va stocker le coup final qu'on recupere dans le main.
                                    }
                              }
                    }
                }
                free(coup_IAI);
           }

           else {

                coup_saisi * coup_IAI;
                coup_IAI = malloc(sizeof(coup_saisi));

                meilleur_score = +10000;

                      for(int i=0;i<8;i++){
                              coup_IAI->x = i;
                          for(int j=0;j<8;j++){
                              coup_IAI->y = j;

                                  if (coup_legale(exemple,coup_IAI,joueur)){
                                          plateau copie_N;
                                          clone_plateau(copie_N,exemple);

                                          //  printf(" NOIR coup[%d][%d]\n",i+1,j+1);
                                          retourner_pions(copie_N,coup_IAI,joueur);// Jouer coup legal

                                          int score = minmax(copie_N,profondeur-1,BLANC,coup_Best);

                                          clone_plateau(copie_N,exemple); // Annulation du coup

                                            if(score<meilleur_score){
                                                meilleur_score = score;

                                                coup_Best->x = coup_IAI->x;
                                                coup_Best->y = coup_IAI->y;
                                              }
                                    }
                            }
                        }
                        free(coup_IAI);
                }

//  printf("Final [%d][%d] \n\n",final->x+1,final->y+1);
  free(coup_Best);

  return meilleur_score;
}

//---------------------------------------------------------------------------//
