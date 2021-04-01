#ifndef __JOUEURS_IN_H__
#define __JOUEURS_IN_H__
#include <stdio.h>
#include "joueurs.h"

/*
  Lis l'ensemble de joueurs dans un fichier portant le nom choisi.
  Le contenu du fichier devra suivre rigoureusement le format :
  - sur la première ligne, le nombre de joueurs de l'ensemble
  - puis, sur chaque ligne, un nom de joueur, une espace et son nombre de billes
 */
joueurs lire_les_joueurs(char *nom_fich);


#endif