#include <stdio.h>

#include "joueurs.h"
#include "operations.h"

int gain(joueurs *e) {
    char nom[TAILLE_MAX_NOM] ;
    int i, solde, depose ;

    printf("Nom du joueur et billes gagnées ? ") ;
    scanf("%s %d", nom, &depose) ;
    i = trouver_joueur(e, nom) ;
    if (i == -1) { 
        printf("Inconnu\n") ; return 1 ;
    }
    solde = billes_joueur(e, i) ;
    solde = solde + depose ;
    modifier_billes(e, i, solde) ;
    return 0 ;
  }
      
int perte(joueurs *e) {
    char nom[TAILLE_MAX_NOM] ;
    int i, solde, retire ;

    printf("Nom du joueur et billes perdues ? ") ;
    scanf("%s %d", nom, &retire) ;
    i = trouver_joueur(e, nom) ;
    if (i == -1) { 
        printf("Inconnu\n") ; return 1 ;
    }
    solde = billes_joueur(e, i) ;
    solde = solde - retire ;
    modifier_billes(e, i,solde) ;
    return 0 ;
  }

/* Lecture du nom du joueur a debiter, du nom
du joueur a crediter, et du montant du transfert.
Mise a jour des deux comptes.*/
int transfert(joueurs *e) {
  /********** A COMPLETER ***********/
  int i, j, montant, soldeg, soldep ;
  char nomp[TAILLE_MAX_NOM], nomg[TAILLE_MAX_NOM] ;

  printf("Nom du joueur qui gagne ? ") ;
  scanf("%s", nomg) ;
  printf("Nom du joueur qui perd ? ") ;
  scanf("%s", nomp) ;
  i = trouver_joueur(e, nomp);
  j = trouver_joueur(e, nomg);
  if (i == -1 || j == -1) { 
      printf("Inconnu\n") ; return 1 ;
  }
  printf("Montant ? ") ;
  scanf("%d", &montant) ;

  soldeg = billes_joueur(e, j) ;
  soldep = billes_joueur(e, i) ;
  modifier_billes(e, j,soldeg+montant) ;
  modifier_billes(e, i,soldep-montant) ;
  return 0 ;
}
