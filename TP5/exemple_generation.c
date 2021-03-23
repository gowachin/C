#include <stdio.h>
#include "generer_entier.c"

int main() {
    int n = 5;
    int i;
    long x;

    for (i = 0; i < n; i++) {
        x = generer_entier(100);
        printf("J'ai genere l'entier %ld\n", x);
        if (x<42)
            printf("Trop petit\n");
        else if (x==42)
            printf("Youpie\n");
        else 
            printf("Trop grand\n");
    }
    return 0;
}