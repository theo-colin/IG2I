#ifndef BIBLIO_H   //compilation conditionnelle
#define BIBLIO_H


#include "livre.h"
#include <time.h>

#define CAPACITE_BIBLIO 20 // nb maximum de livres ds la bibliotheque

typedef  T_livre 	T_tabloDeLivres[CAPACITE_BIBLIO];

typedef struct
{
	T_tabloDeLivres etagere;
	int nbLivres;  //nb de livres actuellement ds la bibliotheque

} T_Bibliotheque;




//prototypes
void init (T_Bibliotheque *ptrB);
int ajouterLivre(T_Bibliotheque  *ptrB);
int  afficherBibliotheque(const T_Bibliotheque  *ptrB);
int rechercherTitre(T_Bibliotheque *ptrB,char *rechercheT);
int rechercherAuteur(T_Bibliotheque *ptrB,char *rechercheA);
int emprunter(T_Bibliotheque *ptrB ,char *rechercheT,char *rechercheA) ;
int restituer(T_Bibliotheque *ptrB ,char *rechercheT,char *rechercheA);
int trieurTitre(T_Bibliotheque *ptrB);
int trieurAuteur(T_Bibliotheque *ptrB);
int trieurAnnee(T_Bibliotheque *ptrB);
int supprimer(T_Bibliotheque *ptrB, char *rechercheT,char *rechercheA) ;
void chargement(T_Bibliotheque *ptrB) ;
void sauvegarde(T_Bibliotheque *ptrB) ;
void afficherLivreEmp(T_livre *L);
void lireDateSysteme(T_Emp *E);
int afficherlivredisponible(T_Bibliotheque *ptrB);
int afficherlisteRetard(T_Bibliotheque *ptrB);


#endif
