# include "biblio.h"

void init (T_Bibliotheque *ptrB)
{

ptrB->nbLivres=0;
// ou (*ptrB).nbLivres=0;
}

int ajouterLivre(T_Bibliotheque  *ptrB)
{
if (ptrB->nbLivres< CAPACITE_BIBLIO )// reste t il de la place?
	{
	saisirLivre(&(ptrB->etagere[ptrB->nbLivres]));
	ptrB->nbLivres++;
	return 1;
	}
	
	
return 0;
	
}


int  afficherBibliotheque(const T_Bibliotheque  *ptrB)
{
int i;
if(ptrB->nbLivres==0)
	return 0;
	else
		{
		for(i=0;i<ptrB->nbLivres;i++)
			{
			afficherLivre( &(ptrB->etagere[i])  );
			
			}


		
		return 1;
		}
}

int rechercherTitre(T_Bibliotheque*ptrB,char *rechercheT){//la fonction renvoie le nombre d'exemplaire du livre recherché .
	int i ;
	int compteur=0; //Compteur qui permet de renvoyer le nombre de livre trouvé 	
	if(ptrB->nbLivres==0){
		return 0 ;
	}
	else{
		for (i=0;i<ptrB->nbLivres;i++){
			if (strcmp(rechercheT,ptrB->etagere[i].titre)==0){
				compteur=compteur+1
				;
			}
			
		}
		
		return compteur;
	}
}


int rechercherAuteur(T_Bibliotheque *ptrB,char *rechercheA){
	int i ;
	int compteur=0;// Compteur qui permet de renvoyer le nombre de livre trouvé 	
	if(ptrB->nbLivres==0){
		return 0 ;
	}
	else{
		for(i=0;i<ptrB->nbLivres;i++){
			if(strcmp(rechercheA,ptrB->etagere[i].auteur)==0){
				printf("\nL'auteur %s a écrit le livre <%s>",rechercheA,ptrB->etagere[i].titre);
				compteur=compteur+1;
				
			}
			
		}
		return compteur;
	}
}

int supprimer(T_Bibliotheque *ptrB, char *rechercheT,char *rechercheA) {
	int i;
	int lim=0;//limite qui lorsqu'il n'y a pas le livre chercher permet de renvoyer 0 
	int indice=0 ;//indice de la position du livre à supprimer
	if(ptrB->nbLivres==0){
		return 0 ;
	}
	for (i=0;i<ptrB->nbLivres;i++){
		if(strcmp(rechercheT,ptrB->etagere[i].titre)==0 && strcmp(rechercheA,ptrB->etagere[i].auteur)==0){
			indice=i;
		}
		else{
			lim++;
		}
	}
	if (lim==ptrB->nbLivres){
	return 0;
	}
	else{
		for(i=indice;i<ptrB->nbLivres;i++){
			strcpy(ptrB->etagere[i].titre,ptrB->etagere[i+1].titre);
			strcpy(ptrB->etagere[i].auteur,ptrB->etagere[i+1].auteur);
			
		}
		(ptrB->nbLivres)--;
		printf("%d",ptrB->nbLivres);
		return 1;
	}

}






