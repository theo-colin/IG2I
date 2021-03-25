#include "file.h" 

void testfile(T_File *ptrF)
{
    initFile(mafile) ;

}

void initFile(T_File *ptrF) //mettre Tete et Queue à -1
{
    ptrF->Queue = -1 ;
    ptrF->Tete = -1 ;
    printf("queue : %d et Tete : %d", ptrF->Queue ,ptrF->Tete) ;
}

int  retirer(T_File *ptrF,T_Elt *ptrE) //si pas vide, en tete de file
{
    if (ptrF->Queue != ptrF->Tete)
    {
           ptrF->Tete = -1 ;
    }
return 0;
}

int ajouter(T_File *ptrF,T_Elt *ptrE) // si espace libre, ajout en queue
{
    if(ptrF->Elts[ptrF->Queue] < ptrF->Elts[MAX] )
    {
        ptrF->Queue = ptrF->Queue + 1 ;
        printf("quel est le nouvel élément ? \n");
        saisirElt(&ptrE) ;
    }
    else {
        printf("il n'y a pas d'espace libre \n") ;
    }
return 0;
} 

int fileVide(const  T_File *ptrF) // qd Tete == 0
{
    if(ptrF->Tete == ptrF->Queue)
    {
        printf("la file est vide \n") ;

    }
return 0;
}

int filePleine(const  T_File *ptrF) // qd MAX elts dans la file 
{
    if (ptrF->Elts[ptrF->Queue] == ptrF->Elts[MAX])
    {
        printf("La file est pleine") ;
    }
return 0;
}

T_Elt  premier(T_File *ptrF) //valeur en tete de file
{
    printf("la valeur en tête de file est : %d \n", ptrF->Elts[ptrF->Queue]);
return 0;
}

void afficherFile(T_File *ptrF)
{
    int i ;
    for (i= 0 ; i<ptrF->Queue ; i++)
    {
        printf("%d \n",ptrF->Elts[i]);

    }
}






