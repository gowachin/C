#include <stdio.h>
#include <ctype.h>
#define LETTRE 0
#define PONCTUATION 1
#define ESPACE 2
#define FIN_FICHIER 3

int transition [4][4] = {
    {1 , 2 , 2 , 3} ,
    {1 , 2 , 2 , 3} ,
    {1 , 2 , 2 , 3} ,
    {3 , 3 , 3 , 3}
};

int lire_nature_entree (FILE * f) {
    char c ;
    int nature ;
    fscanf (f , "%c" , &c);
    if (feof ( f ))
        nature = FIN_FICHIER ;
    else if ( isalpha ( c ))
        nature = LETTRE ;
    else if ( isspace ( c ))
        nature = ESPACE ;
    else
        nature = PONCTUATION ;
    return nature ;
}

int sortie ( int etat , int nature_entree ) {
    int bip = 0;
    if (( etat == 1) && ( nature_entree != LETTRE ))
        bip = 1;
    return bip ;
}

int main (int argc ,char *argv[]) {
    FILE * f ;
    int x = 0;
    int etat_courant, etat_suivant ;
    int nature_entree ;
    /* Vérifications */
    if(argc < 2){
        fprintf( stderr, "Il n'y a pas assez d'arguments\n");
        return 1;
    }
    f = fopen(argv[1], "r");
    if(f == NULL){
        fprintf( stderr, "Le fichier à ouvrir n'existe pas\n");
        return 2;
    }
    /* Simulation */
    nature = lire_nature_entree (f);
    fscanf(f,"%c",&nature_entree);
    while(!feof(f)){

    }
    
    printf ( "x = %d\n" , x );
    fclose(f);
    return 0;
}