#include "semaine_6.h"


void prochain_fibonacci (int* a, int* b){
    //int *tmp = a;
    //a = b;
    //b = a + tmp;
}

char *trouve_42 (char *s){
    char *pointeur = NULL;
    int tmp = 0;
    for(int i = 0; s[i] != '\0'; i++ ){
        if (s[i]=='4'){
            tmp = i;
        }
        if (s[i] == '2' && i == tmp + 1){
            pointeur = &s[i-1];
        }
    }
    return pointeur;
}

/*
Exercice 3
Ecrivez une fonction pas_de_repetition prenant en paramètre une chaîne de caractères s, 
qui ne renvoie rien et qui remplace dans s toutes les répétitions d'un caractère x par 
une seule occurence de x. On appelle une répétition d'un caractère x le fait que x est
 présent à au moins deux positions successives dans la chaîne. Bien entendu, il faudra 
 remplacer toutes les répétitions, même celles comportant plus de deux caractères, 
 à la sortie de la fonction, s ne doit plus contenir de répétition du tout.

Par exemple, si s contient "abcccccddeffghi", après l'appel à pas_de_repetition(s), la chaîne s contient "abcdefghi".

*/

char* modif(char *s,int place){
    for (int i=place;s[i]!='\0';i++){
        s[i]=s[i+1];
    }
    return s;
}

void pas_de_repetition(char *s){
    int i = 0;
    while(s[i]!='\0'){
        if(s[i]==s[i+1])
            modif(s,i);
        else
            i++;
    }
}

/*Exercice 4
Ecrivez une fonction encode prenant en paramètre deux chaines de caractères code et texte qui ne 
renvoie rien et modifie chaque caractère c de texte de la manière suivante :

si c est présent dans code à la position i, c est remplacé dans texte par le caractère de code de position :
i+1 si la longueur de code est strictement supérieure à i+1 ;
0 sinon ;
si c n'est pas présent dans code, il reste inchangé.
Nous supposerons que les caractères de code sont tous différents.

Par exemple, si code contient "abc" et texte contient "coucou bonjour les amis", après l'appel à 
pas_de_repetition(s), la chaîne texte contient "aouaou conjour les bmis".
*/

void encode(char *code,char *texte){
    int temp;
    for(int i = 0; texte[i]!='\0';i++){
        temp = 0;
        for(int j = 0; code[j]!='\0' && temp!=1;j++){
            if (texte[i]==code[j]){
                if(code[j+1]=='\0')
                    texte[i] = code[0];
                else
                    texte[i] = code[j+1];
                temp=1;
            }
        }
    }
}

int main() {
    int a=3, b=5;
    printf("*** Exercice 1 :\nValeurs fibonacci : %d %d, ", a, b);
    prochain_fibonacci(&a, &b);
    printf("valeurs suivantes : %d %d\n\n", a, b);

    
    char chaine_2[] = "Un bel exemple avec du 42 dedans";
    char *ptr = trouve_42(chaine_2);
    printf("*** Exercice 2 :\nChaine : [%s]\nPointeur chaine : %p, position 42 : %p, contenu[0] : %c, "
           "contenu[1] : %c\n\n", chaine_2, chaine_2, ptr, ptr[0], ptr[1]);
    
    char chaine_3[] = "quelle belle phrase d'exemple";
    printf("*** Exercice 3 :\nChaine originale : [%s]\n", chaine_3);
    pas_de_repetition(chaine_3);
    printf("Chaine sans répétition : [%s]\n\n", chaine_3);

    char code[] = "demo421";
    char texte[] = "Une phrase a transformer avec du 42";
    printf("*** Exercice 4 :\nCode : [%s], texte : [%s]\n", code, texte);
    encode(code, texte);
    printf("Encodage : [%s]\n\n", texte);
    

    return 0;
  }