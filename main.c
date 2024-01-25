#include <stdio.h>
#include "fichier.h"
#include "research.h"
#include "contact.h"



//Fonction pour afficher le menu
void displayMenu(List_contact *listContact){
    int choice;

    do {
        printf("-----------------------------------------------------------------\n");
        printf("|                       Menu:                                   |\n");
        printf("|             1. Creer un nouveau contact                       |\n");
        printf("|             2. Ajouter un rendez-vous                         |\n");
        printf("|             3. Supprimer un rendez-vous                       |\n");
        printf("|             4. Rechercher un contact                          |\n");
        printf("|             5. Afficher les rendez-vous d'un contact          |\n");
        printf("|             6. display tout les contacts listes 0 for now     |\n");
        printf("|             7. Saugarder tous les contacts                    |\n");
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
                new= askContact(listContact);
                if (new==NULL){
                    printf("le contact n'existe pas");
                    break;
                }
                addNewRendezVous(new);
                break;
            case 3:
                new= askContact(listContact);
                if (new==NULL){
                    printf("le contact n'existe pas");
                    break;
                }
                int x;
                printf("quel rendez vous voulez vous supprimer ?\n");
                x=scanInt(0);
                deleteRendezVous(new,x-1);
                break;
            case 4:
                new=askContact(listContact);
                if (new==NULL){
                    printf("le contact n'existe pas");
                    break;
                }
                displayContact(*new);
                break;
            case 5:
                new=askContact(listContact);
                if (new==NULL){
                    printf("le contact n'existe pas");
                    break;
                }
                displayRendezVous(new);
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
            case 7:

                printf("Sauvegarde en cours...\n");
                saveInFile( *listContact);
                break;
            case 0:
                printf("Sauvegarde en cours...\n");
                saveInFile( *listContact);
                printf("\nAu revoir !\n");
                break;
            default:
                printf("Choix non valide. Veuillez reessayer.\n");
        }

    } while (choice != 0);
}

//Fonction d'exemple pour tester l'alignement des cellules
void testlistAligne(){
    t_d_list *list = createEmptyList(5);

    t_d_cell *cell1 = createCell(10, 3);
    addCellInList(list, cell1);
    t_d_cell *cell2 = createCell(200, 2);
    t_d_cell *cell3 = createCell(150, 4);
    t_d_cell *cell4 = createCell(300, 4);
    t_d_cell *cell5 = createCell(1, 5);
    t_d_cell *cell6 = createCell(-1101, 5);
    t_d_cell *cell7 = createCell(101, 5);
    addCellInList(list, cell7);
    addCellInList(list, cell2);
    addCellInList(list, cell3);
    addCellInList(list, cell4);
    addCellInList(list, cell5);
    addCellInList(list, cell6);
    // Afficher le contenu de la liste
    displayList(list);
}

//Fonction d'exemple pour tester le tri des cellules
void testTrie(){
    t_d_list *list = createEmptyList(5);

    t_d_cell *cell1 = createCell(rand() % 201 -100
            , 3);
    addCellInList(list, cell1);
    t_d_cell *cell2 = createCell(rand() % 201 -100
            , 2);
    t_d_cell *cell3 = createCell(rand() % 201 -100
            , 4);
    t_d_cell *cell4 = createCell(rand() %201 -100
            , 4);
    t_d_cell *cell5 = createCell(rand() % 201 -100, 5);
    t_d_cell *cell6 = createCell(rand() % 201 -100, 5);
    t_d_cell *cell7 = createCell(rand() % 201 -100, 5);
    addCellInList(list, cell7);
    printf("Ajout de la valeur %d\n", cell1->value);
    displayList(list);
    addCellInList(list, cell2);
    printf("Ajout de la valeur %d\n", cell2->value);
    displayList(list);
    addCellInList(list, cell3);
    printf("Ajout de la valeur %d\n", cell3->value);
    displayList(list);
    addCellInList(list, cell4);
    printf("Ajout de la valeur %d\n", cell4->value);
    displayList(list);
    addCellInList(list, cell5);
    printf("Ajout de la valeur %d\n", cell5->value);
    displayList(list);
    addCellInList(list, cell6);
    printf("Ajout de la valeur %d\n", cell6->value);
    // Afficher le contenu de la liste
    displayList(list);
}


int main() {
    testlistAligne();
    testTrie();
//    timeSearch();

    List_contact *listContact = createListContact();  // Création de la liste de contact
    /// Attention : Pour faire des tests on ne récupère que les 100 premiers retirer l'indice i dans la fonction pour récuperer tout les contacts
    readNamesFromFile(listContact);                   // Lecture des noms dans le fichier et ajout dans la liste

    displayMenu(listContact);                         // Affichage du menu


    return 0;
}

