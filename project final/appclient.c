#include <stdio.h>
#include <string.h>

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
    char description[101];
} Produit;

void Profil();
    void Creation();
    void AfficherProfil();
    void Modification();
void Solde(){};
    void afficherSolde(){};
    void deposerArgent(){};
void consultationProduits(){};
    void afficherDetailsProduit(){};
    void afficherCatalogue(){};

void Effectuer(){};

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
    scanf("%s", client.nom);
    printf("Entrez le prenom : ");
    scanf("%s", client.prenom);
    
    strcpy(client.email, client.nom);
    strcat(client.email, ".");
    strcat(client.email, client.prenom);
    strcat(client.email, "@gmail.com");
    sprintf(client.idClient, "%c.%c", client.prenom[0], client.nom[0]);

    cmpClient = 1;
    printf("Compte cree avec succes \n");
}
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
    char nome[50], prenome[50];
    printf("\nEntrez le nouveau nom : ");
    scanf("%s", nome);
    printf("Entrez le nouveau prenom : ");
    scanf("%s", prenome);
    printf("Profil mis a jour avec succes \n");
}
