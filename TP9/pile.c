#include "pile.h"



void initPile( T_Pile * P)
{
    P->nbElts = 0;
}


int pilepleine(const  T_Pile *P)
{
    if (P->nbElts == MAX){
        return 1;
    }
    else {
        return 0;
    }
}



int pilevide(const  T_Pile *P)
{
    if (P->nbElts == 0){
        return 1;
    }
    else {
        return 0;
    }
}



int empiler( T_Pile *P, T_Elt e) //renvoie 0 si pile pleine, sinon 1
{
    if (pilepleine(P)==1){
        return 0;
    }
    else{
        P->nbElts=P->nbElts+1;
        P->Elts[P->nbElts-1]=e;
        return 1;
    }
}



int depiler( T_Pile *P, T_Elt *pelt)  //renvoie 0 si pile vide, sinon 1
{
    if(pilevide(P)==1){

        return 0;
    }
    else{
        *pelt=P->Elts[P->nbElts-1];
        P->nbElts=P->nbElts-1;
        return 1 ;
    }
}



T_Elt sommet(const  T_Pile *P)
{
    return P->Elts[P->nbElts-1];
}



int hauteur(const  T_Pile *P)
{
    int haut = P->nbElts;
    return haut ;
}


void afficherPile( T_Pile *P)
{

    T_Elt elt_depilerAux;
    int i=0;
    T_Pile PileAux;
    initPile(&PileAux);
    int taillePile= P->nbElts;
    for (i=0;i<taillePile;i++){
        depiler(P,&elt_depilerAux);
        printf("\n%d",elt_depilerAux);
        empiler(&PileAux,elt_depilerAux);
    }
    for(i=0;i <taillePile;i++){
        depiler(&PileAux,&elt_depilerAux);
        empiler(P,elt_depilerAux);
    }

}

void testPile(T_Pile *P){

    T_Elt elt_empiler ;
    T_Elt elt_depiler;
    int i=0;

    printf("\nOn initialise la Pile ");
    initPile(P);
    printf("\nOn teste si la file est pleine");
    if (pilepleine(P)==1){
        printf("\nLa pile est pleine");
    }
    else{
        printf("\nla pile n'est pas pleine'");
    }
    printf("\n On teste si la file est pleine :");

    if (pilevide(P)==1){
        printf("\nLa pile est vide");
    }
    else{
        printf("\nLa pile n'est pas vide ");
    }

    printf("\non empile la valeur 5 et on affiche la pile");
    elt_empiler=5;
    if (empiler(P,elt_empiler)==0){
        printf("\n Erreur dans l'empilement : La pile est déja pleine ");
    }
    else{
        printf("\n L'ajout a fonctioné ");

    }
    afficherPile(P);
    printf("\nOn affiche le sommet de la pile: %d",sommet(P));
    printf("\nOn affiche la hauteur de la pile: %d",hauteur(P));
    printf("\n On empile jusqu'aux max");
    for (i=0;i<10;i++){
        elt_empiler=i;
        empiler(P,elt_empiler);
    }
    printf("\non affiche la pile");
    afficherPile(P);
    printf("On regarde si la pile est pleine");
    if (pilepleine(P)==1){
        printf("\nLa pile est pleine");
    }
    else{
        printf("\nla pile n'est pas pleine'");
    }
    printf("\non dépile une valeur et on affiche");
    if (depiler(P,&elt_depiler)==0){
        printf("La pile est déja vide ");
    }
    else{
        printf("L'element à été dépilé");
    }
    afficherPile(P);




}