#include <stdio.h>
#include <string.h>
#include "joueurs.h"
#include "joueurs_out.h"

void ecrire_les_joueurs(joueurs *ens, char *nom_fich){
    FILE *f;
    f = fopen(nom_fich, "w");

    //write number
    fprintf(f, "%d\n", ens->nb);
    //write players
    for (int i = 0; i < ens->nb; i++){
        for(int ii = 0; ens->T[i].pseudo[ii] != '\0'; ii++){
            fprintf(f, "%c", ens->T[i].pseudo[ii]);
        }
        fprintf(f, " %d\n", ens->T[i].nb_billes);
    }
    fclose(f) ;
}

