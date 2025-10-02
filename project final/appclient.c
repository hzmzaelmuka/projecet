#include <stdio.h>
#include <string.h>
#include <strings.h>
#define MAX_PRODUITS 5
typedef struct {
    char idClient[10];
    char nom[50];
    char prenom[50];
    char email[100];
    float solde;
} Client;
Client client;
int cmpClient = 0;

typedef struct {
    int idProduit;
    char nom[50];
    char categorie[30];
    float prix;
    int stock;
    char description[100];
} Produit;
Produit catalog[MAX_PRODUITS] = {
    {1, "Ordinateur Portable", "Electronique", 500, 5, "Un ordinateur portable performant pour le travail et les jeux."},
    {1, "Ordinateur Portable", "Electronique",500 , 5, "Un ordinateur portable performant pour le travail et les jeux."},
    {1, "Ordinateur Portable", "Electronique", 500, 5, "Un ordinateur portable performant pour le travail et les jeux."},
    {1, "Ordinateur Portable", "Electronique", 500, 5, "Un ordinateur portable performant pour le travail et les jeux."},
    {1, "Ordinateur Portable", "Electronique", 500, 5, "Un ordinateur portable performant pour le travail et les jeux."},
};
void Profil();
    void Creation();
    void emailId();
    void AfficherProfil();
    void Modification();
void Solde();
    void afficherSolde();
    void deposerArgent();
void consultationProduits();
    void RecherchNom();
    void RecherchCategorie();
    void afficherDetailsProduit();
    void afficherCatalogue();
void Effectuer();

void Statistiques(){};

int main() {
    int choix;
    do {
        printf("\n==================== SYSTEME D ACHAT CLIENT ====================\n");
        printf("1 : Gestion du profil client\n");
        printf("2 : Gestion du solde virtuel\n");
        printf("3 : Consultation des produits\n");
        printf("4 : Effectuer un achat\n");
        printf("5 : Mes statistiques\n");
        printf("6 : Quitter l application\n");
        printf("Veuillez saisir votre choix (1-6) : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1: Profil();break;
            case 2: Solde();break;
            case 3: consultationProduits();break;
            case 4: Effectuer();break;
            case 5: Statistiques();break;
            case 6: printf("Merci pour votre visite. a bientot !\n"); break;
            default: printf("Choix invalide !\n");
        }
} while (choix != 6);
return 0;
}
void Profil() {
    int choix;
    do {
        printf("\n~~~~~~~~~~~~~~ Gestion du profil ~~~~~~~~~~~~~~\n");
        printf("1. Creer un compte\n");
        printf("2. Afficher le compte\n");
        printf("3. Modifier le compte\n");
        printf("0. Quitter vers l accueil\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choix);
switch (choix) {
            case 1:
                if (cmpClient == 1) {
                    printf("Le compte existe deja.\n");
                } else {
                    Creation();
                }
                break;
            case 2:
                if (cmpClient == 0) {
                    printf("Le compte n existe pas. Veuillez en creer un d abord.\n");
                } else {
                    AfficherProfil();
                }
                break;
            case 3:
                if (cmpClient == 0) {
                    printf("Le compte n existe pas. Veuillez en creer un d abord.\n");
                } else {
                    Modification();
                }
                break;
            case 0:
                printf("Retour a l accueil.\n");
                break;
            default:
                printf("Choix invalide.\n");
        }
    } while (choix != 0);
}
void Creation() {
    printf("\n              LA CREATION DE COMPTE         \n ");
    client.solde = 0.0;
    printf("\nEntrez le nom : ");
    scanf(" %[^\n]", client.nom);
    printf("Entrez le prenom : ");
    scanf("%s", client.prenom);
   emailId();
    cmpClient = 1;
    printf("Compte cree avec succes \n");
}
void emailId(){
    int j=0;
    char nome[50];
    for(int i=0;client.nom[i]!='\0';i++){
        if(client.nom[i]!=' '){
        nome[j++]=client.nom[i];

    }}
    nome[j]='\0';

    strcpy(client.email,nome);
    strcat(client.email, ".");
    strcat(client.email, client.prenom);
    strcat(client.email, "@gmail.com");
    sprintf(client.idClient, "%c.%c", client.prenom[0], client.nom[0]);}

void AfficherProfil() {
    printf("\n===========================================\n");
    printf("                \\  LE PROFIL  //          \n");
    printf("===========================================\n");
    printf("Nom complet        : %s %s\n", client.prenom, client.nom);
    printf("ID Client          : %s\n", client.idClient);
    printf("Adresse e-mail     : %s\n", client.email);
    printf("Solde disponible   : %.2f MAD\n", client.solde);
}
void Modification() {
    printf("\n              LA MODIFICATION DE COMPT       \n ");
    printf("\nEntrez le nouveau nom : ");
    scanf(" %[^\n]",client.nom);
    printf("Entrez le nouveau prenom : ");
    scanf("%s", client.prenom);
    printf("Profil mis a jour avec succes \n");
    emailId();
}
void Solde(){
    int choix ;
     if (cmpClient== 0){
        printf("Veuillez creer un compte d abord.\n");
    } else {
do {
        printf("\n===  GESTION DU SOLDE VIRTUEL ===\n");
        printf("1. Consulter le solde\n");
        printf("2. Deposer de l argent\n");
        printf("0. Fermez cette page \n");
        printf("Votre choix : ");
        scanf("%d", &choix);
switch (choix) {
            case 1:
                afficherSolde();
            break;
            case 2:
                deposerArgent();
                break;
            case 0:
                printf(" Au revoir !\n");
                break;
            default:
                printf(" Choix invalide, veuillez réessayer.\n");
        }

    } while (choix != 0);
}
}

void afficherSolde() {
if (cmpClient == 0) {
 printf("Le compte n existe pas. Veuillez en creer un d abord.\n");
 } else {
 printf("\n Votre solde actuel est : %.2f DH\n", client.solde);
}}
void deposerArgent() {
    float montant;
    printf("\n  Entrez le montant a deposer : ");
    scanf("%f", &montant);

    if (montant <= 0) {
        printf(" Montant invalide ! Il doit être superieur a 0.\n");
    } else {
        client.solde += montant;
        printf(" %.2f MAD ont ete deposes avec succes !\n", montant);
        afficherSolde();
    }
}
void consultationProduits(){
    int choix;
    afficherCatalogue();
do{
        printf("________________________________________________________________");
printf("\n 1 :  details un produit ");
printf("\n 2 :  recherche un produit par nom" );
printf("\n 3 :  recherche un produit par categorie" );
printf("\n 4 :  tri des produits par pri ou alphabe");
printf("\n 5 :  Retour au menu principal.\n");
switch(choix){
          case 1 :afficherDetailsProduit();break;
          case 2 :RecherchNom();break;
          case 3 :RecherchCategorie();break;
 }
        printf("\nVoulez-vous consulter un autre produit ? (1: Oui, 0: Non): ");
        scanf("%d", &choix);
 } while (choix != 0);


}

void afficherCatalogue() {

    printf("\n===== Catalogue des produits =====\n");
    for (int i = 0; i <MAX_PRODUITS; i++){
        printf("%d. %s - %.2f MAD - Stock: %d\n", catalog[i].idProduit, catalog[i].nom, catalog[i].prix, catalog[i].stock);
    }
}
void afficherDetailsProduit(){
    int trouve = 0;
    int id ;
    printf("entre le id dun produit");
    scanf("%d",&id);
    for (int i = 0; i < MAX_PRODUITS; i++) {
        if (catalog[i].idProduit == id) {
            trouve = 1;
            printf("\n----------- Details du produit -----------\n");
            printf("Nom               : %s\n", catalog[i].nom);
            printf("Categorie         : %s\n", catalog[i].categorie);
            printf("Prix              : %.2f MAD\n", catalog[i].prix);
            printf("Stock             : %d\n", catalog[i].stock);
            printf("Description       : %s\n", catalog[i].description);
            break;
}}
    if(trouve==0) {
        printf("Produit introuvable.\n");
}}
void RecherchNom(){
    char nomProduit[20];
printf("entre le nome de produit");
scanf("%s",&nomProduit);
int trouver=0;
for(int i=0;i<MAX_PRODUITS;i++){
 if(strscasecmp(catalog[i].nom,nomProduit)==0){
    trouver=1;
            printf("\n----------- Details du produit -----------\n");
            printf("Nom               : %s\n", catalog[i].nom);
            printf("Categorie         : %s\n", catalog[i].categorie);
            printf("Prix              : %.2f MAD\n", catalog[i].prix);
            printf("Stock             : %d\n", catalog[i].stock);
            printf("Description       : %s\n", catalog[i].description);

    }
    if(trouver==0){
    printf(" pas d produit ave");
    }
}}
void RecherchCategorie(){
    char nomCategorie[20];
printf("entre le categorie");
scanf("%s",&nomCategorie);
int trouver=0;
for(int i=0;i<MAX_PRODUITS;i++){
    if(strscasecmp(catalog[i].categorie,nomCategorie)==0){
    trouver=1;
            printf("\n----------- Details du produit -----------\n");
            printf("Nom               : %s\n", catalog[i].nom);
            printf("Categorie         : %s\n", catalog[i].categorie);
            printf("Prix              : %.2f MAD\n", catalog[i].prix);
            printf("Stock             : %d\n", catalog[i].stock);
            printf("Description       : %s\n", catalog[i].description);

    }
    if(trouver==0){
    printf(" pas d produit ave");
    }
}}



void Effectuer(){
    if (cmpClient == 0) {
 printf("Le compte n existe pas. Veuillez en creer un d abord.\n");
 } else {
     consultationProduits();


 }





}



