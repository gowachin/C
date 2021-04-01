#include <string.h>
#include <stdio.h>
#include "joueurs.h"

void init_joueurs(joueurs *ens){
  ens->nb = 0;
}

int ajouter_joueur(joueurs *ens, char *nom, int billes) {
  int nb = ens->nb;
  int place = trouver_joueur(ens, nom);

  if (place == -1) {
    strcpy(ens->T[nb].pseudo, nom);
    ens->T[nb].nb_billes = billes;
    ens->nb++;
  } else {
    nb = place;
  }
  return nb;
}

int nombre_joueurs(joueurs *ens) {
  return ens->nb;
}

char *nom_joueur(joueurs *ens, int i) {
  if (i < ens->nb){
    return ens->T[i].pseudo;
  }
  else
    return NULL;
}

int billes_joueur(joueurs *ens, int i) {
  if (i < ens->nb){
    return ens->T[i].nb_billes;
  }
  else
    return 0;
}

int trouver_joueur(joueurs *ens, char *nom) {
  int test = -1;
  for (int i = 0; i < ens->nb && test == -1; i++){
    if (!strcmp(nom, ens->T[i].pseudo)){
      test = i;
    }
  }
  return test;
}

void modifier_billes(joueurs *ens, int i, int cpt) {
}

void afficher_ensemble_joueurs(joueurs *ens) {
    int i ;
    for (i=0 ; i<ens->nb ; i++) 
      printf("%s %d\n", ens->T[i].pseudo, ens->T[i].nb_billes) ;
}
