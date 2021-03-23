#include <stdio.h>

void affiche_entier(char c, int i){

    if (c == 'o') {
        printf("%o\n",i);
    } else if (c == 'd') {
        printf("%d\n",i);
    } else if (c == 'x') {
        printf("%x\n",i);
    }
    
}

void affiche_V(int i){

    int ii;
    int bi;
    int mi;

    for (ii = 0; ii < i; ii++) {
        for (bi = 0; bi < ii; bi++) {
            printf(" ");  
        }
        printf("*");
        for(mi = (2*i -1 - (2 + 2*bi)); mi > 0; mi--){
            printf(" ");
        }
        if (ii != i-1)
            printf("*\n");
        else 
            printf("\n");
    }
}

/*Ecrivez une fonction compte_qd prenant en paramètre 
un tableau d'entiers t et un entier n, 
le nombre d'éléments du tableau, qui 
renvoie le nombre d'occurence de la valeur 42 dans t.*/

int compte_qd(int * t, int n){
    int i;
    int r = 0;
    for (i = 0; i < n; i++){
        // printf("%d\n", t[i]);
        if (t[i] == 42)
            r++;
    }
    return r;
}

void renverse(int * t, int n){

    int i, tmp;

    for (i = 0; i < n/2; i++) {
        tmp = t[i];
        t[i] = t[n-i-1];
        t[n-i-1] = tmp;
    }
}

void affiche_tableau(int *t, int n) {
    for (int i=0; i<n; i++)
      printf("%d ", t[i]);
    printf("\n");
  }

int main() {
    affiche_entier('o', 66);
    affiche_entier('d', 66);
    affiche_entier('x', 66);
    affiche_entier('z', 66);

    affiche_V(5);
    int t[] = { 1, 2, 3, 42, 5 };
    printf("Il y a %d fois 42 dans le tableau\n", compte_qd(t, 5));

    affiche_tableau(t, 5);
    renverse(t, 5);
    affiche_tableau(t, 5);
}