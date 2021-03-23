#include <stdio.h>

int main (int argc, char *argv[]) {
	FILE *f ;
	char c ;
	int i ;
	if (argc == 1){
		char c;
		fscanf(stdin, "%s", &c);
		while( !feof(stdin)){
			printf("%s\n", &c);
			fscanf(stdin, "%s", &c);
		}
		return 0;
	}

	for(i = 1; i <argc ; i++ ){
		//printf("l’argument numero %d est %s\n",i, argv[i]) ;
		f = fopen(argv[i], "r") ;
		if (f == NULL) {
			printf("%s n'a pas pu être ouvert en lecture\n", argv[i]) ;
		return 2 ;
		}
	
		fscanf(f, "%c", &c) ;
		while (!feof(f)) {
			printf("%c", c) ;	
			fscanf(f, "%c", &c) ;
		}
		printf("\n");
		fclose(f) ;
	} 
	return 0 ;
}
