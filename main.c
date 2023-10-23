#include <stdio.h>
#include "fichier.h"
int main() {
    printf("Hello, test 2!\n");

    t_d_list *list = create_d_list(5); // Crée une liste à niveaux avec une hauteur maximale de 5 niveaux

    displayList(list);

    return 0;
}
