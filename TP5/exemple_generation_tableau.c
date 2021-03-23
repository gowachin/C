#include <stdio.h>
#include "generer_entier.c"


// affiche a l'écran T[0..nb-1]
void afficher(long T[], int nb) {
    int i;
    printf("[ ");
    for (i = 0; i < nb; i++) {
        printf("%ld ", T[i]);
    }
    printf("]\n");
}


void echanger(long Tab[], int i, int j) {
    long tmp;
    tmp = Tab[i];
    Tab[i] = Tab[j];
    Tab[j] = tmp;
}

/* inserer a sa place l’entier val dans la sequence triee Tab[0..nb-1] */
void inserer(long Tab[], int nb, int val){
    Tab[nb] = val;
    int i = 0;
    while (Tab[nb - 1 - i ] > Tab[nb - i] && nb - i > 0 )
    {
        echanger(Tab, nb - i, nb - 1 - i);
        i++; 
    }
    
}

int main() {
    int Taille = 20;
    long T[Taille];
    int i;
    long valeur ;
    // on initialise le tableau pour pas récuperer la mémoire précédente
    for (i = 0; i < Taille; i++) 
        T[i] = 0;

    for (i = 0; i < Taille; i++) {
	valeur = generer_entier(100) ;
        // T[i] = valeur;
        inserer(T,i,valeur) ;
        afficher(T, Taille);
    }
    // afficher(T, Taille);
    return 0;
}