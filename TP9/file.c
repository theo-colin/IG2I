#include "file.h"

void initFile(T_File *ptrF) //mettre Tete et Queue à -1
{
    ptrF->Queue = -1 ;
    ptrF->Tete = -1 ;
    /*printf("queue : %d\n",ptrF->Queue);
    printf("Tete : %d\n",ptrF->Tete); */
}

int  retirer(T_File *ptrF,T_Elt *ptrE) //si pas vide, en tete de file
{
    int i ;
    printf("ptrE ===>: %d \n",*ptrE);
    if (ptrF->Queue > 0)
    {
        if(ptrF->Queue != 1)
        {
            for (i=1 ;ptrF->Queue-1;i++)
            {
                ptrF->Elts[i] = *ptrE ;
            }
        }
        ptrF->Queue = ptrF->Queue-1 ;
        printf("ptrE ===>: %d \n",*ptrE);
        return 1 ;
    }
    else {
        return 0;
    }

}

int ajouter(T_File *ptrF,T_Elt *ptrE) // si espace libre, ajout en queue
{
    if (ptrF->Queue < MAX )
    {
        ptrF->Queue = ptrF->Queue +1 ;
        ptrF->Elts[ptrF->Queue] = *(ptrE) ;
        return 1 ;
    }
    else{
        printf("la file est pleine\n") ;
        return 0 ;
    }
}

int fileVide(const  T_File *ptrF) // qd Tete == 0
{
    if ( ptrF->Tete ==ptrF->Queue)
    {
        printf("la file est vide \n") ;
        return 1;
    }
    else{
        printf("la file n'est pas vide \n");
    }
    return 0 ;
}

int filePleine(const  T_File *ptrF) // qd MAX elts dans la file
{
    if (ptrF->Queue == MAX )
    {
        printf("La file est pleine \n") ;
        return 1 ;
    }
    else{
        printf("la file n'est pas pleine \n") ;
        return 0 ;
    }
}

T_Elt  premier(T_File *ptrF) //valeur en tete de file
{
    return ptrF->Elts[ptrF->Tete];
}

void afficherFile(T_File *ptrF)
{
    int i ;
    for (i=0; i<ptrF->Queue;i++)
    {
        retirer(ptrF ,ptrF->Elts) ;
        premier(ptrF);
        printf("%d",premier(ptrF));
    }

}
void testerfile(T_File *ptrF)
{
    T_Elt elt ;
    initFile(ptrF) ;
    fileVide(ptrF);
    printf("ajouter l'élément :");
    saisirElt(&elt);
    ajouter(ptrF,&elt);
    printf("ajouter l'élément :");
    saisirElt(&elt);
    retirer(ptrF,&elt);
    filePleine(ptrF);
    premier(ptrF);
    afficherFile(ptrF);
    printf("\n%d",ptrF->Queue);
}




