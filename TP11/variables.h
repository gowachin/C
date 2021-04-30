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


#ifndef __VARIABLE_H__
#define __VARIABLE_H__

#define TAILLE_MAX_NOM 512
#define TAILLE_MAX_VALEUR 512
#define NOMBRE_MAX_VARIABLES 512

typedef struct {
	char nom[TAILLE_MAX_NOM];
	char valeur[TAILLE_MAX_VALEUR];
} variable;

struct ensemble_variables {
	variable T[NOMBRE_MAX_VARIABLES];
	int nb;
};

typedef struct ensemble_variables variables;

#include "variables_base.h"

/* pour aider a la mise au point des programmes - affichage des
 * variables d'un ensemble de variables */
void afficher_ensemble_variables(variables *ens);

/* cherche a reconnaitre une affectation de variable dans la ligne donnee.
 * Si c'est le cas, affecte la variable a la valeur donnee et modifie la ligne donnee.
 * Renvoie 1 en cas d'affectation trouvee, 0 sinon. */
int trouver_et_appliquer_affectation_variable(variables *ens, char *ligne);

/* copie la ligne originale dans la ligne expansee en remplacant les $NOM par la valeur
 * de la variable NOM */
void appliquer_expansion_variables(variables *ens, char *ligne_originale, char *ligne_expansee);

/* remplit l'ensemble de variables avec les variables automatiques correspondantes aux
 * arguments passes */
void affecter_variables_automatiques(variables *ens, int argc, char *argv[]);
#endif
