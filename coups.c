#include"fonctions.h"


//    ------------------------  Verification de la légalité d'un coup  ------------------------------//

int coup_legale(plateau verification,coup_saisi *coup,int joueur){

 if(verification[coup->x][coup->y]!=VIDE){
          return 0;
  }

      int legal=0 ;
      int joueur_courrant,autre_joueur;

        if (joueur == NOIR){
            joueur_courrant = NOIR;
            autre_joueur = BLANC;
        } else {
                joueur_courrant = BLANC;
                  autre_joueur = NOIR;
              }


		if(!coup_interieur_plateau(coup)){
			printf("Dehors d'Othelier\n");
			return legal;
		}


		      coup_saisi *coup_temp;
		      coup_temp = malloc(sizeof(coup_saisi));

            		//----------- Vertical vers le haut -----------------------

                		coup_temp->x = coup->x - 1;
                		coup_temp->y = coup->y;
                		legal = 0;
                while (coup_interieur_plateau(coup_temp) && verification[coup_temp->x][coup_temp->y] == autre_joueur) {
                 	    coup_temp->x--;
                    	legal = 1;
                }
                	if (coup_interieur_plateau(coup_temp) && verification[coup_temp->x][coup_temp->y] == joueur_courrant && legal == 1){free(coup_temp); return legal;}

                // ---------- Vertical vers le bas ----------------------------

            		    coup_temp->x = coup->x + 1;
                		coup_temp->y = coup->y;
                		legal = 0;
               while (coup_interieur_plateau(coup_temp) && verification[coup_temp->x][coup_temp->y] == autre_joueur) {
                    	coup_temp->x++;
                    	legal = 1;
                }
                	if (coup_interieur_plateau(coup_temp) && verification[coup_temp->x][coup_temp->y] == joueur_courrant && legal == 1) {free(coup_temp); return legal;}


              		//------------- Horizontal vers la gauche  ----------

                		coup_temp->x = coup->x;
                		coup_temp->y = coup->y - 1;
                		legal = 0;
                while (coup_interieur_plateau(coup_temp) && verification[coup_temp->x][coup_temp->y] == autre_joueur) {
                    	coup_temp->y--;
                    	legal = 1;
                }
                	if (coup_interieur_plateau(coup_temp) && verification[coup_temp->x][coup_temp->y] == joueur_courrant && legal == 1) {free(coup_temp); return legal;}

               		//------------- Horizontal vers la droite  -----------------

                		coup_temp->x = coup->x;
                		coup_temp->y = coup->y + 1;
                		legal = 0;
                while (coup_interieur_plateau(coup_temp) && verification[coup_temp->x][coup_temp->y] == autre_joueur) {
                    	coup_temp->y++;
                    	legal = 1;
                }
                	if (coup_interieur_plateau(coup_temp) && verification[coup_temp->x][coup_temp->y] == joueur_courrant && legal == 1) {free(coup_temp); return legal;}

              		//--------------  Diagonale vers le côté gauche en haut  -----------

                		coup_temp->x = coup->x - 1;
                		coup_temp->y = coup->y - 1;
                		legal = 0;
                while (coup_interieur_plateau(coup_temp) && verification[coup_temp->x][coup_temp->y] == autre_joueur) {
                  		coup_temp->x--;
                  		coup_temp->y--;
                    	legal = 1;
                }
                	if (coup_interieur_plateau(coup_temp) && verification[coup_temp->x][coup_temp->y] == joueur_courrant && legal == 1) {free(coup_temp); return legal;}

                	//-------------   Diagonale  vers le côté droit en haut  -----------

                		coup_temp->x = coup->x - 1;
                		coup_temp->y = coup->y + 1;
                		legal = 0;
                while (coup_interieur_plateau(coup_temp) && verification[coup_temp->x][coup_temp->y] == autre_joueur) {
                    	coup_temp->x--;
                    	coup_temp->y++;
                    	legal = 1;
                }
                	if (coup_interieur_plateau(coup_temp) && verification[coup_temp->x][coup_temp->y] == joueur_courrant && legal == 1) {free(coup_temp); return legal;}

                //-------------- Diagonale  vers le côté gauche en bas  -----------

                		coup_temp->x = coup->x + 1;
                		coup_temp->y = coup->y - 1;
                		legal = 0;

                while (coup_interieur_plateau(coup_temp) && verification[coup_temp->x][coup_temp->y] == autre_joueur) {
                    	coup_temp->x++;
                		coup_temp->y--;
                		legal = 1;

                }
                	if (coup_interieur_plateau (coup_temp) && verification[coup_temp->x][coup_temp->y] == joueur_courrant && legal == 1) {free(coup_temp); return legal;}

                  //-------------- Diagonale  vers le côté droit en bas  -----------

                		coup_temp->x = coup->x + 1;
                		coup_temp->y = coup->y + 1;
                		legal = 0;
                while (coup_interieur_plateau(coup_temp) && verification[coup_temp->x][coup_temp->y] == autre_joueur) {
                  		coup_temp->x++;
               	  		coup_temp->y++;
               	  		legal = 1;

                }
                	if (coup_interieur_plateau (coup_temp) && verification[coup_temp->x][coup_temp->y] == joueur_courrant && legal == 1) {free(coup_temp); return legal;}

      	else return 0;


    	}

//--------------------------------------------------------------------------------------------------------------------//



//    ------------------------------------  Retournement des pions  -------------------------------------------//

int retourner_pions(plateau temp,coup_saisi *depart,int joueur){



	if(temp[depart->x][depart->y] !=VIDE) return 0;

	 temp[depart->x][depart->y] = joueur;
	  int nb_pions_retourne = 0;//mettre a 1 pour compter le pions placé aussi

          	coup_saisi *coup_temp;
          		 coup_temp = malloc(sizeof(coup_saisi));

          //----------- Vers le Haut ----------------------

          			coup_temp->x = depart->x - 1;
              		coup_temp->y = depart->y;
              while (coup_interieur_plateau(coup_temp) && temp[coup_temp->x][coup_temp->y] == !joueur)
               	    coup_temp->x--;
              	if (coup_interieur_plateau(coup_temp) && temp[coup_temp->x][coup_temp->y] == joueur)
              		 coup_temp->x = depart->x - 1;
              		while(temp[coup_temp->x][depart->y]==!joueur){
              			temp[coup_temp->x][depart->y] = joueur;
              			nb_pions_retourne++;
              			coup_temp->x--;
              		}

          //------------  Vers le Bas  ------------------------

              		coup_temp->x = depart->x + 1;
              		coup_temp->y = depart->y;
              while (coup_interieur_plateau(coup_temp) && temp[coup_temp->x][coup_temp->y] == !joueur)
              		coup_temp->x++;
              	if (coup_interieur_plateau(coup_temp) && temp[coup_temp->x][coup_temp->y] == joueur) {
                  	coup_temp->x = depart->x + 1;
                  while (temp[coup_temp->x][coup_temp->y] == !joueur) {
                      temp[coup_temp->x][coup_temp->y] = joueur;
                      nb_pions_retourne++;
                      coup_temp->x++;
                  }
              }

          //------------  Horizontal vers la gauche  --------------

              		coup_temp->x = depart->x;
              		coup_temp->y = depart->y-1;
              while (coup_interieur_plateau(coup_temp) && temp[coup_temp->x][coup_temp->y] == !joueur)
              		coup_temp->y--;
              	if (coup_interieur_plateau(coup_temp) && temp[coup_temp->x][coup_temp->y] == joueur) {
                  	coup_temp->y = depart->y - 1;
                  while (temp[coup_temp->x][coup_temp->y] == !joueur) {
                      temp[coup_temp->x][coup_temp->y] = joueur;
                      nb_pions_retourne++;
                      coup_temp->y--;
                  }
              }

          //-------------  Horizontal vers la droite ---------------------

              		coup_temp->x = depart->x;
              		coup_temp->y = depart->y+1;
              while (coup_interieur_plateau(coup_temp) && temp[coup_temp->x][coup_temp->y] == !joueur)
              		coup_temp->y++;
              	if (coup_interieur_plateau(coup_temp) && temp[coup_temp->x][coup_temp->y] == joueur) {
                  	coup_temp->y = depart->y + 1;
                  while (temp[coup_temp->x][coup_temp->y] == !joueur) {
                      temp[coup_temp->x][coup_temp->y] = joueur;
                      nb_pions_retourne++;
                      coup_temp->y++;
                  }
              }

          //--------------  Diagonale vers le côté gauche en haut  -------------------------

          		coup_temp->x = depart->x-1;
              	coup_temp->y = depart->y-1;

              while (coup_interieur_plateau(coup_temp) && temp[coup_temp->x][coup_temp->y] == !joueur){
              		coup_temp->x--;
              		coup_temp->y--;
              	}
              	if (coup_interieur_plateau(coup_temp) && temp[coup_temp->x][coup_temp->y] == joueur) {
                  	coup_temp->x = depart->x-1;
              		coup_temp->y = depart->y-1;
                  while (temp[coup_temp->x][coup_temp->y] == !joueur) {
                      temp[coup_temp->x][coup_temp->y] = joueur;
                      nb_pions_retourne++;
                      coup_temp->x--;
              		coup_temp->y--;
                  }
              }

          //------------------- Diagonale vers le côté droit en  haut ----------------

          		coup_temp->x = depart->x-1;
              	coup_temp->y = depart->y+1;
              while (coup_interieur_plateau(coup_temp) && temp[coup_temp->x][coup_temp->y] == !joueur){
              		coup_temp->x--;
              		coup_temp->y++;}
              	if (coup_interieur_plateau(coup_temp) && temp[coup_temp->x][coup_temp->y] == joueur) {
                  	coup_temp->x = depart->x-1;
              		coup_temp->y = depart->y+1;
                  while (temp[coup_temp->x][coup_temp->y] == !joueur) {
                      temp[coup_temp->x][coup_temp->y] = joueur;
                      nb_pions_retourne++;
                      coup_temp->x--;
              		coup_temp->y++;
                  }
              }

          //--------------------  Diagonale vers le côté gauche en bas ---------------------------

              	coup_temp->x = depart->x+1;
              	coup_temp->y = depart->y-1;
              while (coup_interieur_plateau(coup_temp) && temp[coup_temp->x][coup_temp->y] == !joueur){
              		coup_temp->x++;
              		coup_temp->y--;}
              	if (coup_interieur_plateau(coup_temp) && temp[coup_temp->x][coup_temp->y] == joueur) {
                  	coup_temp->x = depart->x+1;
              		coup_temp->y = depart->y-1;
                  while (temp[coup_temp->x][coup_temp->y] == !joueur) {
                      temp[coup_temp->x][coup_temp->y] = joueur;
                      nb_pions_retourne++;
                      coup_temp->x++;
              		coup_temp->y--;
                  }
              }

           //---------------  Diagonale vers le côté droit en bas ---------------------------

             	 	coup_temp->x = depart->x+1;
              	coup_temp->y = depart->y+1;
              while (coup_interieur_plateau(coup_temp) && temp[coup_temp->x][coup_temp->y] == !joueur){
              		coup_temp->x++;
              		coup_temp->y++;}
              	if (coup_interieur_plateau(coup_temp) && temp[coup_temp->x][coup_temp->y] == joueur) {
                  	coup_temp->x = depart->x+1;
              		coup_temp->y = depart->y+1;
                  while (temp[coup_temp->x][coup_temp->y] == !joueur) {
                      temp[coup_temp->x][coup_temp->y] = joueur;
                      nb_pions_retourne++;
                      coup_temp->x++;
              		coup_temp->y++;
                  }
              }
   		  free(coup_temp);
	 return nb_pions_retourne;
}

//---------------------------------------------------------------------------------------------------------------------------------//
