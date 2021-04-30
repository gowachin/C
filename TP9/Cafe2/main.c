#include <stdio.h>
#include "automate.h"

int main(int argc,char* argv[]){
	automate A ;
	FILE *f;
	// init_mon_automate(&A);
	if (argc != 2){
		fprintf(stderr,"Le programme requiert un nom de fichier\n");
		return 1;
	}
	f = fopen(argv[1], "r");
	if (f == NULL){
		fprintf(stderr,"Le fichier n'existe pas\n");
		return 2;
	}
	lecture_automate(&A, f);
	simule_automate(&A);
	fclose(f);
	return 0 ;
}	
