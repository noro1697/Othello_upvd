#Compilateur
CC = gcc
#Nom d'executable
EXEC = othello
#Flags pour warnings
CFLAGS = -Wall
LDFLAGS = -Wall

#Fichiers .c

AFFICHAGE = affichage.c
COUPS = coups.c
FONCTIONS = fonctions.c
MAIN = main.c
IA = min_max.c

#Fichiers .o

AFFICHAGE.O = affichage.o
COUPS.O = coups.o
FONCTIONS.O = fonctions.o
MAIN.O = main.o
IA.O = min_max.o


compile: $(MAIN) $(FONCTIONS) $(COUPS) $(AFFICHAGE) $(IA)
	@echo "Compilation et creation d'executable du projet  : "
	$(CC) -c $(FONCTIONS) $(CFLAGS)
	$(CC) -c $(COUPS) $(CFLAGS)
	$(CC) -c $(AFFICHAGE) $(CFLAGS)
	$(CC) -c $(IA) $(CFLAGS)
	$(CC) -c $(MAIN) $(CFLAGS)
	$(CC)  -o $(EXEC) $(MAIN.O) $(FONCTIONS.O) $(COUPS.O)  $(AFFICHAGE.O) $(IA.O) $(LDFLAGS)

execute: $(EXEC)
	@echo "Execution : "
	./$(EXEC)


c_exec :  main.o fonctions.o coups.o  affichage.o
	@echo " Creation d'executable "
	$(CC)  -o $(EXEC) $(MAIN.O) $(FONCTIONS.O) $(COUPS.O)  $(AFFICHAGE.O) $(LDFLAGS)


compile_main: $(MAIN)
	@echo " Compilation du main.c "
	$(CC) -c $(MAIN) $(CFLAGS)

compile_fonctions: $(FONCTIONS)
	@echo "Compilation des fonctions  "
	$(CC) -c $(FONCTIONS) $(CFLAGS)


compile_coups : $(COUPS)
	@echo " Compilation de coups.c "
	$(CC) -c $(COUPS) $(CFLAGS)

compile_affichage: $(AFFICHAGE)
	@echo "Compilation de L'affichage  "
	$(CC) -c $(AFFICHAGE) $(CFLAGS)

compile_ia: $(AFFICHAGE)
		@echo "Compilation de l'IA  "
		$(CC) -c $(IA) $(CFLAGS)

supprime_tout:
	@echo "Suppresion  :"
	rm *
