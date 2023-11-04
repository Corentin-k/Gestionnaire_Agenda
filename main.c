#include <stdio.h>
#include "fichier.h"
#include "research.h"
int main() {
    printf("Hello, test 2!\n");

    t_d_list *list = create_d_list(5);
    displayList(list);

    t_d_cell *cell1 = create_d_cell(10, 3);
    add_cell_in_list(list, cell1);
    t_d_cell *cell2 = create_d_cell(20, 2);
    t_d_cell *cell3 = create_d_cell(15, 4);
    t_d_cell *cell4 = create_d_cell(30, 4);
    t_d_cell *cell5 = create_d_cell(1, 5);
    t_d_cell *cell6 = create_d_cell(-1101, 5);
    add_cell_in_list(list, cell2);
    add_cell_in_list(list, cell3);
    add_cell_in_list(list, cell4);
    add_cell_in_list(list, cell5);
    add_cell_in_list(list, cell6);
    // Afficher le contenu de la liste
    displayList(list);

    t_d_list* list2 = createlisttrie(10);
    printf("clear");
    printf("cette valeur est dans la liste tri different :%d", rechercheint(list,20));
    timesearch();
    //printf("cette valeur est dans la liste :%d", rechercheclassique(list2,20)); printf("clear %d",list2->max_levels);




    return 0;
}
