//
// Created by Bastien Peltier on 23/10/2023.
//

#include "fichier.h"
#include <stdlib.h>
#include <stdio.h>
#include<math.h>


///<summary>
///Créer une cellule : on donne sa valeur et le nombre de niveaux que possède cette
///cellule, pour obtenir un pointeur vers cette cellule
///</summary>
///<param name="value">Valeur de la cellule</param>
///<param name="nb_levels">Nombre de niveaux de la cellule</param>
///<returns>Pointeur vers la cellule</returns>
t_d_cell *createEmptyCell(int value, int nb_levels) {


    t_d_cell *cell = malloc(sizeof(t_d_cell));

    cell->value = value;
    cell->level = nb_levels;
    cell->next = (t_d_cell **)malloc(nb_levels * sizeof(t_d_cell *)); //tableau dynamique de nb_level pointeurs.vers des cellules

    for (int i = 0; i < nb_levels; i++) { //initialisation des pointeurs à NULL
        cell->next[i] = NULL;
    }

    return cell;
}

///<summary>
///Créer une liste : on donne le nombre de niveaux que possède cette liste, pour obtenir un pointeur vers cette liste
///</summary>
///<param name="max_levels">Nombre de niveaux de la liste</param>
///<returns>Pointeur vers la liste</returns>
t_d_list *createEmptyList(int max_levels) {
    t_d_list *list = malloc(sizeof(t_d_list));
    list->max_levels = max_levels;
    list->heads = (t_d_cell **)malloc(max_levels * sizeof(t_d_cell *));

    for (int i = 0; i < max_levels; i++)  { //initialisation des head à NULL
        list->heads[i] = NULL;
    }
    return list;
}

///<summary>
/// Affiche une cellule en affichant sa valeur
///</summary>
///<param name="cell">Cellule que l'on veut afficher</param>
///<returns>void</returns>
void displayCell(t_d_cell *cell) {
    if (cell == NULL) { //Si la cellule est NULL, on ne fait rien
        printf("NULL");
        return;
    }

    printf("--->[ %d|@-]", cell->value);
}

///<summary>
/// Affiche une liste en affichant les cellules de chaque niveau en les alignant
///</summary>
///<param name="list">Liste que l'on veut afficher</param>
///<returns>void</returns>
void displayList(t_d_list *list) {

    t_d_cell * temp, *prev;
    for (int i = 0; i <list->max_levels; i++){  // on parcourt les niveaux de la liste
        temp = list->heads[i];                  // pointeur vers la cellule à afficher
        prev = list->heads[0];                  // pointeur vers la cellule précédente
        printf("[list head_%d @-]", i);
        while (prev != NULL){
            if (temp!=prev || temp==NULL) {

                ////////////////////////////////Calcul de la taille de la cellule
                int val = prev->value;
                int size = 0;
                if (val < 0) {
                    size ++;
                }
                do {
                    size++;
                    val /= 10;
                } while (val != 0);
                ////////////////////////////////

                ////////////////////////////////Ajout du bon nombre de tirer si il y a un écart entre les cellules
                for (int j = 0; j < size+10; j++) { //+10 car on affiche 10 caractères pour chaque cellule [ valeur |@-]
                    printf("-");
                }
                ////////////////////////////////

            } else {
                displayCell( temp);
                temp = temp->next[i];
            }
            prev = prev->next[0];

        }
        printf("--->NULL\n");
    }

}



///<summary>
/// Ajoute une cellule dans une liste en la triant par ordre croissant a partir du niveau head[0]
///</summary>
///<param name="list">Liste dans laquelle on veut ajouter la cellule</param>
///<param name="cell">Cellule que l'on veut ajouter dans la liste</param>
///<returns>void</returns>

void addCellInList(t_d_list *list, t_d_cell *cell)
{
    if ( cell->level > list->max_levels) {
        return; // on stop l'erreur niv de cellule au dessus du max level liste
    }
    for (int x = 0; x < cell->level ; x++)
    {

        t_d_cell* temp = list->heads[x];
        t_d_cell *prev = NULL; // pointeur vers la cellule precedente
        while (temp != NULL && temp->value < cell->value) {
            // on cherche la position d'insertion de la cellule dans la liste au niveaud head[x]
            // on s'arrete quand on trouve une valeur plus grande que celle de la cellule a inserer
            // ou quand on arrive a la fin de la liste (temp == NULL)
            prev = temp;
            temp = temp->next[x];
        }
        if (prev == NULL) {   // cas ou on insère au debut de la liste de niveaux
            cell->next[x] = list->heads[x];
            list->heads[x] = cell;
        }
        else { //Sinon on insere apres prev

            cell->next[x] = temp;
            prev->next[x] = cell;
        }
    }
}




///<summary>
///Ajoute une cellule dans une liste en la triant par ordre croissant
///</summary>
///<param name="n">niveau de la liste</param>
///<returns>void</returns>
t_d_list*  createListTrie(int n){
    t_d_list* list = createEmptyList(n);
    ajoutreCursifList(list, pow(2,n)/2,n,n-1);
    return list;
}

void ajoutreCursifList(t_d_list* list, int val, int niv,int puiss)
{// le principe est d'ajouter du niveau le plus profond et de remonter comme un arbre avec ses voisins
    if (niv==0) return; // condition d'arrêt
    addCellInList(list,createEmptyCell(val,niv));

    ajoutreCursifList(list,val+ pow(2,puiss-1),niv-1,puiss-1);
    ajoutreCursifList(list,val- pow(2,puiss-1),niv-1,puiss-1);
}

///<summary>
///Créer une liste : de 2^n cellules
///</summary>
///<param name="n">niveau de la liste</param>
///<returns>void</returns>
t_d_list createList(int n) {
    int nbCell, niveau;
    t_d_list* listniv;
    t_d_cell *newcell;
    listniv = createEmptyList(n);

    nbCell = (int) pow(2, n) - 1;

    for (int i = 0; i < nbCell; i++) {
        niveau = 0;

        for (int j = 0; j < n; j++) {
            if ((i + 1)%(int) pow(2, j) == 0) {
                niveau++;
            }
        }

        newcell = createEmptyCell((i + 1), niveau);
        addCellInList(listniv, newcell);
    }
    return *listniv;
}

