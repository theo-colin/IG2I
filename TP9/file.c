#include "file.h"


void initFile(T_File *ptrF) //mettre Tete et Queue à -1
{
    ptrF->Queue = -1 ;
    ptrF->Tete = -1 ;
}

int  retirer(T_File *ptrF,T_Elt *ptrE) //si pas vide, en tete de file
{
    int i ;
    if (ptrF->Queue > 0)
    {
        for (i=0; i<ptrF->Queue ;i++)
        {

        }

    }
    return 0;
}

int ajouter(T_File *ptrF,T_Elt *ptrE) // si espace libre, ajout en queue
{

    if (ptrF->Queue < MAX )
    {
        ptrF->Queue = ptrF->Queue +1 ;
        saisirElt(ptrF->Elts[ptrF->Queue]);
    }
    else{
        printf("la file est pleine\n") ;
    }
    return 0;
}

int fileVide(const  T_File *ptrF) // qd Tete == 0
{
    if ( ptrF->Tete ==0)
    {
        printf("la file est vide \n") ;
    }
    return 0;
}

int filePleine(const  T_File *ptrF) // qd MAX elts dans la file
{
    if (ptrF->Queue == MAX )
    {
        printf("La file est pleine \n") ;
    }
    return 0;
}

T_Elt  premier(T_File *ptrF) //valeur en tete de file
{
    printf("le premier élément est :\n");
    afficherElt(ptrF->Elts[ptrF->Tete]);
    return 0;
}

void afficherFile(T_File *ptrF)
{
    int i ;
    for (i=0 ; i> ptrF->Queue ; i++)
    {
        afficherElt(ptrF->Elts[i]);

    }
}





