#include <stdio.h>
#include <stdlib.h>


int main() {
    unsigned int courant = 0, prochain = 1;

    printf("taille du type unsigned int : %ld octet(s)\n", sizeof(unsigned int));

    while (prochain > courant) {
        courant = prochain;
        prochain = prochain + 1;
    }

    printf("%u + 1 = %u donc ...\n", courant, prochain);
    printf("valeur maximum d'une variable de type unsigned int : %u\n", courant);

    return 0;
}
