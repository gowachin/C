#include <stdio.h>

int main (int argc, char *argv[]) {
	FILE *f ;
	FILE *g ;
	char c ;
	if(argc == 2){
		f = fopen(argv[1], "r") ;
		if (f == NULL) {
			printf("%s n'a pas pu être ouvert en lecture\n", argv[1]) ;
		return 2 ;
		}
	
		fscanf(f, "%c", &c) ;
		while (!feof(f)) {
			printf("%c", c) ;	
			fscanf(f, "%c", &c) ;
		}
		printf("\n");
	} else if (argc == 3) {
		f = fopen(argv[1], "r") ;
		g = fopen(argv[2], "a") ;
		if (f == NULL) {
			printf("%s n'a pas pu être ouvert en lecture\n", argv[1]) ;
			return 2 ;
		}
		if (g == NULL) {
			printf("%s n'a pas pu être ouvert en lecture\n", argv[2]) ;
			return 2 ;
		}
		fprintf(g, "%c", '\n');
		fscanf(f, "%c", &c);
		while (!feof(f)) {
			fprintf(g,"%c", c) ;	
			fscanf(f, "%c", &c) ;
		}

	} else { 
		printf("Rentrez un nombre correct d'arguments (1) \n");
		return 1 ;
	}
	fclose(f) ;
	return 0 ;
}
