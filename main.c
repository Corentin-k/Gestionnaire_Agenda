#include <stdio.h>
#include "fichier.h"
#include "research.h"
#include "contact.h"




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

////    printf("cette valeur est dans la liste :%d", rechercheclassique(&lis,20)); printf("clear %d",lis.max_levels);
//   List_contact *listContact =createListContact();
////    //ouvrir le fichier sauvegarder si il existe etcréer la liste des contacts
//    Contact *contact=createContact();
//    createRendezVous(contact);
//    displayRendezVous(contact->rendez_vous);
//    createRendezVous(contact);
//    displayContact(*contact);
//    readNamesFromFile( listContact);
//    displayMenu(listContact);
    //timeSearch();


    List_contact *listContact = createListContact();
    readNamesFromFile(listContact);
//    readNamesFromFile( listContact);
//    displayContact(*listContact->contact[0]);
//    displayContact(*listContact->contact[1]);

    displayMenu(listContact);


//    Contact *newContact = createContact();
//    displayContact(*newContact);
//
//    // Ajouter le nouveau contact à la liste
//
//    addNewContact(listContact, newContact);
//    Contact *newContact2 = createContact();
//    displayContact(*newContact2);
//
//    // Ajouter le nouveau contact à la liste
//
//    addNewContact(listContact, newContact2);

//    displayRendezVous(newContact);
//
//    addNewRendezVous(newContact);
//
//    displayRendezVous(newContact);
//    addNewRendezVous(newContact);
//    displayRendezVous(newContact);

  //  displayRendezVous(newContact);
//    // Sauvegarder dans un fichier
//    saveInFile(*listContact);
//
//    // Lecture à partir du fichier
//    readNamesFromFile(listContact);

    return 0;
}

