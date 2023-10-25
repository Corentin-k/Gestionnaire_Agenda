#include <stdio.h>
#include "fichier.h"
int main() {


    t_d_list *list = create_d_list(5); // Crée une liste à niveaux avec une hauteur maximale de 5 niveaux
    t_d_cell* test = create_d_cell(4,2);
    t_d_cell* test1 = create_d_cell(2,2);
    t_d_cell* test2 = create_d_cell(6,3);
    t_d_cell* test3 = create_d_cell(14,5);
    add_cell_in_list(list,test3);
    add_cell_in_list(list,test);
    add_cell_in_list(list,test1);
    add_cell_in_list(list,test2);


    displayList(list);


    displaynivList(list,2);
    return 0;
}
