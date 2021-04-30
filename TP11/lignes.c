/*
Interpr�teur de commandes � but p�dagogique
Copyright (C) 2011-2018 Guillaume Huard
Ce programme est libre, vous pouvez le redistribuer et/ou le modifier selon les
termes de la Licence Publique G�n�rale GNU publi�e par la Free Software
Foundation (version 2 ou bien toute autre version ult�rieure choisie par vous).

Ce programme est distribu� car potentiellement utile, mais SANS AUCUNE
GARANTIE, ni explicite ni implicite, y compris les garanties de
commercialisation ou d'adaptation dans un but sp�cifique. Reportez-vous � la
Licence Publique G�n�rale GNU pour plus de d�tails.

Vous devez avoir re�u une copie de la Licence Publique G�n�rale GNU en m�me
temps que ce programme ; si ce n'est pas le cas, �crivez � la Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307,
�tats-Unis.

Contact: Guillaume.Huard@imag.fr
	 B�timent IMAG
	 700 avenue centrale, domaine universitaire
	 38401 Saint Martin d'H�res
*/


#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "lignes.h"

int lire_ligne_fichier(FILE * fichier, char *ligne) {
/*************** A COMPLETER ******************/
    /*
       Lecture d'une ligne depuis un fichier avec stockage de la ligne lue
       dans la variable ligne. Ne pas inclure le '\n' final dans la variable
       ligne, ne pas oublier de completer la ligne avec un '\0' terminal.
       La valeur de retour doit etre 0 s'il n'y a plus rien a lire (fin de
       fichier sans avoir lu aucun caractere) et 1 sinon.
     */
/**********************************************/
    char c;
    strcpy(ligne, "");
	fscanf(fichier, "%c", &c);
    while ((c != '\n') && (!feof(fichier))) {	
        strncat(ligne, &c, 1);
        fscanf(fichier, "%c", &c) ;   
    }
    strncat(ligne, "\0", 1);
    if (feof(fichier)){
        return 0;
    }
    return 1;
}

void decouper_ligne(char *ligne, char *ligne_decoupee[]) {
/*************** A COMPLETER ******************/
    /* 
       Decoupage de la ligne : chaque mot devient une chaine, c'est-a-dire
       est termine par '\0'. ligne_decoupee contient les adresses de ces mots,
       et se termine par NULL (s'il y a N mots, ligne_decoupee[0] pointe sur
       le premier mot et ligne_decoupee[N] vaut NULL.
       L'algorithme consiste a parcourir la variable ligne en reperant
       les debuts et les fins de mots (les mots sont separes par des espaces).
       Au debut d'un mot, on garde son adresse dans ligne_decoupee.
       A la fin d'un mot, on remplace le 1er espace qui le suit par '\0'
     */
/**********************************************/
    // A remplacer : cette solution temporaire ne d�coupe rien, elle ne
    // fonctionne qu'avec les commandes sans argument
    int i;
    int j = 1;
    ligne_decoupee[0] = ligne;
    for (i = 0; ligne[i] != '\0';i++){
        if (ligne[i] == ' '){
            ligne[i] = '\0';
            ligne_decoupee[j] = &ligne[i+1];
            j++;
        }
    }
    ligne_decoupee[j] = NULL;
}

