#ifndef __AUTOMATE__
#define __AUTOMATE__

#define NB_ETATS 5
#define NB_ENTREES 10
#define LG_MAX_SORTIE 128

typedef struct {
	int transitions[NB_ETATS][NB_ENTREES] ;
} transit ;

int init_automate(char* nom, transit *t) ;

void simule_automate() ;

#endif

