
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CMAX 50
#define MAX_ADHERENTS 100
#define MAX_LIVRES 100

typedef struct SAdherent {
    int adh_Index;
    char adh_Nom[CMAX];
    int adh_NbEmprunts;
} Adherent;

typedef struct SLivre {
    int liv_Index;
    char liv_Titre[CMAX];
    char liv_Auteur[CMAX];
    int liv_Emprunteur;
} Livre;



void ajouter_adherents(Adherent adherents[], int *p_nbAdherents) {
    int nbNouveauxAdherents;
    printf("Combien d'adherents voulez-vous ajouter ?  :  ");
    scanf("%d", &nbNouveauxAdherents);
    getchar(); // consomme le caract�re '\n' laiss� dans le buffer par scanf()
  Adherent nouvelAdherent;
    for (int i = 0; i < nbNouveauxAdherents; i++) {


        printf("entrez les information des adherent");
        printf("le nom : ");
        scanf("%s", nouvelAdherent.adh_Nom);
        printf("le nombre de emprunt : ");
        scanf("%d",&nouvelAdherent.adh_NbEmprunts);

         nouvelAdherent.adh_Index = (*p_nbAdherents) + 1; // l'index de l'adhérent sera le nombre d'adhérents + 1
        adherents[*p_nbAdherents] = nouvelAdherent;
        (*p_nbAdherents)++; // l'index de l'adh�rent sera le nombre d'adh�rents + 1
    }
                         // afficher le tableau d'adh�rents pour v�rification
        printf("\nTableau des adherents :\n");
        for (int i = 0; i < *p_nbAdherents; i++) {
        printf("Adherent %d : index=%d, nom=%s, nbEmprunts=%d\n", i+1, adherents[i].adh_Index,adherents[i].adh_Nom, adherents[i].adh_NbEmprunts);
                                                 }
    printf("%d adherent(s) ajoute(s) avec succes !\n", nbNouveauxAdherents);
}

void modifier_adherent(Adherent adherents[], int nb_adherents) {
    int index;

    printf("Entrez l'index de l'adherent a modifier : ");
    scanf("%d", &index);

    // Recherche de l'adh�rent � modifier
    int i;
    for (i = 0; i < nb_adherents; i++) {
        if (adherents[i].adh_Index == index) {
            // Adh�rent trouv�, modification des informations
            printf("Nom : ");
            scanf("%s", adherents[i].adh_Nom);
            printf("Nombre d'emprunts : ");
            scanf("%d", &adherents[i].adh_NbEmprunts);
            printf("Adh�rent modifie avec succes.\n");
            return;
        }
    }

    // Si l'adh�rent n'a pas �t� trouv�, afficher un message d'erreur
    printf("Aucun adherent trouve avec l'index %d.\n", index);
}

void supprimer_adherent(Adherent adherents[], int *nb_adherents) {
    int index_a_supprimer;
    afficher_adherents(adherents, *nb_adherents); // afficher la liste des adh�rents pour que l'utilisateur choisisse l'adh�rent � supprimer
    printf("Entrez l'index de l'adherent a supprimer : ");
    scanf("%d", &index_a_supprimer);

    // rechercher l'index de l'adherent a supprimer
    int index_adherent = -1;
    for (int i = 0; i < *nb_adherents; i++) {
        if (adherents[i].adh_Index == index_a_supprimer) {
            index_adherent = i;
            break;
        }
    }

    // si l'index de l'adh�rent a supprimer est trouv�, supprimer l'adh�rent en d�calant les elements suivants
    if (index_adherent != -1) {
        for (int i = index_adherent; i < *nb_adherents - 1; i++) {
            adherents[i] = adherents[i+1];
        }
        (*nb_adherents)--;
        printf("L'adherent a ete supprime avec succes.\n");
    } else {
        printf("L'adherent n'a pas ete trouve.\n");
    }
}

void afficher_adherents(Adherent adherents[], int nbAdherents) {
    // Tri du tableau des adh�rents par ordre alphab�tique
    for (int i = 0; i < nbAdherents - 1; i++) {
        for (int j = i + 1; j < nbAdherents; j++) {
            if (strcmp(adherents[i].adh_Nom, adherents[j].adh_Nom) > 0) {
                Adherent temp = adherents[i];
                adherents[i] = adherents[j];
                adherents[j] = temp;
            }
        }
    }

    // Affichage des adh�rents tri�s
    printf("Liste des adherents par ordre alphabetique :\n");
    for (int i = 0; i < nbAdherents; i++) {
        printf("Index  : %d | Nom : %s | Nombre d'emprunts : %d\n", adherents[i].adh_Index, adherents[i].adh_Nom, adherents[i].adh_NbEmprunts);
    }
}
void modifier_livre(Livre livres[], int nbLivres) {
    int index;
    printf("Entrez l'index du livre a modifier : ");
    scanf("%d", &index);

    int i;
    for (i = 0; i < nbLivres; i++) {
        if (livres[i].liv_Index == index) {
            printf("Titre actuel : %s\n", livres[i].liv_Titre);
            printf("Entrez le nouveau titre (max %d caracteres) : ", CMAX);
            scanf(" %[^\n]", livres[i].liv_Titre);

            printf("Auteur actuel : %s\n", livres[i].liv_Auteur);
            printf("Entrez le nouvel auteur (max %d caracteres) : ", CMAX);
            scanf(" %[^\n]", livres[i].liv_Auteur);

            printf("Modification effectu�e.\n");
            return;
        }
    }

    printf("Aucun livre trouve avec l'index %d.\n", index);
}

void supprimer_livre(Livre livres[], int *nb_livres) {
    int index_livre;

    // Demander l'index du livre � supprimer
    printf("Entrez l'index du livre a supprimer : ");
    scanf("%d", &index_livre);

    // Rechercher le livre dans le tableau
    int index = -1;
    for (int i = 0; i < *nb_livres; i++) {
        if (livres[i].liv_Index == index_livre) {
            index = i;
            break;
        }
    }

    // Si le livre a �t� trouv�, le supprimer
    if (index >= 0) {
        // D�caler les livres suivants vers la gauche pour combler le trou
        for (int i = index; i < *nb_livres - 1; i++) {
            livres[i] = livres[i + 1];
        }
        // D�cr�menter le nombre de livres pr�sents dans le tableau
        (*nb_livres)--;
        printf("Livre supprime avec succes !\n");
    } else {
        printf("Livre non trouve.\n");
    }
}
void trier_livres_par_titre(Livre *bibliotheque, int nbLivres) {
    Livre tmp;
    int i, j;
    for (i = 0; i < nbLivres - 1; i++) {
        for (j = i + 1; j < nbLivres; j++) {
            if(strcmp(bibliotheque[i].liv_Titre, bibliotheque[j].liv_Titre) > 0) {
                tmp = bibliotheque[i];
                bibliotheque[i] = bibliotheque[j];
                bibliotheque[j] = tmp;
            }
        }
    }
}

void afficher_livres(Livre livres[], int nbLivres) {
    // Tri des livres par ordre alphab�tique du titre
    trier_livres_par_titre(livres, nbLivres);

    printf("Liste des livres :\n");
    printf("Index\tTitre\t\t\tAuteur\t\t\tEmprunteur\n");

    for (int i = 0; i < nbLivres; i++) {
        Livre livre = livres[i];
        printf("%d\t%s\t\t\t%s\t\t\t", livre.liv_Index, livre.liv_Titre, livre.liv_Auteur);

        if (livre.liv_Emprunteur == -1) {
            printf("disponible\n");
        } else {
            printf("%d\n", livre.liv_Emprunteur);
        }
    }
}

void emprunter_livre(Livre *livres, int nb_livres, Adherent *adherents, int nb_adherents) {
    int id_livre, id_adherent;
    int livre_trouve = 0, adherent_trouve = 0;

    // Saisie de l'ID du livre � emprunter
    do {
        printf("Veuillez saisir l'Index du livre a emprunter : ");
        scanf("%d", &id_livre);

        for (int i = 0; i < nb_livres; i++) {
            if (livres[i].liv_Index== id_livre) {
                livre_trouve = 1;
                // V�rification que le livre n'est pas d�j� emprunt�
                if (livres[i].liv_Emprunteur == 1) {
                    printf("Le livre est deje emprunte.\n");
                    livre_trouve = 0;
                    break;
                }
                break;
            }
        }
        if (!livre_trouve) {
            printf("L'Index du livre est incorrect ou le livre est introuvable.\n");
        }
    } while (!livre_trouve);

    // Saisie de l'ID de l'adh�rent emprunteur
    do {
        printf("Veuillez saisir l'Index de l'adherent emprunteur : ");
        scanf("%d", &id_adherent);

        for (int i = 0; i < nb_adherents; i++) {
            if (adherents[i].adh_Index == id_adherent) {
                adherent_trouve = 1;
                break;
            }
        }
        if (!adherent_trouve) {
            printf("L'Index  de l'adh�rent est incorrect ou l'adherent est introuvable.\n");
        }
    } while (!adherent_trouve);

    // Recherche du livre dans le tableau et mise � jour de son statut d'emprunt
    for (int i = 0; i < nb_livres; i++) {
        if (livres[i].liv_Index== id_livre) {
            livres[i].liv_Emprunteur = 1;
            livres[i].liv_Index = id_adherent;
            printf("Le livre \"%s\" a bien �t� emprunt� par l'adh�rent avec l'Index %d.\n", livres[i].liv_Titre, id_adherent);
            break;
        }
    }
}

void afficher_livres_empruntes(Adherent adherents[], int nbAdherents, Livre livres[], int nbLivres) {
    printf("Livres empruntes :\n");

    // Boucle sur les livres
    for (int i = 0; i < nbLivres; i++) {
        Livre livre = livres[i];

        // V�rifie si le livre est emprunt�
        if (livre.liv_Emprunteur) {
            // Trouve l'adh�rent qui a emprunt� ce livre
            Adherent* adherent = NULL;
            for (int j = 0; j < nbAdherents; j++) {
                if (adherents[j].adh_Index== livre.liv_Emprunteur) {
                    adherent = &adherents[j];
                    break;
                }
            }

            // Affiche le livre et l'adh�rent qui l'a emprunt�
            printf("- %s (emprunte par %s )\n", livres->liv_Titre , adherents->adh_Nom );
        }
    }
}

Adherent chercher_adherent_par_id(Adherent adherents[], int nb_adherents, int id_adherent) {
    for (int i = 0; i < nb_adherents; i++) {
        if (adherents[i].adh_Index == id_adherent) {
            return adherents[i];
        }
    }
    Adherent adh_vide;
    adh_vide.adh_Index= -1; // identifiant impossible
    return adh_vide; // retourne un adh�rent vide si l'identifiant n'est pas trouv�
}
Livre* chercher_livre_par_id(Livre livres[], int nb_livres, int id_livre) {
    int i;
    for (i = 0; i < nb_livres; i++) {
        if (livres[i].liv_Index== id_livre) {
            return &livres[i];
        }
    }
    return NULL;
}
void rendreLivre(Livre livres[], int nbLivres, Adherent adherents[], int nbAdherents) {
    int i, livreIndex;
    printf("Entrez l'index du livre que vous souhaitez rendre : ");
    scanf("%d", &livreIndex);

    for (i = 0; i < nbLivres; i++) {
        if (livres[i].liv_Index == livreIndex) {
            if (livres[i].liv_Emprunteur != -1) {
                livres[i].liv_Emprunteur = -1; // Le livre est rendu en mettant l'index de l'emprunteur à -1
                printf("Le livre a été rendu avec succès.\n");
                return;
            } else {
                printf("Ce livre n'est pas actuellement emprunté.\n");
                return;
            }
        }
    }
    printf("Aucun livre trouvé avec cet index.\n");
}
void afficher_emprunteurs_livres(Livre liv[], int nb_liv, Adherent adh[], int nb_adh) {
    printf("Liste des livres empruntes :\n\n");
    for (int i = 0; i < nb_liv; i++) {
        if (liv[i].liv_Emprunteur != NULL) {
            printf("- Titre : %s\n", liv[i].liv_Titre);
            printf("  Auteur : %s\n", liv[i].liv_Auteur);
            printf("  Emprunt� par :\n");
            printf("    - Index: %d\n", liv[i].liv_Emprunteur);
            printf("    - Nom : %s\n", liv[i].liv_Emprunteur);
            printf("\n");
        }
    }
}

int main() {

    Adherent adherents[MAX_ADHERENTS];
    Livre livres[MAX_LIVRES];
    int nb_adherents = 0, nb_livres = 0;
    FILE *fichierAdherents = fopen("adherents.txt", "w");
FILE *fichierLivres = fopen("livres.txt", "w");

if (fichierAdherents == NULL || fichierLivres == NULL) {
    printf("Erreur lors de l'ouverture des fichiers.\n");
    return 1;
}

for (int i = 0; i < nb_adherents; i++) {
    fprintf(fichierAdherents, "%d %s %d\n", adherents[i].adh_Index, adherents[i].adh_Nom, adherents[i].adh_NbEmprunts);
}

for (int i = 0; i < nb_livres; i++) {
    fprintf(fichierLivres, "%d %s %s %d\n", livres[i].liv_Index, livres[i].liv_Titre, livres[i].liv_Auteur, livres[i].liv_Emprunteur);
}

fclose(fichierAdherents);
fclose(fichierLivres);
    int choix_menu_principal, choix_menu_adherent, choix_menu_livre,choix_menu_enprunt;
    do {
        printf("\n--- MENU PRINCIPAL ---\n");
        printf("1. Gestion des adherents\n");
        printf("2. Gestion des livres\n");
        printf("3. Gestion des emprunts\n");
        printf("4. Quitter\n");
        printf("Choix : ");
        scanf("%d", &choix_menu_principal);

        switch (choix_menu_principal) {
            case 1:
                do {
                    printf("\n--- GESTION DES ADHERENTS ---\n");
                    printf("1. Ajouter un adherent\n");
                    printf("2. Modifier un adherent\n");
                    printf("3. Supprimer un adherent\n");
                    printf("4. Afficher la liste des adherents par ordre alphabetique\n");
                    printf("0. Retour\n");
                    printf("Choix : ");
                    scanf("%d", &choix_menu_adherent);

                    switch (choix_menu_adherent) {
                        case 1:
                            ajouter_adherents(adherents, &nb_adherents);
                            break;
                        case 2:
                            modifier_adherent(adherents, nb_adherents);
                            break;
                        case 3:
                            supprimer_adherent(adherents, &nb_adherents);
                            break;
                        case 4:
                            afficher_adherents(adherents, nb_adherents);
                            break;


                        default:
                            printf("Choix invalide\n");
                            break;
                    }
                } while (choix_menu_adherent != 0);
                break;

            case 2:
                do {
                    printf("\n--- GESTION DES LIVRES ---\n");
                    printf("1. Ajouter un livre\n");
                    printf("2. Modifier un livre\n");
                    printf("3. Supprimer un livre\n");
                    printf("4. Afficher la liste des livres par ordre alphabetique\n");
                    printf("0. Retour\n");
                    printf("Choix : ");
                    scanf("%d", &choix_menu_livre);
                    switch(choix_menu_livre){
                      case 1:{
                                    // Ajouter un nouveau livre
                                     printf("Titre du livre : ");
                                     scanf("%s", livres[nb_livres].liv_Titre);
                                    printf("Auteur du livre : ");
                                     scanf("%s", livres[nb_livres].liv_Auteur);
                                     printf("index du livre : ");
                                     scanf("%d",&livres[nb_livres].liv_Index);
                                     printf("Index de l'emprunteur (0 si non emprunt�) : ");
                                   scanf("%d", &livres[nb_livres].liv_Emprunteur);

                                      // Augmenter le nombre de livres
                                   nb_livres++;

                              // Afficher tous les livres
                           for (int i = 0; i < nb_livres; i++) {
                                printf("Livre %d : %s (%s)", i+1, livres[i].liv_Titre, livres[i].liv_Auteur);
                                 if (livres[i].liv_Emprunteur!= 0) {
                                     printf(" (Emprunt� par l'adh�rent %d)", livres[i].liv_Emprunteur);
                                   }
                              printf("\n");
                             }

                }


                         break;
                      case 2:
                           modifier_livre(livres,nb_livres);
                         break;
                      case 3 :
                           supprimer_livre(livres,&nb_livres);
                         break;
                      case 4:
                          afficher_livres(livres,nb_livres);
                        break;
                      default :
                           printf("choix invalide\n");
                        break;
                    }

                }while(choix_menu_livre != 0);
        case 3:
            do{
                printf("\n--- GESTION DES emprunts ---\n");
                    printf("1. Emprunter un livre \n");
                    printf("2. Rendre un livre\n");
                    printf("3. Afficher la liste des livres emprunt�s\n");
                    printf("4. Afficher la liste des emprunteurs de livres\n");
                    printf("0. Retour\n");
                    printf("Choix : ");
                    scanf("%d", &choix_menu_enprunt);
                      switch(choix_menu_enprunt){
                        case 1 :
                            emprunter_livre(livres,adherents,&nb_livres, nb_adherents);
                          break;
                        case 2:
                             rendreLivre(livres,adherents,nb_livres, nb_adherents);
                           break;
                        case 3 :
                           afficher_livres_empruntes(livres,adherents,&nb_livres, nb_adherents);
                           break;
                        case 4:
                            afficher_emprunteurs_livres(livres,adherents,&nb_livres, nb_adherents);
                            break;
                        default :
                            printf("choix invalide\n");
                           break;
                      }
            }while(choix_menu_enprunt!=0);
              case 4 : {
                            printf("\t\t   ___________________________");
                            printf("\n\t\t|          merci           |");
                            printf("\n\t\t|     d'avoire choisir     |");
                            printf("\n\t\t|           notre          |");
                            printf("\n\t\t|_______bibloitique________|");
                              exit(0);
                              break;
                              }
        }
    }while(choix_menu_principal != 0);

    return 0;
}

