#include <stdio.h>
#include <string.h>
#include "automate.h"

#define NB_ETATS 5
#define NB_ENTREES 10
#define LG_MAX_SORTIE 128

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

typedef struct {
	int transitions[NB_ETATS][NB_ENTREES] ;
} transit ;

void init_par_defaut(transit *t) {
	int i, j;
	for (i = 0; i < NB_ETATS; i++)
		for (j = 0; j < NB_ENTREES; j++)
			t->transitions[i][j] = Q0;
}

void transition(transit *t){
	init_par_defaut(t);
	t->transitions[Q0][1] = Q1;
	t->transitions[Q1][1] = Q1;
	t->transitions[Q2][1] = Q1;
	t->transitions[Q3][1] = Q1;
	t->transitions[Q4][1] = Q1;
	t->transitions[Q1][2] = Q2;
	t->transitions[Q2][3] = Q3;
	t->transitions[Q3][4] = Q4;
}

void simule_automate() {
	int etat_courant, etat_suivant, entree ;
	transit t;
	transition(&t);
	entree = 0 ;
	etat_courant = etat_initial() ;
	while (entree != -1 && etat_courant != Q4) {
		entree = lire_entree() ;
		etat_courant = t.transitions[etat_courant][entree] ;
		if(etat_courant == Q4)
			printf("clic\n");
	}
}