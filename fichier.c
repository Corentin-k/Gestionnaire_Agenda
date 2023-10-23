//
// Created by Bastien Peltier on 23/10/2023.
//

#include "fichier.h"
#include <stdlib.h>
#include <stdio.h>

//Créer une cellule : on donne sa valeur et le nombre de niveaux que possède cette
//cellule, pour obtenir un pointeur vers cette cellule
t_d_cell *create_d_cell(int value, int nb_levels) {


    t_d_cell *cell = malloc(sizeof(t_d_cell));

    cell->value = value;
    cell->level = nb_levels;

    cell->next = (t_d_cell **)malloc(nb_levels * sizeof(t_d_cell *)); //tableau dynamique de nb_level pointeurs.

    for (int i = 0; i < nb_levels; i++) { //initialisation des pointeurs à NULL
        cell->next[i] = NULL;
    }
    return cell;
}



t_d_list *create_d_list(int max_levels) {
    t_d_list *list = malloc(sizeof(t_d_list));
    list->max_levels = max_levels;
    list->heads = (t_d_cell **)malloc(max_levels * sizeof(t_d_cell *));

    for (int i = 0; i < max_levels; i++)  { //initialisation des head à NULL
        list->heads[i] = NULL;
    }
    return list;
}
void insert_d_cell(t_d_list *list, t_d_cell *cell) {
    int levels_to_insert = cell->level;
    for (int i = 0; i < levels_to_insert; i++) {
        cell->next[i] = list->heads[i];
        list->heads[i] = cell;
    }
}
void displayCell(t_d_cell *cell) {
    if (cell == NULL) { //Si la premiere cellule est NULL, on ne fait rien
        return;
    }
    for(int i = 0; i < cell->level; i++) {

        printf("[ %d|@-]--> ", cell->value);
    }
}
void displayList(t_d_list *list) {

    for(int i = 0; i < list->max_levels; i++) {
        printf("[list head_%d @-]-->", i);
        displayCell(list->heads[i]);
        printf("NULL");
        printf("\n");

    }

}