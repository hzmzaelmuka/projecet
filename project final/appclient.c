#include <stdio.h>
#include <string.h>
#include <strings.h>
#define MAX_PRODUITS 5

typedef struct
{
    char idClient[10];
    char nom[50];
    char prenom[50];
    char email[100];
    float solde;
} Client;

Client client;
int cmpClient = 0;
int nbAchats = 0;

typedef struct
{
    int idProduit;
    char nom[50];
    char categorie[30];
    float prix;
    int stock;
    char description[100];
} Produit;

Produit catalog[MAX_PRODUITS] = {
    {4, "Sac a dos", "Accessoires", 100, 80, "Un sac a dos confortable et spacieux."},
    {1, "Ordinateur Portable", "Electronique", 500, 50, "Un ordinateur portable performant pour le travail et les jeux."},
    {2, "Smartphone", "Electronique", 300, 30, "Un smartphone moderne avec un bon appareil photo."},
    {3, "Livre", "Education", 20, 150, "Un livre intEressant pour apprendre la programmation."},
    {5, "Casque Audio", "Electronique", 100, 12, "Un casque audio de haute qualite."},
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
void trierParAlphabi();
void trierParPrix();

void EffectuerAcha();

void Statistiques();

int main()
{
    int choix;
    do
    {
        printf("\n==================== SYSTEME D ACHAT CLIENT ====================\n");
        printf("1 : Gestion du profil client\n");
        printf("2 : Gestion du solde virtuel\n");
        printf("3 : Consultation des produits\n");
        printf("4 : Effectuer un achat\n");
        printf("5 : Mes statistiques\n");
        printf("6 : Quitter l application\n");
        printf("Veuillez saisir votre choix (1-6) : ");
        scanf("%d", &choix);

        switch (choix)
        {
        case 1:
            Profil();
            break;
        case 2:
            Solde();
            break;
        case 3:
            consultationProduits();
            break;
        case 4:
            EffectuerAcha();
            break;
        case 5:
            Statistiques();
            break;
        case 6:
            printf("Merci pour votre visite. A bientot !\n");
            break;
        default:
            printf("Choix invalide !\n");
        }
    } while (choix != 6);
    return 0;
}

void Profil()
{
    int choix;
    do
    {
        printf("\n~~~~~~~~~~~~~~ Gestion du profil ~~~~~~~~~~~~~~\n");
        printf("1. Creer un compte\n");
        printf("2. Afficher le compte\n");
        printf("3. Modifier le compte\n");
        printf("0. Quitter vers l accueil\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choix);

        switch (choix)
        {
        case 1:
            if (cmpClient == 1)
            {
                printf("Le compte existe deja.\n");
            }
            else
            {
                Creation();
            }
            break;
        case 2:
            if (cmpClient == 0)
            {
                printf("Le compte n existe pas. Veuillez en creer un d abord.\n");
            }
            else
            {
                AfficherProfil();
            }
            break;
        case 3:
            if (cmpClient == 0)
            {
                printf("Le compte n existe pas. Veuillez en creer un d abord.\n");
            }
            else
            {
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

void Creation()
{
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

void emailId()
{
    int j = 0;
    char nome[50];
    for (int i = 0; client.nom[i] != '\0'; i++)
    {
        if (client.nom[i] != ' ')
        {
            nome[j++] = client.nom[i];
        }
    }
    nome[j] = '\0';

    strcpy(client.email, nome);
    strcat(client.email, ".");
    strcat(client.email, client.prenom);
    strcat(client.email, "@gmail.com");

    sprintf(client.idClient, "%c.%c", client.prenom[0], client.nom[0]);
}

void AfficherProfil()
{
    printf("\n===========================================\n");
    printf("             \\  LE PROFIL  /         \n");
    printf("===========================================\n");
    printf("Nom complet        : %s %s\n", client.prenom, client.nom);
    printf("ID Client          : %s\n", client.idClient);
    printf("Adresse e-mail     : %s\n", client.email);
    printf("Solde disponible   : %.2f DH\n", client.solde);
}

void Modification()
{
    printf("\n              LA MODIFICATION DE COMPTE       \n ");
    printf("\nEntrez le nouveau nom : ");
    scanf(" %[^\n]", client.nom);
    printf("Entrez le nouveau prenom : ");
    scanf("%s", client.prenom);
    emailId();
    printf("Profil mis a jour avec succes \n");
}

void Solde()
{
    int choix;
    if (cmpClient == 0)
    {
        printf("Veuillez creer un compte d abord.\n");
    }
    else
    {
        do
        {
            printf("_____________________________________________________________");
            printf("\n===  GESTION DU SOLDE VIRTUEL ===\n");
            printf("1. Consulter le solde\n");
            printf("2. Deposer de l argent\n");
            printf("0. Fermez cette page \n");
            printf("Votre choix : ");
            scanf("%d", &choix);

            switch (choix)
            {
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

void afficherSolde()
{
    printf("\n Votre solde actuel est : %.2f DH\n", client.solde);
}

void deposerArgent()
{
    float montant;
    printf("\n  Entrez le montant a deposer : ");
    scanf("%f", &montant);

    if (montant <= 0)
    {
        printf(" Montant invalide ! Il doit être superieur a 0.\n");
    }
    else
    {
        client.solde += montant;
        printf(" %.2f DH ont ete deposes avec succes !\n", montant);
        afficherSolde();
    }
}

void consultationProduits()
{
    int choix;
    afficherCatalogue();
    do
    {

        printf("________________________________________________________________\n");
        printf(" 1 : Details d'un produit\n");
        printf(" 2 : Recherche un produit par nom\n");
        printf(" 3 : Recherche un produit par categorie\n");
        printf(" 4 : Tri des produits par alphabet\n");
        printf(" 5 : Tri des produits par prix\n");
        printf(" 6 : Retour au menu principal\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choix);

        switch (choix)
        {
        case 1:
            afficherDetailsProduit();
            break;
        case 2:
            RecherchNom();
            break;
        case 3:
            RecherchCategorie();
            break;
        case 4:
            trierParAlphabi();
            break;
        case 5:
            trierParPrix();
            break;
        case 6:
            printf("Retour au menu principal.\n");
            break;
        default:
            printf("Choix invalide.\n");
        }
    } while (choix != 6);
}

void afficherCatalogue()
{
    printf("\n========= Catalogue des produits ==========\n");
    for (int i = 0; i < MAX_PRODUITS; i++)
    {
        printf("Id :%d. %s - %.2f DH - Stock: %d\n", catalog[i].idProduit, catalog[i].nom, catalog[i].prix, catalog[i].stock);
    }
}

void afficherDetailsProduit()
{
    int trouve = 0;
    int id;
    printf("Entrez l id du produit : ");
    scanf("%d", &id);

    for (int i = 0; i < MAX_PRODUITS; i++)
    {
        if (catalog[i].idProduit == id)
        {
            trouve = 1;
            printf("\n----------- Details du produit -----------\n");
            printf("Nom        : %s\n", catalog[i].nom);
            printf("Categorie  : %s\n", catalog[i].categorie);
            printf("Prix       : %.2f DH\n", catalog[i].prix);
            printf("Stock      : %d\n", catalog[i].stock);
            printf("Description: %s\n", catalog[i].description);
            break;
        }
    }
    if (trouve == 0)
    {
        printf("Produit introuvable.\n");
    }
}

void RecherchNom()
{
    char nomProduit[50];
    printf("Entrez le nom du produit : ");
    scanf("%s", nomProduit);
    int len = strlen(nomProduit);
    int trouver = 0;
    for (int i = 0; i < MAX_PRODUITS; i++)
    {
        if (strncasecmp(catalog[i].nom, nomProduit, len) == 0)
        {
            trouver = 1;
            printf("\n----------- Details du produit -----------\n");
            printf("Nom        : %s\n", catalog[i].nom);
            printf("Categorie  : %s\n", catalog[i].categorie);
            printf("Prix       : %.2f DH\n", catalog[i].prix);
            printf("Stock      : %d\n", catalog[i].stock);
            printf("Description: %s\n", catalog[i].description);
        }
    }
    if (trouver == 0)
    {
        printf("Aucun produit avec ce nom.\n");
    }
}

void RecherchCategorie()
{
    char nomCategorie[50];
    printf("Entrez la categorie : ");
    scanf("%s", nomCategorie);
    int len = strlen(nomCategorie);

    int trouver = 0;
    for (int i = 0; i < MAX_PRODUITS; i++)
    {
        if (strncasecmp(catalog[i].categorie, nomCategorie, len) == 0)
        {
            trouver = 1;
            printf("\n----------- Details du produit -----------\n");
            printf("Nom        : %s\n", catalog[i].nom);
            printf("Categorie  : %s\n", catalog[i].categorie);
            printf("Prix       : %.2f DH\n", catalog[i].prix);
            printf("Stock      : %d\n", catalog[i].stock);
            printf("Description: %s\n", catalog[i].description);
        }
    }
    if (trouver == 0)
    {
        printf("Aucun produit dans cette categorie.\n");
    }
}

void trierParAlphabi()
{
    Produit temp;
    for (int i = 0; i < MAX_PRODUITS - 1; i++)
    {
        for (int j = i + 1; j < MAX_PRODUITS; j++)
        {
            if (strcasecmp(catalog[i].nom, catalog[j].nom) > 0)
            {
                temp = catalog[i];
                catalog[i] = catalog[j];
                catalog[j] = temp;
            }
        }
    }
    printf("\nCatalogue trie par ordre alphabetique (nom):\n");
    afficherCatalogue();
}

void trierParPrix()
{
    Produit temp;
    for (int i = 0; i < MAX_PRODUITS - 1; i++)
    {
        for (int j = i + 1; j < MAX_PRODUITS; j++)
        {
            if (catalog[i].prix < catalog[j].prix)
            {
                temp = catalog[i];
                catalog[i] = catalog[j];
                catalog[j] = temp;
            }
        }
    }
    printf("\nCatalogue trie par prix croissant:\n");
    afficherCatalogue();
}

void EffectuerAcha()
{
    if (cmpClient == 0)
    {
        printf("Le compte client n existe pas. Veuillez en creer un d abord.\n");
        return;
    }

    int idProduit, trouve = 0;
    int confrm;

    afficherCatalogue();
    printf("\nEntrez l id du produit que vous souhaitez acheter : ");
    scanf("%d", &idProduit);

    for (int i = 0; i < MAX_PRODUITS; i++)
    {
        if (catalog[i].idProduit == idProduit)
        {
            trouve = 1;
            if (catalog[i].stock <= 0)
            {
                printf("Ce produit est en rupture de stock.\n");
                return;
            }
            if (client.solde < catalog[i].prix)
            {
                printf("Solde insuffisant pour acheter ce produit.\n");
                printf("Votre solde : %.2f DH" , client.solde);
                return;
            }
            printf("Voulez-vous vraiment acheter le %s   : \n", catalog[i].nom);
            printf("1 :oui\n");
            printf("2 :no\n");
            scanf(" %d", &confrm);

            if (confrm == 1)
            {
                catalog[i].stock--;
                client.solde -= catalog[i].prix;
                nbAchats++;

                printf("Achat de %s effectue avec succes pour %.2f DH !\n", catalog[i].nom, catalog[i].prix);
                printf("Nouveau solde : %.2f DH\n", client.solde);
            }
            else
            {
                printf("Achat annule.\n");
            }
            return;
        }
    }

    if (trouve == 0)
    {
        printf("Aucun produit ne correspond a l id saisi.\n");
    }
}

void Statistiques()
{
    if (cmpClient == 0)
    {
        printf("Le compte n existe pas. Veuillez en creer un d abord.\n");
        return;
    }

    printf("\n===== STATISTIQUES DU CLIENT =====\n");
    printf("Nombre total d achats effectues : %d\n", nbAchats);
    printf("Solde actuel : %.2f DH\n", client.solde);
}
