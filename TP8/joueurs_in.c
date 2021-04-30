#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "joueurs.h"
#include "joueurs_in.h"


joueurs lire_les_joueurs(char *nom_fich){
    FILE *f;
    f = fopen(nom_fich, "r");
    joueurs ens;
    char nb_string[3] = "";
    char c;
    char nb_j[32] = "";
    char nb_bille[4] = "";
    int nb;

    //init
    init_joueurs(&ens); 

    // lecture-ecriture des joueurs
    fscanf(f, "%c", &c);
    while (c!='\n') {	
        strncat(nb_string, &c,1);
        fscanf(f, "%c", &c) ;   
    }
    nb = atoi(nb_string);
    
    for(int i = 0; i < nb ; i++){
        // noms des joueurs
        strcpy(nb_j, "");
        fscanf(f, "%c", &c);
        while (c!=' ') {	
            strncat(nb_j, &c,1);
            fscanf(f, "%c", &c) ;   
        }
        // nb billes joueurs
        strcpy(nb_bille, "");
        fscanf(f, "%c", &c);
        while (c!='\n' && !feof(f)) {	
            strncat(nb_bille, &c,1);
            fscanf(f, "%c", &c) ;   
        }
        ajouter_joueur(&ens, nb_j, atoi(nb_bille));
    }
    
    fclose(f);
    return ens;
}