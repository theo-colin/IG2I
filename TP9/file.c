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
    if (ptrF->Queue > 0)
    {
        if(ptrF->Queue != 1)
        {
            for (i=1 ;ptrF->Queue-1;i++)
            {
                ptrF->Elts[i] = ptrF->Elts[i+1] ;
            }
        }
        ptrF->Queue = ptrF->Queue-1 ;
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
        ptrF->Elts[ptrF->Queue] = ptrE ;
    }
    else{
        printf("la file est pleine\n") ;
    }

    return 0;
}

int fileVide(const  T_File *ptrF) // qd Tete == 0
{
    if ( ptrF->Tete ==ptrF->Queue)
    {
        printf("la file est vide \n") ;
        return 0;
    }
    else{
        printf("la file n'est pas vide \n");
    }
    return 1 ;
}

int filePleine(const  T_File *ptrF) // qd MAX elts dans la file
{
    if (ptrF->Queue == MAX )
    {
        printf("La file est pleine \n") ;
    }
    else{
        printf("la file n'est pas pleine \n") ;
    }
    return 0;
}

T_Elt  premier(T_File *ptrF) //valeur en tete de file
{
    printf("le premier élément est :\n");
    afficherElt(ptrF->Elts);
    return 0;
}

void afficherFile(T_File *ptrF)
{
    T_Elt elt_aux;
    int i ;
    T_File file_aux ;
    initFile(&file_aux);
    int taille_file =  ptrF->Queue ;
    for (i = 0 ;i<taille_file ;i++)
    {
        retirer(ptrF,&elt_aux);
        printf("\n%d",elt_aux);
    }
    for (i = 0 ;i <taille_file ; i++)
    {
        retirer(&file_aux,&elt_aux);
        ajouter(ptrF,elt_aux);
    }
}
void testerfile(T_File *ptrF)
{
    T_Elt elt ;
    initFile(ptrF) ;
    fileVide(ptrF);
    printf("ajouter l'élément :");
    scanf("%d",&elt);
    ajouter(ptrF,elt);
    printf("\nretirer l'élément :");
    scanf("%d",&elt);
    retirer(ptrF,elt);
    filePleine(ptrF);
    premier(ptrF);
    afficherFile(ptrF);
    printf("\n%d",ptrF->Queue);

}




