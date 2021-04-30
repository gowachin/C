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
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "debug.h"
#include "variables.h"

void init_variables(variables * ens) {
    ens->nb = 0;
}

int ajouter_variable(variables * ens, char *nom, char *valeur) {
/*************** A COMPLETER ******************/
    /*
       Fonction qui affecte la valeur donnee au nom de variable donne.
       Si la variable existe deja dans les variables definies, il suffit juste
       de changer sa valeur. Dans le cas contraire, il faut l'ajouter aux
       variables definies : ajouter un couple (nom, valeur) a l'ensemble
       de variables. Dans tous les cas, la fonction retourne l'indice de la
       variable ajout�e.
     */
/**********************************************/
    int nb = trouver_variable(ens, nom);
    // printf("%d\n", nb);
    if (nb == -1){
        // printf("LA\n");
        nb = ens->nb;
        ens->nb++;
        strcpy(ens->T[nb].nom, nom);
        strcpy(ens->T[nb].valeur, valeur);
    } else {
        modifier_valeur_variable(ens, nb, valeur);
    }
    return nb; 
}

int nombre_variables(variables * ens) {
/*************** A COMPLETER ******************/
    /*
       Fonction qui renvoie le nombre de variables dans l'ensemble.
     */
/**********************************************/
    return ens->nb;
}

int trouver_variable(variables * ens, char *nom) {
    int i = 0;

/*************** A COMPLETER ******************/
    /*
       Fonction qui recherche le nom de variable dans l'ensemble
       des variables definies. Si le nom est trouve, la fonction retourne
       l'indice correspondant dans le tableau, dans le cas
       contraire elle retourne -1.
     */
/**********************************************/
    for (i; i < ens->nb; i++){
        if ( strcmp(ens->T[i].nom, nom) == 0)
            return i;
    }
    return -1;
}

char *nom_variable(variables * ens, int i) {
/*************** A COMPLETER ******************/
    /*
       Fonction qui renvoie le nom de la variable a l'indice i ou
       NULL si elle n'existe pas.
     */
/**********************************************/
    if(i>=ens->nb || i<0)
        return NULL;
    return ens->T[i].nom;
}

char *valeur_variable(variables * ens, int i) {
/*************** A COMPLETER ******************/
    /*
       Fonction qui renvoie la valeur de la variable a l'indice i ou
       "" si elle n'existe pas.
     */
/**********************************************/
    if(i>=ens->nb || i<0)
        return "";
    return ens->T[i].valeur;
}

void modifier_valeur_variable(variables * ens, int i, char *valeur) {
/*************** A COMPLETER ******************/
    /*
       Fonction qui modifie la valeur de la variable a l'indice i.
       Comportement indeterminee si l'indice i n'est pas valide.
     */
/**********************************************/
    if(i<=ens->nb){
        strcpy(ens->T[i].valeur, valeur);
    }
}

void afficher_ensemble_variables(variables * ens) {
    for (int i = 0; i < nombre_variables(ens); i++) {
        printf("%s=%s\n", nom_variable(ens, i), valeur_variable(ens, i));
    }
}

int trouver_et_appliquer_affectation_variable(variables * ens, char *ligne) {
/*************** A COMPLETER ******************/
    /*
       Fonction qui cherche a reconnaitre une affectation de variable dans le 
       morceau de ligne de commande transmise et, le cas echeant, l'applique. 
       Pour cela il faut determiner si ce morceau de
       ligne est de la forme :
       nom=valeur
       Cette fonction est destructive : elle modifie ligne lorsqu'elle
       trouve une affectation. Retourne 1 en cas d'affectation trouvee, 0 dans le
       cas contraire.
     */
/**********************************************/
    char* pointeur;
    int test = 0;
    for (int i = 0; ligne[i] != '\0'; i++)
    {
        if (ligne[i]=='='){
            pointeur = &ligne[i+1];
            ligne[i] = '\0';
            test = 1;
        }
    }
    if (test == 1){
        ajouter_variable(ens, ligne, pointeur);
        return 1;
    }
    return 0;
}

void appliquer_expansion_variables(variables * ens, char *ligne_originale, char *ligne_expansee) {
/*************** A COMPLETER ******************/
/*
  Fonction qui prend une ligne lue en parametre et la recopie dans le tableau
  resultat en remplacant toutes les utilisations de variable (de la forme
  '$nom' ou nom est une chaine de caracteres alphanumeriques ou * ou #) par la
  valeur de la variable correspondante.
*/
/**********************************************/
    int id;
    char variable[TAILLE_MAX_NOM] = "";
    strcpy(ligne_expansee, ""); // init to empty
    char hash[3];
    int i = 0,k = 0;
    int trouv_var;
    while (ligne_originale[i] != '\0')
    {
        strcpy(variable, "");
        if(ligne_originale[i]=='$'){
            i++;
            if (ligne_originale[i] == '#'){
                snprintf( hash, 3, "%d", ens->nb - 1 );
                strcat(ligne_expansee, hash);
                k = k + strlen(hash);
                i++;
            } else if (ligne_originale[i] == '*'){
                for (int index = 1; ens->nb > index;index++){
                    strcat(ligne_expansee, ens->T[index].valeur);
                    k = k + strlen(ens->T[index].valeur) + 1;
                    strncat(ligne_expansee, " ", 1);
                }
                i++;
            } else { // cas avec une variable
                for (i; isalnum(ligne_originale[i]) != 0; i++){
                    strncat(variable, &ligne_originale[i],1);
                } 
                trouv_var = trouver_variable(ens, variable);
                if (trouv_var!=-1){
                    strcat(ligne_expansee,ens->T[trouver_variable(ens,variable)].valeur);
                    k = k + strlen(ens->T[trouver_variable(ens, variable)].valeur);
                }
            }
        } else{
            ligne_expansee[k] = ligne_originale[i];
            ligne_expansee[k+1] = '\0';
            k++;
            i++;
        }

    }
    printf("Expansion : %s\n",ligne_expansee);
}


void affecter_variables_automatiques(variables *ens, int argc, char *argv[]) {
/*************** A COMPLETER ******************/
    /*
       Il faut definir les variables automatiques a partir des arguments
       donnes au programme :
       - placer la valeur de chacun des arguments transmis au programme dans la
       variable correspondante ($0, $1, $2, ...)
       - construire au fur et a mesure une chaine de caractere contenant toutes
       les valeurs et l'affecter a $*
       - affecter le nombre d'arguments a $#
     */
/**********************************************/
    char hash[3];
    for(int i = 1; i < argc; i ++){
        snprintf( hash, 3, "%d", i-1 );
        ajouter_variable(ens, hash, argv[i]);
    }
}
