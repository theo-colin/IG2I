#include "livre.h"
//

void saisirLivre(T_livre * ptrL)
{
lireChaine("TITRE :", (ptrL->titre), MAX_TITRE );
lireChaine("AUTEUR :", (ptrL->auteur ), MAX);
lireChaine("EDITEUR :",(ptrL ->editeur),MAX) ;
lireChaine("EMPRUNTEUR :",(ptrL ->emprunteur.nomemprunteur),MAX);
lireChaine("CODE :",(ptrL->code),MAX_CODE);
printf("ANNÉE :");
scanf("%d",&(ptrL->annee));
}

void afficherLivre(const T_livre *ptrL)
{
afficherChaine("TITRE :", (ptrL->titre));
printf(" - ");
afficherChaine("AUTEUR :", (ptrL->auteur ));
printf(" - ");
afficherChaine("EDITEUR :",(ptrL->editeur));
printf(" - ");
afficherChaine("EMPRUNTEUR :",(ptrL ->emprunteur.nomemprunteur));
printf(" - ");
afficherChaine("CODE :",(ptrL->code));
printf(" - ");
printf("ANNÉE : %d",(ptrL->annee));
printf("\n");


}



