//
// Created by Coko on 28/11/2023.
//

#include "menu.h"

void displayMenu(List_contact *listContact) {
    int choice;

    do {
        printf("-----------------------------------------------------------------\n");
        printf("|                       Menu:                                   |\n");
        printf("|             1. Creer un nouveau contact                       |\n");
        printf("|             2. Ajouter un rendez-vous                         |\n");
        printf("|             3. Supprimer un rendez-vous                       |\n");
        printf("|             4. Rechercher un contact                          |\n");
        printf("|             5. Afficher les rendez-vous d'un contact          |\n");
        printf("|             6. display tout les contacts listes 0 for now     |\n"); //Sauvegarder dans un fichier
        printf("|             0. Quitter                                        |\n");
        printf("-----------------------------------------------------------------\n");


        do {
            printf("Entrez votre choix (0 - 6)\n>>>");
            if (scanf("%d", &choice) != 1) {
                while (getchar() != '\n');                      // Si l'entrée n'est pas un entier, on vide le tampon d'entrée
            } else if (choice < 0 || choice > 6) {
                printf("Veuillez entrer un nombre valide entre 0 et 6 :\n");// Si l'entier n'est pas dans la plage souhaitée
            }
        } while (choice < 0 || choice > 6);
        printf("\n");
        Contact* new;
        switch (choice) {
            case 1:
                new =createContact();
                addNewContacttemp(listContact,new);
                break;
            case 2:
                //createRendezVous(listContact);
                break;
            case 3:
//                deleteAppointment(listContact);
                break;
            case 4:
//                searchContact(listContact);
                break;
            case 5:

//                //displayRendezVous(*contactExists(listContact,contact));
                break;
            case 6:
                new = listContact->contact[0];
                if (new!= NULL) {
                    do {
                        displayContact(*new);
                        new = new->next[0];
                    }
                    while (new!=NULL);
                }

                break;
            case 0:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix non valide. Veuillez réessayer.\n");
        }

    } while (choice != 0);
}
