#include <stdio.h>
#include <string.h>

typedef struct {
    char pseudo[20];
    int nb_billes;
} joueur;           

joueur atchoum = { "Atchoum", 42 };
joueur dormeur = { "Dormeur", 25 };
joueur grincheux = { "Grincheux", 3 };
joueur joyeux = { "Joyeux", 100 };
joueur prof = { "Prof", 2 };
joueur simplet = { "Simplet", 0 };
joueur timide = { "Timide", 12 };

void afficher_joueur_V1(joueur j) {
    printf("%s a %d billes\n", j.pseudo, j.nb_billes);
}

void afficher_joueur_V2(joueur* pj) {
    printf("%s a %d billes\n", pj->pseudo, pj->nb_billes);
}

void lire_joueur(joueur* pj){
    char t_pseudo[20] ;
    int nbille ;
    scanf("%19s", t_pseudo) ;
    scanf("%d", &nbille) ;
    strcpy(pj->pseudo,t_pseudo);
    pj->nb_billes = nbille;
}

void transferer_V1(joueur j1, joueur j2, int nb){
    j1.nb_billes = j1.nb_billes - nb;
    j2.nb_billes = j2.nb_billes + nb;
}

void transferer_V2(joueur* j1, joueur* j2, int nb){
    j1->nb_billes = j1->nb_billes - nb;
    j2->nb_billes = j2->nb_billes + nb;
}


int main() {
    afficher_joueur_V1(atchoum);
    afficher_joueur_V2(&simplet);
    lire_joueur(&simplet);
    afficher_joueur_V2(&simplet);
    printf("\nOn test transferer_V1 avec 10 billes\n");
    transferer_V1(atchoum,simplet,10);
    afficher_joueur_V2(&atchoum);
    afficher_joueur_V2(&simplet);
    printf("\nOn test transferer_V2 avec 10 billes\n");
    transferer_V2(&atchoum,&simplet,10);
    afficher_joueur_V2(&atchoum);
    afficher_joueur_V2(&simplet);
    return 0;
}
