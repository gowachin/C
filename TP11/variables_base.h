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


/* initialisation d'un ensemble de variables a l'ensemble vide */
void init_variables(variables *ens);

/* ajout d'une variable dans un ensemble de variables si elle n'y est pas deja,
 * ecrase sa valeur sinon. Dans tous les cas renvoie l'indice de la variable dans
 * l'ensemble */
int ajouter_variable(variables *ens, char *nom, char *valeur);

/* cardinal d'un ensemble de variables */
int nombre_variables(variables *ens);

/* recherche de l'indice d'une variable dans un ensemble, -1 si la variable n'est
 * pas presente dans l'ensemble */
int trouver_variable(variables *ens, char *nom);

/* variable d'indice i (NULL si cette variable n'existe pas dans l'ensemble) */
char *nom_variable(variables *ens, int i);

/* valeur de la variables a l'indice i ("" si inexistant) */
char *valeur_variable(variables *ens, int i);

/* met a jour la valeur de la variable d'indice i (sans effet si indice invalide) */
void modifier_valeur_variable(variables *ens, int i, char *valeur);
