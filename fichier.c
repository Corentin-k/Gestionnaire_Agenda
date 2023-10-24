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

void add_cell_in_list(t_d_list *list, t_d_cell *cell)
{
    if ( cell->level > list->max_levels) {
        return; // on stop la erreur niv de cellule au dessus du max level liste
    }
    for (int x = 0; x < cell->level ; x++)
    {
        int compteur = 0;
        t_d_cell* temp = list->heads[x];
        if (temp->value > cell->value) // cas a part pour le premier élément
        {
            cell->next[x] = temp;
            list->heads[x] = cell;
            compteur++;
        }
        while (temp->next[x] != NULL && compteur ==0)// onva jusqu'au dernier
        {
            if (temp->next[x]->value >  cell->value)
            {
                cell->next[x] = temp->next[x];
                temp->next[x]=cell;
                compteur++;
            }
            temp = temp->next[x];
        }
        if (compteur==0) // cas ou c'est le dernier élément cad la tail  ( meme si on en a pas )
        {
            // temp s'arrete a la derniere case justement pour ce cas.
            temp->next[x] = cell;
        }
        // on fait ca pour tous les niveaux.
    }
}

void add_head_in_list(t_d_list *list, t_d_cell *cell)
{
    for ( int x = 0; x < cell->level ; x++)
    {
        list->heads[x] = cell;
    }
}