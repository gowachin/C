#include <stdio.h>
#include <string.h>
#include "generer_entier.c"
#include "bouts_de_phrases.c"

/* longueur de la chaine passee en parametre */
unsigned long mon_strlen(char *ch) {
	int i;
	for (i=0 ; ch[i] != '\0' ; i++)
		;
	return i ;
}

void mon_strcopy(char *destination, char *source){
	int i;
	for(i=0;source[i]!= '\0'; i++){
		destination[i] = source[i];
	}
	destination[i+1] = '\0';
}

/* Concatène source à la fin de destination */
void mon_strcat(char *destination, char *source){
	int i;
	int j = 0;
	for(i = mon_strlen(destination) ;source[j]!= '\0'; i++){
		destination[i] = source[j];
		j++;
	}
	destination[i+1] = '\0';
}

int mon_strcmp(char *chaine1, char *chaine2){
	int i;
	int rep = 0;
	for(i = 0; chaine1[i]!= '\0' || chaine2[i]!= '\0' ;i++){
		if (chaine1[i] != chaine2[i]){
			if (chaine1[i] < chaine2[i])
				rep = -1;
			else 
				rep = 1;
			return rep;
		}
	}
	return rep;
}

int main() {
	char chaine[50] ;
	unsigned long mon_resultat ;

	printf("un mot (pas trop long !) à mesurer ?\n") ;
	scanf("%49s", chaine) ;
	mon_resultat=mon_strlen(chaine) ;
	if (mon_resultat == strlen(chaine) )
		printf("longueur de la chaine %s :%lu\n", chaine, mon_resultat) ;
	else
		printf("non, la longueur de '%s' n'est pas %lu\n", chaine, mon_resultat) ;


	char temp[mon_resultat *2 + 1];
	mon_strcopy(temp, chaine);
	printf("On a bien copié ici le mot : %s \n", temp);


	int retour;
	retour=mon_strcmp(temp,chaine);
	if (retour == 0)
		printf("Les deux chaines %s et %s sont identiques\n", temp, chaine);
	else
		printf("Les deux chaines %s et %s sont différentes\n", temp, chaine);


	mon_strcat(temp, chaine);
	printf("On a bien concaténé ici le mot avec lui même : %s \n", temp);
	

	retour=mon_strcmp(temp,chaine);
	if (retour == 0)
		printf("Les deux chaines %s et %s sont identiques, code %d\n", temp, chaine, retour);
	else
		printf("Les deux chaines %s et %s sont différentes, code %d\n", temp, chaine, retour);
	return 0;
}
