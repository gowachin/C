#include <stdio.h>
#include <string.h>
#include "bouts_de_phrases.c"
#include "generer_entier.c"


int nb_mots(char *Phrase){
	int i,j = 1;
	for (i=0; Phrase[i] != '\0'; i++){
		if(Phrase[i] == ' ')
			j++;
	}
	return j;
}


int main() {
	char Sujet[50]="la petite souris" ;
	char Verbe[50]="mange" ;
	char Compl[50]="le gros chat" ;
	char Phrase[150] ;
	int res,i;

	strcat(Phrase,Sujet);
	strcat(Phrase, " ");
	strcat(Phrase,Verbe);
	strcat(Phrase, " ");
	strcat(Phrase,Compl);
	// printf("%s\n", Phrase);

	for(i = 0; i < 3; i++){
		Phrase[0] = '\0'; // reinitialise phrase
		strcat(Phrase,sujet[generer_entier(11)]);
		strcat(Phrase, " ");
		strcat(Phrase,verbe[generer_entier(11)]);
		strcat(Phrase, " ");
		strcat(Phrase,complement[generer_entier(11)]);
		printf("%s\n", Phrase);
		res = nb_mots(Phrase);
		printf("La phrase : %s contient %d mots\n", Phrase, res);
	}
	return 0;
}
