#include "automate.h"
#include <stdio.h>

int main(int argc,char* argv[]) {
	if (argc != 2){
		printf("Mettre un nom de fichier\n");
		return 1;
	}
	transit t;
	int test;
	test = init_automate(argv[1], &t);
	if (test==1){
		printf("Nom de fichier incorrect\n");
		return 1;
	}
	simule_automate(t) ;
	return 0 ;
}


