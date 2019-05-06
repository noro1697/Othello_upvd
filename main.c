#include<stdio.h>
#include<stdlib.h>
#include"fonctions.h"

int main(void){

	int type=0;

	printf("\n                  \033[32m   Bienvenu sur \"OTHELLO\".\033[00m \n"); 

	do{

		int pions_retourne=0;
		int joueur = NOIR;

		plateau othellier;
		initialiser_plateau(othellier);

		coup_saisi *coup_joueur;
		coup_joueur = malloc(sizeof(coup_saisi));
		type = choix_menu(); // Recuperation de mode de jeu

			if(type == 1){
				int profondeur = difficulte();     //Jeu contre l'ordinateur
				while(!partie_finit(othellier)){

						if(coup_possible(othellier,joueur)){

										if(joueur==NOIR){

													affichage_plateau(othellier);
													printf("%d pion(s) retourné\n",pions_retourne);
													printf("Joueur %d doit jouer \n",joueur);
													aff_coup_possible(othellier,joueur);

													coup_joueur = entrer_coup(othellier,coup_joueur,joueur); //Demande de saisir un coup
													pions_retourne = retourner_pions(othellier,coup_joueur,joueur); //Joue le coup saisie

												}

														if (joueur==BLANC){

															affichage_plateau(othellier);
															printf("%d  retourné\n",pions_retourne);
															printf("Joueur %d doit jouer \n",joueur);
															aff_coup_possible(othellier,joueur);

															minmax(othellier,profondeur,BLANC,coup_joueur); //appel fonction IA profondeur 4
															pions_retourne = retourner_pions(othellier,coup_joueur,joueur); //Joue le coup choisi par IA
														}
											joueur = changement_joueur(joueur);
										}
										else{
												joueur = changement_joueur(joueur);
											}

							}

							 affichage_gagnant(othellier);

							}

					if(type==2){
								while(!partie_finit(othellier)) {

											if(!coup_possible(othellier,joueur)){
												joueur = changement_joueur(joueur);}

													affichage_plateau(othellier);
													printf("%d pion(s) retourné\n",pions_retourne);
													printf("Joueur %d doit jouer \n",joueur);
										 			aff_coup_possible(othellier,joueur);

										 coup_joueur = entrer_coup(othellier,coup_joueur,joueur);
										 pions_retourne = retourner_pions(othellier,coup_joueur,joueur);

									joueur = changement_joueur(joueur);
								}

						affichage_gagnant(othellier);
					}
				free(coup_joueur);
	}while(type!=4);

	return 0;

	}
