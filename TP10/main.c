////////////////////////// TP10

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prod.h"

int lireProchaineCommande() //pour lire l'int contenu dans nextFact
{
    FILE *f;
    int N;
    f=fopen("nextFact","r");
    fread(&N,sizeof(int),1,f);
    fclose(f);
//printf("\n--->lu N=%d",N);
    return N;
}

void convertirNenChaine4(int N,char *N4) //convertit l'int N en une chaine de 4 caracteres
{ // si N=1234 alors N4 sera égal à "1234"
    int m,c,d,u;
    char cm,cc,cd,cu;
    m=N/1000;cm=48+m;
    N%=1000;
    c=N/100;cc=48+c;
    N%=100;
    d=N/10;cd=48+d;
    u=N%10;
    cu=48+u;
    N4[0]=cm;N4[1]=cc;N4[2]=cd;N4[3]=cu;N4[4]='\0';
}

int RemplirLalistedeProduits(T_TableauDeProduits liste){//permet de creer la liste des produits
    int prod_ref;
    char prod_libelle[TAILLE];
    float prod_prixU ;
    int tailleliste=0;
    FILE *ficProduit=NULL;
    ficProduit=fopen("produits.txt","rt");
    if (ficProduit!=NULL){
        do{
            fscanf(ficProduit,"%d %s %f",&prod_ref,prod_libelle,&prod_prixU);
            liste[tailleliste].reference=prod_ref;
            strcpy(liste[tailleliste].libelle,prod_libelle);
            liste[tailleliste].prixU=prod_prixU;
            tailleliste++;
        }
        while(!(feof(ficProduit)) && tailleliste<NB_MAX_PRODUITS);
        return tailleliste;

    }
    else{
        printf("\nLe fichier produits.txt n'existe pas !\n");
        return 0;

    }
    //fclose(ficProduit);
}


void ecrireFacture(FILE* ficF,char lib[TAILLE],float prixU, int quantite){

    float prixqte=prixU*quantite;
    if(ficF!=NULL){
        fprintf(ficF,"%d %s (PU=%.2f€)::%.2f€\n",quantite,lib,prixU,prixqte);//&prixU*&quantite//
    }
}

void ecrireStock(FILE* ficS,int ref,int qtt){

    fprintf(ficS,"%d %d\n",ref,qtt);
}


void lirestock(T_TableauStock listeStock){
    FILE *ficStock=NULL;
    ficStock=fopen("stock.txt","rt");
    int stock_ref;
    int stock_qtt;
    int taille_liste=0;
    if (ficStock!=NULL){
        do {

            fscanf(ficStock,"%d %d",&stock_ref,&stock_qtt);
            //printf("\n%d %d",stock_ref,stock_qtt);//affichage
            listeStock[taille_liste].reference=stock_ref;
            listeStock[taille_liste].qtt=stock_qtt;
            taille_liste++;
        }
        while(!(feof(ficStock)));
        fclose(ficStock);
    }
}


void lireCommande(FILE* fcommande,FILE* ficF,int fonction,char nomCommande[29]){//fcommande est déja ouvert donc pas besoin de le réouvrir en mettant en argument le nom de la commande ...
    //Dans cette fonction on va lire la commande , génerer la liste de produit ,puis créer la facture .
    char client[TAILLE];
    int ref;
    int qtt;
    int Nbr_liste;//connaitre la taille de la liste
    int i ;
    float total =0;// variables qui stock le prix  total de la facture
    FILE* ficStock=NULL;
    FILE* ficAlert=NULL;
    T_TableauDeProduits Lesproduits;
    T_TableauStock LeStock;//Initialise une liste de stock

    Nbr_liste=RemplirLalistedeProduits(Lesproduits);
    //printf("\nTaille de la liste: %d\n",Nbr_liste);
    //test de la struc produit printf("\n%s\n",Lesproduits[0].libelle);
    fscanf(fcommande,"%s",client);
    fprintf(ficF,"client: %s\n",client);//on ecrit le nom du client sur la facture
    printf("\nLe client est :%s",client);
    do {
        fscanf(fcommande,"%d %d",&ref,&qtt);
        printf("\n %d %d",ref,qtt );

        if (fonction ==2){//on regarde si on a utilisé la fonction lireLesCommandes2
            lirestock(LeStock);//on lit le stock pour pouvoir le modifier en suite
            ficStock=fopen("stock.txt","wt");//on ouvre le fichier a chaque commande
            ficAlert=fopen("alertes.txt","wt");
        }

        for (i=0;i<Nbr_liste;i++){
            if(ref==Lesproduits[i].reference){
                //test printf(" ligne dans produits: %d",i+1);
                ecrireFacture(ficF,Lesproduits[i].libelle,Lesproduits[i].prixU,qtt);//on ecrit le detail des produit acheter
                total = total + Lesproduits[i].prixU * qtt;
            }

            if(fonction ==2 ){//Le stock à le meme nombre de ligne que le fichier produits


                if(ficStock!=NULL) {
                    if (LeStock[i].reference == ref)
                        if (LeStock[i].qtt - qtt >= 0) {
                            LeStock[i].qtt = LeStock[i].qtt - qtt;
                        } else {
                            printf("\nPLUS DE STOCK");
                            fprintf(ficAlert, "La %s n'a pas pu être traiter, pas assez de stock disponible",
                                    nomCommande);
                        }
                        ecrireStock(ficStock, LeStock[i].reference, LeStock[i].qtt);
                    }

                else{
                    ecrireStock(ficStock,LeStock[i].reference,LeStock[i].qtt);
                }
            }
            //printf("\nLE STOCK =>%d",LeStock[i].qtt);

        }
        if (fonction==2){
            fclose(ficStock);
            fclose(ficAlert);
        }
    }
    while(!(feof(fcommande)));
    fprintf(ficF,"\n\tTOTAL= %f\n",total);//on ecrit le prix total

}


void lireLesCommandes() //cette fonction ouvre tous les fichiers commandeXXX.txt avec XXXX démarrant à N
{
    FILE *ficCommande=NULL;
    FILE *ficFacture = NULL;
    int FINI=0;
    int N = lireProchaineCommande(); //numero de la premiere commande qui sera lue et traitee
    char NNNN[5];
    char nomCommande[29];
    char nomFacture[TAILLE];

    do //ce do while prend fin dès que fichier commandeXXXX.txt est absent
    {
        strcpy(nomCommande,"./commandes/commande");
        strcpy(nomFacture,"./factures/facture");
        convertirNenChaine4(N,NNNN);
        //printf("\n==>%s<==",NNNN);
        ficCommande=NULL;
        ficFacture=NULL;
        strcat(nomCommande,NNNN);
        strcat(nomCommande,".txt");
        strcat(nomFacture,NNNN);
        strcat(nomFacture,".txt");

        //printf("\n traitement de  %s",nomCommande);

        ficCommande=fopen(nomCommande,"rt");
        ficFacture = fopen(nomFacture,"wt");
        if (ficCommande!=NULL)
        { // le fichier commandeNNNN.txt existe
            printf("\n fichier %s present",nomCommande);
            //lireCommande(nomCommande); // à vous de coder cette fonction lors de ce TP9
            lireCommande(ficCommande,ficFacture,1,nomCommande);
            fclose(ficCommande);
            fclose(ficFacture);
        }
        else
        {
            printf("\n toutes les commandes presentes ont ete traitees.");
            FILE *f=fopen("nextFact","w"); // on va ecrire la valeur de N dans enxtFact
            // pour
            fwrite(&N,1,sizeof(int),f);
            fclose(f);
            FINI=1;
        }

        N++;
    }while(FINI==0);

}


void lireLesCommandes2(){

    FILE *ficCommande=NULL;
    FILE *ficFacture = NULL;
    int FINI=0;
    int N = lireProchaineCommande(); //numero de la premiere commande qui sera lue et traitee
    char NNNN[5];
    char nomCommande[29];
    char nomFacture[TAILLE];

    do //ce do while prend fin dès que fichier commandeXXXX.txt est absent
    {
        strcpy(nomCommande,"./commandes/commande");
        strcpy(nomFacture,"./factures/facture");
        convertirNenChaine4(N,NNNN);
        //printf("\n==>%s<==",NNNN);
        ficCommande=NULL;
        ficFacture=NULL;
        strcat(nomCommande,NNNN);
        strcat(nomCommande,".txt");
        strcat(nomFacture,NNNN);
        strcat(nomFacture,".txt");

        //printf("\n traitement de  %s",nomCommande);

        ficCommande=fopen(nomCommande,"rt");
        ficFacture = fopen(nomFacture,"wt");
        if (ficCommande!=NULL)
        { // le fichier commandeNNNN.txt existe
            printf("\n fichier %s present",nomCommande);
            //lireCommande(nomCommande); // à vous de coder cette fonction lors de ce TP9
            lireCommande(ficCommande,ficFacture,2,nomCommande);//fonction 2
            fclose(ficCommande);
            fclose(ficFacture);
        }
        else
        {
            printf("\n toutes les commandes presentes ont ete traitees.");
            FILE *f=fopen("nextFact","w"); // on va ecrire la valeur de N dans enxtFact
            // pour
            fwrite(&N,1,sizeof(int),f);
            fclose(f);
            FINI=1;
        }

        N++;
    }while(FINI==0);

}





int main()
{

    int choix ;
    FILE *f;int N=1;

    do {
        //creation d un fichier d'un seul int nommé nextFact et contenant l'int 1
        // code à utiliser pour réinitialiser nextFact à 1 si besoin au cours du TP

        f=fopen("nextFact","w");
        fwrite(&N,1,sizeof(int),f);
        fclose(f);

        printf("\n\n1: Générer des factures sans gestion des stocks");
        printf("\n2: Générer des factures avec la gestion des stocks");
        printf("\n0: Quitter");
        printf("\n\nVotre choix :");
        scanf("%d",&choix);

        switch (choix){
            case 1 :
                lireLesCommandes();
                break;
            case 2 :
                lireLesCommandes2();
        }

    }
    while(choix !=0);
    //PARTIE 1 du TP : sans Gestion de stock
    //lireLesCommandes(); //lecture de tous les fichiers commandeXXX.txt (fichiers non traités jusqu'ici)


    //PARTIE 2 du TP : avec Gestion de stock
    //copiez coller votre travail précédent puis modifiez le
    //lireLesCommandes2();

    return 0;
}
   /*     FILE *ficalertes=fopen("alertes.txt","wt");
        if(ficalertes!=NULL) {
            fprintf(ficalertes," %d n'a pas pu assez de stock \n", ref);
            fprintf(ficalertes," donc  la commande => %s n'a pas pu être traitée\n", nomCommande);
        }*/