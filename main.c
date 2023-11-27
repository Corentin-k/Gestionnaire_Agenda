#include <stdio.h>
#include "fichier.h"
#include "research.h"
#include "contact.h"

void testlistAligne(){
    t_d_list *list = createEmptyList(5);

    t_d_cell *cell1 = createEmptyCell(10, 3);
    addCellInList(list, cell1);
    t_d_cell *cell2 = createEmptyCell(200, 2);
    t_d_cell *cell3 = createEmptyCell(150, 4);
    t_d_cell *cell4 = createEmptyCell(300, 4);
    t_d_cell *cell5 = createEmptyCell(1, 5);
    t_d_cell *cell6 = createEmptyCell(-1101, 5);
    t_d_cell *cell7 = createEmptyCell(101, 5);
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

    t_d_cell *cell1 = createEmptyCell(rand() % (100 - -100 + 1) + -100
    , 3);
    addCellInList(list, cell1);
    t_d_cell *cell2 = createEmptyCell(rand() % (100 - -100 + 1) + -100
    , 2);
    t_d_cell *cell3 = createEmptyCell(rand() % (100 - -100 + 1) + -100
    , 4);
    t_d_cell *cell4 = createEmptyCell(rand() % (100 - -100 + 1) + -100000
    , 4);
    t_d_cell *cell5 = createEmptyCell(rand() % (100 - -100 + 1) + -100, 5);
    t_d_cell *cell6 = createEmptyCell(rand() % (100 - -100 + 1) + -100, 5);
    t_d_cell *cell7 = createEmptyCell(rand() % (100 - -100 + 1) + -100, 5);
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
};

int main() {

//    t_d_list *list=createListTrie(25);
//   displayList(list);
//   t_d_list list2=createList(25);
//  displayList(&list2);
//    TestlistAligne();
//    t_d_list lis = createlist(10);
//    ddisplayList(&lis);
//    printf("clear");
//    printf("cette valeur est dans la liste tri different :%d", rechercheint(list,20));
//    timeSearch();
//   timeSearch();
////    printf("cette valeur est dans la liste :%d", rechercheclassique(&lis,20)); printf("clear %d",lis.max_levels);
   List_contact *listContact =createListContact();
//    //ouvrir le fichier sauvegarder si il existe etcréer la liste des contacts
    //Contact *contact=createContact();
    //createRendezVous(contact);
    //displayRendezVous(contact->rendez_vous);
    //createRendezVous(contact);
    //displayContact(*contact);
    readNamesFromFile( listContact);
    displayMenu(listContact);
    //timeSearch();

    return 0;
}
