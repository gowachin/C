#include <stdio.h>
//#include <stdlib.h>
#include <string.h>
#include "automate.h"

void init_par_defaut(automate *A) {
	int i, j;
	A->nb_etats = NB_MAX_ETATS;
	A->etat_initial = 0;
	for (i = 0; i < NB_MAX_ETATS; i++)
		A->etats_finals[i] = 0;
	for (i = 0; i < NB_MAX_ETATS; i++)
		for (j = 0; j < NB_MAX_ENTREES; j++)
			A->transitions[i][j] = i;
	for (i = 0; i < NB_MAX_ETATS; i++)
		for (j = 0; j < NB_MAX_ENTREES; j++)
			strcpy(A->sortie[i][j], "entree_invalide");
}

void lecture_automate(automate *A,FILE *f){
	int nb_trans, i, s, nb_sorties;
	int depart, arrivee;
	char symbole_entree, sorties[LG_MAX_SORTIE];
	int entree;

	//fopen(f,'r');
	// init
	init_par_defaut(A); 
	// nb etats
	fscanf(f, "%d", &A->nb_etats);
	// etat finaux
	fscanf(f, "%d", &i); 
	for (int j = 0; j < i; j++){
		fscanf(f, " %d", &s);
		A->etats_finals[s] = 1;
	}
	// etat de transition
	fscanf(f, "%d", &nb_trans);
	for (i=1 ; i<= nb_trans ; i++) {
		fscanf(f, "%d %c %d", &depart, &symbole_entree, &arrivee);
		entree = symbole_entree;
		A->transitions[depart][entree] = arrivee ;
		A->sortie[depart][entree][0] = '\0' ;
	}
	// message sorties
	fscanf(f, "%d", &nb_sorties);
	for (i=1 ; i<= nb_sorties ; i++) {
		fscanf(f, "%d %c %s", &depart, &symbole_entree, sorties);
		entree = symbole_entree;
		strcpy(A->sortie[depart][entree], sorties);
	}
	//fclose(f);
}

void init_mon_automate(automate * A) {
	init_par_defaut(A);
	A->nb_etats = 2;
	A->transitions[0]['2'] = 1;
	A->transitions[0]['r'] = 0;
	A->transitions[0]['c'] = 0;
	A->transitions[1]['2'] = 1;
	A->transitions[1]['r'] = 0;
	A->transitions[1]['c'] = 0;

	strcpy(A->sortie[0]['2'], "credit:20c");
	strcpy(A->sortie[0]['r'], "");
	strcpy(A->sortie[0]['c'], "");
	strcpy(A->sortie[1]['2'], "CLING!-credit:20c");
	strcpy(A->sortie[1]['r'], "CLING!");
	strcpy(A->sortie[1]['c'], "Boisson_servie");
}

int lire_entree() {
	char c;
	scanf(" %c", &c);
	return c;
}

void ecrire_sortie(char *message) {
	printf("%s\n", message);
}

void simule_automate(automate * A) {
	int etat_courant, etat_suivant;
	int entree = ' ';

	etat_courant = A->etat_initial;
	entree = lire_entree();
	while (entree != 'q') {
		etat_suivant = A->transitions[etat_courant][entree];
		printf("%s\n", A->sortie[etat_courant][entree]);
		etat_courant = etat_suivant;
		entree = lire_entree();
	}
}

