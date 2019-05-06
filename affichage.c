#include"fonctions.h"


//   ---------------------- Regles ------------------------------------//

void regles_jeu(){

	printf("\n \033[36m Othello, aussi connu sous le nom Reversi est un jeu de société.\033[00m \n");
	printf("\033[36m  C’est un jeu de stratégie opposant deux joueurs. Il se joue sur\n  un plateau carré uni-couleur de 64 cases (8 sur 8) appelé othellier.\033[00m\n");
    printf("\033[36m  Les joueurs disposent de 64 pions bicolores ayant une face noire et \n  une face blanche.\033[00m\n\n\n");

    printf("\033[36m  Au départ, il y a deux pions noirs et deux pions blancs placés au centre \n  du plateau comme sur la photo d’othellier.\033[00m ");
    printf("\033[36mChaque joueur à sa couleur.\n  Comparé aux autres jeux de plateau, c’est toujours le joueur ayant les \n  pions noirs qui commence le jeu. \033[00m\n");

    	printf("\n\n\033[32m  Pour plus d'information vous pouvez visiter le cite \n  de la fédération Française d'othello. \033[00m \n");
    	printf("\033[31m\n         http://www.ffothello.org/othello/regles-du-jeu/  \033[00m \n\n");

}

//--------------------------------------------------------------------//


//   ------------------ Affichage du menu ----------------------------//

void menu(void){
	printf("\n\n");
	printf("\033[32m       ##        ##   ######   ##        ##   ##     ## \033[00m\n");
	printf("\033[32m       ## ##  ## ##   ##       ## ##     ##   ##     ##  \033[00m\n");
	printf("\033[32m       ##   ##   ##   ######   ##   ##   ##   ##     ##  \033[00m\n");
	printf("\033[32m       ##        ##   ##       ##     ## ##   ##     ##  \033[00m\n");
	printf("\033[32m       ##        ##   ######   ##        ##     #####    \033[00m\n");



	puts("\n");
	printf("\033[33m            1)Jouer contre l'ordinateur.  \033[00m\n");
	printf("\033[35m            2)Jouer contre un adversaire humain.  \033[00m\n");
	printf("\033[36m            3)Règles du jeu.   \033[00m\n");
	printf("\033[31m            4)Quitter le jeu.  \033[00m\n");

}

//--------------------------------------------------------------------//

//   -----------------  Choix du MENU  -------------------------------//


int choix_menu(){

	 int choix;
	 menu();
	 printf("\nFaites votre choix  :");
	 scanf("%d",&choix);

  switch(choix){
	case 1: printf("\n Vous avez choisi de jouer contre l'ordinateur.\n");
		 	break;

	case 2: printf("\n Vous avez choisi de jouer contre un adversaire humain. \n");
			break;

	case 3: regles_jeu(); printf(" \n1)Retour au menu. \n");
					printf("2)Quitter le jeu. \n"); printf("\nFaites votre choix  :");
					scanf("%d",&choix);
					if(choix==1){ choix_menu();}
					else{ printf("Au revoir !!\n");exit(0);}
			break;

	case 4: printf("Exit \n"); exit(0);
			break;

	default : printf("choix invalide\n");
				choix_menu();

  } return choix;
}
//---------------------------------------------------------------------//

//   -----------  Affichage du score des joueurs  ---------------------//

int score(plateau nb_pions,int joueur){
	int i,j,nb=0;
		for(i=0;i<8;i++){
			for(j=0;j<8;j++){
				if(nb_pions[i][j]==joueur){
					nb++;
				}
			}
		}
				return nb;

}
//---------------------------------------------------------------------//

//   -----------  Affichage d'un plateau  -----------------------------//

void affichage_plateau(plateau affichage){
	int i,j;
	char lettres = 'A';

	printf("\n\n 			Pions \033[32mVERT\033[00m  : \033[32m%d \033[00m \n                        Pions BLANC : %d\n",score(affichage,NOIR),score(affichage,BLANC));

	printf ("\n");                     /// affichage A B C D E F G H
         for (i=0; i<8; i++) {
              printf ("\033[33m %c  \033[00m", lettres);
              lettres++;
            }
    printf ("\n");


 			 for (i= 0; i < 8; i++){
   				 for (j = 0; j < 8; j++){
    					if(affichage[i][j]==BLANC)
    					printf(" %d  ",affichage[i][j]);

    					if(affichage[i][j]==NOIR)

       						printf("\033[32m %d \033[00m ",affichage[i][j]); // 30 noir

       					 if(affichage[i][j]==VIDE)
    						printf(" .  ");

    			  		 if(i<8 && j==7)
    			    		printf("\033[34m%d \033[00m\n",i+1 );
    			    }printf("\n");
				}
}

//---------------------------------------------------------------------//


//     ---------------  Affiche les coups possible  ---------------------------//

void aff_coup_possible (plateau exemple,int joueur) {
   			 int i, j;
   			 	coup_saisi *coup_temp;
   			 	coup_temp = malloc(sizeof(coup_saisi));
   		 printf("\033[36m---------- Coups légaux ----------\033[00m \n\n");

   		 for (i=0; i<8; i++){
   		 		coup_temp->x = i;
       	   for (j=0; j<8; j++){
       	   		coup_temp->y = j;
       	     if (coup_legale(exemple,coup_temp,joueur)){
       	     	char y = 'A';
       	     	y+=j;
       	     	printf(" [\033[33m%c\033[00m\033[34m%d\033[00m] ",y,coup_temp->x+1);
				}  }
			}
			printf(" \n\n\033[36m----------------------------------\033[00m \n\n");
	free(coup_temp);
}

//-------------------------------------------------------------------------//

//    ---------------  Affichage du gagnant de la partie et son score  ------------------------//

void affichage_gagnant(plateau jeu) {

			printf("La partie est terminé\n");
			affichage_plateau(jeu);
			int n = score(jeu,NOIR);
			int b = score(jeu,BLANC);

					if(n>b){
						printf("Les Noirs ont gagné \n");
							printf("score %d contre %d\n",n,b);
					}
					else if(n<b){
						printf("Les Blancs ont gagné \n");
						printf("score %d contre %d\n",b,n);
					}
					else
						printf("Egalité\n");

	}
//------------------------------------------------------------------------------------//
