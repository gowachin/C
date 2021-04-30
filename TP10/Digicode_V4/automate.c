#include <stdio.h>
#include <string.h>
#include "automate.h"

#define Q0 0
#define Q1 1
#define Q2 2
#define Q3 3
#define Q4 4

char essai[]="/*" /* un essai : " */;
typedef int etat ;

etat etat_initial() {
	return Q0 ;
}

int est_final(etat Q) {
	return Q == Q4 ;
	}

int lire_entree() {
	char c ;
	scanf("\n%c", &c) ;
	while (((c < '0') || (c > '9')) && (c != '-')) {
		printf("entree invalide ! un chiffre entre 0 et 9 (- pour finir) ?\n") ;
		scanf("\n%c", &c) ;
		}
	if (c == '-') {
		return -1 ;
	}
	else {
		return c-'0' ;
	}
}

void init_par_defaut(transit *t) {
	int i, j;
	for (i = 0; i < NB_ETATS; i++)
		for (j = 0; j < NB_ENTREES; j++)
			t->transitions[i][j] = 0;
}

int init_automate(char* nom, transit *t){
	int nb_trans, dep, e, arr, i;
	FILE *f;
	f = fopen(nom,"r");
	if (f == NULL){
		return 1;
	}
	init_par_defaut(t);

	// etat de transition
	fscanf(f, "%d", &nb_trans);
	for (i=1 ; i<= nb_trans ; i++) {
		fscanf(f, "%d %d %d", &dep, &e, &arr);
		t->transitions[dep][e] = arr ;
	}
	fclose(f);
	return 0;
}

void simule_automate(transit t) {
	int etat_courant, etat_suivant, entree ;
	entree = 0 ;
	etat_courant = etat_initial() ;
	while (entree != -1 && etat_courant != Q4) {
		entree = lire_entree() ;
		etat_courant = t.transitions[etat_courant][entree] ;
		if(etat_courant == Q4)
			printf("clic\n");
	}
}