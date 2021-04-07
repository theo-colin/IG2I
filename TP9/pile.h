#include "es.h"
#define MAX 10 //pile STATIQUE (limitée à MAX éléments)


typedef struct
{
    T_Elt Elts[MAX];  // stockage d'éléments de la case 0 à la case MAX-1
    int nbElts;
} T_Pile;


void initPile( T_Pile *P ); //mettre nbElts à 0
int pilepleine(const  T_Pile *P); //renvoie 1  qd nbElts == MAX
int pilevide(const  T_Pile *P); // renvoie 1  qd nbElts == 0
int empiler( T_Pile *P, T_Elt e); //push de e dans la case nbElts de Elts, renvoie 1 si empiler OK, 0 sinon (qd pilePleine)
int depiler( T_Pile *P, T_Elt *pelt); //pop retourne le T_Elt via pelt et renvoie 0 si pile vide, 1 sinon.
T_Elt sommet(const  T_Pile *P);// valeur au sommet de la pile
int hauteur(const  T_Pile *P);
void afficherPile(T_Pile *P); //vous devez depiler la pile pour afficher chacune de ses valeurs (puis surtout la rempiler)
void testPile(T_Pile *P); // fonction pour tester les fonctions sur les piles

