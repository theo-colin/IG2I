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


int trieurTitre(T_Bibliotheque *ptrB)
{
    int i ;
    int a ;
    T_Bibliotheque aux ;

    for(i=0;i-1<ptrB->nbLivres;i++)
    {
        if(strcmp(ptrB->etagere[i].titre,ptrB->etagere[i+1].titre)<0)
        {
            aux.etagere[i] = ptrB->etagere[i] ;
            ptrB->etagere[i] = ptrB->etagere[i+1] ;
            ptrB->etagere[i+1] = aux.etagere[i]  ;
        }

    }

    //il faut inverser le tableau car la fonction trie actuellement dans l'ordre inverse de l'alphabet
    i=0 ;

    while(i < ptrB->nbLivres/2 )
    {
        aux.etagere[i] = ptrB->etagere[i];
        ptrB->etagere[i] = ptrB->etagere[ptrB->nbLivres-1-i] ;
        ptrB->etagere[ ptrB->nbLivres-1-i] = aux.etagere[i] ;
        i=i+1 ;
    }
    a = ptrB->nbLivres ;
    printf("nblivres : %d \n",a);
    return 0 ;
}

int trieurAuteur(T_Bibliotheque *ptrB)
{
    int i ;
    int a ;
    T_Bibliotheque aux ;
    for(i=0;i-1<ptrB->nbLivres;i++)
    {
        if(strcmp(ptrB->etagere[i].auteur,ptrB->etagere[i+1].auteur)<0)
        {
            aux.etagere[i] = ptrB->etagere[i] ;
            ptrB->etagere[i] = ptrB->etagere[i+1] ;
            ptrB->etagere[i+1] = aux.etagere[i]  ;
        }

    }
    //il faut inverser le tableau car la fonction trie actuellement dans l'ordre inverse de l'alphabet
    i=0 ;
    while(i < ptrB->nbLivres/2 )
    {
        aux.etagere[i] = ptrB->etagere[i];
        ptrB->etagere[i] = ptrB->etagere[ptrB->nbLivres-1-i] ;
        ptrB->etagere[ ptrB->nbLivres-1-i] = aux.etagere[i] ;
        i=i+1 ;
    }
    a = ptrB->nbLivres ;
    printf("nblivres : %d \n",a);

    return 0 ;
}

int trieurAnnee(T_Bibliotheque *ptrB)
{
    int i ;
    int a ;
    T_Bibliotheque aux ;
    for(i=0;i-1<ptrB->nbLivres;i++)
    {
        if(ptrB->etagere[i].annee > ptrB->etagere[i+1].annee)
        {
            aux.etagere[i] = ptrB->etagere[i] ;
            ptrB->etagere[i] = ptrB->etagere[i+1] ;
            ptrB->etagere[i+1] = aux.etagere[i]  ;
        }

    }
    a = ptrB->nbLivres ;
    printf("nblivres : %d \n",a);

    return 0 ;
}




int  afficherBibliotheque(const T_Bibliotheque *ptrB)
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
				compteur=compteur+1;
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

int emprunter(T_Bibliotheque *ptrB, char *rechercheT, char *rechercheA)
{
    int i = 0;
    int indice =0;
    char Nomemp[MAX];
    if(rechercherTitre(ptrB,rechercheT)==0)
    {
        return 0;
    }
    else{
        for (i=0;i<ptrB->nbLivres;i++){
            if(strcmp(rechercheT,ptrB->etagere[i].titre)==0 && strcmp(rechercheA,ptrB->etagere[i].auteur)==0)//on recherche l'indice du livre à emprunter
            {
                indice=i;

            }
        }
        if(strcmp(ptrB->etagere[indice].emprunteur.nomemprunteur,"")==0){
            printf("Entre votre nom :");
            strcpy(ptrB->etagere[indice].emprunteur.nomemprunteur,lire(Nomemp,MAX));
            lireDateSysteme(&ptrB->etagere[indice].emprunteur);
            afficherLivreEmp(&ptrB->etagere[indice]);
            return 1;
        }
        else {
            return 2 ;
        }

    }
}

int restituer(T_Bibliotheque *ptrB ,char *rechercheT,char *rechercheA){
    int i=0;
    int indice=0;

    if(rechercherTitre(ptrB,rechercheT)==0)
    {
        return 0;
    }
    else{
        for (i=0;i<ptrB->nbLivres;i++){
            if(strcmp(rechercheT,ptrB->etagere[i].titre)==0 && strcmp(rechercheA,ptrB->etagere[i].auteur)==0){//on recherche l'indice du livre à restituer
                indice=i;
            }
        }
        if(strcmp(ptrB->etagere[indice].emprunteur.nomemprunteur,"")!=0){
            strcpy(ptrB->etagere[indice].emprunteur.nomemprunteur,"");
            return 1;
        }
        else {
            return 2;
        }
    }
}

int afficherlivredisponible(T_Bibliotheque *ptrB)
{
    int i;

        for (i = 0; i < ptrB->nbLivres; i++) {
            if( (strlen(ptrB->etagere[i].emprunteur.nomemprunteur) <=0 ))
            {
                afficherLivre(&(ptrB->etagere[i]));
            }

        }

    return 0 ;
}

int afficherlisteRetard(T_Bibliotheque *ptrB)
{
    int i;
    int date_limite ;


    for (i = 0; i < ptrB->nbLivres; i++){
        if( (strlen(ptrB->etagere[i].emprunteur.nomemprunteur) >=1 ))
        {
            afficherLivre(&(ptrB->etagere[i]));
            lireDateSysteme(&ptrB->etagere[i].emprunteur);
            //afficherLivreEmp(&ptrB->etagere[i]);
            printf("ladate est :%d \n",ptrB->etagere[i].emprunteur.ladate);
            time_t temps = time( NULL );
            printf( "Timestamp since January 1, 1970: %ld\n", temps );
            date_limite = temps + 604800 ;
            if(temps> date_limite)
            {
                printf("l'emprunteur est en retard ");
            }

        }

    }
    return 0;
}



void sauvegarde(T_Bibliotheque *ptrB)
{
    FILE *fic=NULL; //le type FILE
    int i;
    fic=fopen("baseLivres","w"); // w = le mode = write avec ECRASEMENT
//fopen renvoie NULL si probleme (disque plein, disque non accessible ...
    if (fic!=NULL)
    {
        for(i=0;i<ptrB->nbLivres;i++)
        {
//fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream)
            fwrite(  &(ptrB->etagere[i])        ,sizeof(T_livre),1,fic);

        }
        fclose(fic);
        puts("SAUVEGARDE REUSSIE ..............");



    }
    else puts("ECHEC DE SAUVEGARDE  !!!!!  ");




}


void chargement(T_Bibliotheque *ptrB)
{
    FILE *fic=NULL; //le type FILE
    int i=0;
    fic=fopen("baseLivres","r"); // r = le mode read
//fopen renvoie NULL si probleme (disque plein, disque non accessible ...
    if (fic!=NULL)
    {
        do
        {

            fread(  &(ptrB->etagere[i]) ,sizeof(T_livre),1,fic);
            i++;
        }
        while(!feof(fic));
        fclose(fic);
        ptrB->nbLivres=i-1;
        puts("CHARGEMENT  REUSSI ..............");
    }
    else puts("ECHEC DE CHARGEMENT  !!!!!  ");

}

void afficherLivreEmp(T_livre *L)
{

    char jour[13],mois[13];

    printf("\n titre du livre : %s",L->titre);

    printf("\n emprunteur du livre : %s",L->emprunteur.nomemprunteur);

    printf("\n  emprunt realise le : ");
    switch(L->emprunteur.lejour)
    {
        case 0 :  strcpy(jour,"lundi");break;
        case 1 :  strcpy(jour,"mardi");break;
        case 2 :  strcpy(jour,"mercredi");break;
        case 3 :  strcpy(jour,"jeudi");break;
        case 4 :  strcpy(jour,"vendredi");break;
        case 5 :  strcpy(jour,"samedi");break;
        case 6 :  strcpy(jour,"dimanche");break;

        default : strcpy(jour,"jour inconnu");break;
    }
    printf("%s ",jour);

    printf("%d ",L->emprunteur.ladate);


    switch(L->emprunteur.lemois)
    {
        case 0 :  strcpy(mois,"janvier");break;
        case 1 :  strcpy(mois,"fevrier");break;
        case 2 :  strcpy(mois,"mars");break;
        case 3 :  strcpy(mois,"avril");break;
        case 4 :  strcpy(mois,"mai");break;
        case 5 :  strcpy(mois,"juin");break;
        case 6 :  strcpy(mois,"juillet");break;
        case 7 :  strcpy(mois,"aout");break;
        case 8 :  strcpy(mois,"septembre");break;
        case 	9 :  strcpy(mois,"octobre");break;
        case 10 :  strcpy(mois,"novembre");break;
        case 11 :  strcpy(mois,"decembre");break;

        default : strcpy(jour,"mois inconnu");break;
    }
    printf("%s ",mois);

    printf("%d ",L->emprunteur.lannee);


}
void lireDateSysteme(T_Emp *E)
{
    char j[9],m[10],h[9],mer[11],vir[2];
    int d,a;


    system("date '+ %A %d %B %Y'> ladate"	);
    FILE * fic=NULL;  // pointeur de fichier
    fic=fopen("ladate","r"); //fileOpen en mode 'r'EAD

//ici , si fic vaut NULL, alors le fopen a indiquÃ©
//que le fichier ladate n'est pas accessible
    if (fic!=NULL)
    {
        while(!feof(fic))
        {
            fscanf(fic,"%s %d %s %d %s %s %s",j,&d,m,&a,vir,h,mer);
            if (!feof(fic))
                printf("\n-->LU : %s- %d- %s- %d- %s- %s",j,d,m,a,h,mer);

        }
        fclose(fic);
        if (strcmp(j,"lundi")==0) E->lejour=lundi;
        if (strcmp(j,"mardi")==0) E->lejour=mardi;
        if (strcmp(j,"mercredi")==0) E->lejour=mercredi;
        if (strcmp(j,"jeudi")==0) E->lejour=jeudi;
        if (strcmp(j,"vendredi")==0) E->lejour=vendredi;
        if (strcmp(j,"samedi")==0) E->lejour=samedi;
        if (strcmp(j,"dimanche")==0) E->lejour=dimanche;

        E->ladate=d;

        if (strcmp(m,"janvier")==0) E->lemois=janvier;
        if (strcmp(m,"fevrier")==0) E->lemois=fevrier;
        if (strcmp(m,"mars")==0) E->lemois=mars;
        if (strcmp(m,"avril")==0) E->lemois=avril;
        if (strcmp(m,"mai")==0) E->lemois=mai;
        if (strcmp(m,"juin")==0) E->lemois=juin;
        if (strcmp(m,"juillet")==0) E->lemois=juillet;
        if (strcmp(m,"aout")==0) E->lemois=aout;
        if (strcmp(m,"septembre")==0) E->lemois=septembre;
        if (strcmp(m,"octobre")==0) E->lemois=octobre;
        if (strcmp(m,"novembre")==0) E->lemois=novembre;
        if (strcmp(m,"decembre")==0) E->lemois=decembre;


        E->lannee=a;
    }
    else
    {
        printf("n souci avec la date systeme !!");

        //on range une date irrÃ©elle
        E->lejour=dimanche;
        E->ladate=99;
        E->lemois=decembre;
        E->lannee=-999;


    }

}






