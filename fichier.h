//
// Created by Bastien Peltier on 23/10/2023.
//

#ifndef GESTIONNAIRE_AGENDA_FICHIER_H
#define GESTIONNAIRE_AGENDA_FICHIER_H


//Structure cellule stocke une valeur de type en entier et deux pointeurs vers deux autres cellules
typedef struct s_d_cell
{
    int value;
    int level;
    struct s_d_cell **next; // stocke un tableau de pointeurs vers des cellules/ double pointeur pour avoir acces directement en faisant cell->next[i]

} t_d_cell;

//Structure liste doublement chainée stocke deux pointeurs vers deux cellules
typedef struct s_d_list
{
    t_d_cell **heads; // Tableau de pointeurs vers les têtes de chaque niveau / double pointeur pour avoir acces directement en faisant list->heads[i]
    int max_levels; // Nombre maximal de niveaux
} t_d_list;


//Créer une cellule : on donne sa valeur et le nombre de niveaux que possède cette cellule, pour obtenir un pointeur vers cette cellule
t_d_cell *createEmptyCell(int value, int num_levels);

//Créer une liste : on donne le nombre de niveaux que possède cette liste, pour obtenir un pointeur vers cette liste
t_d_list *createEmptyList(int max_levels);

//Créer une liste : de 2^n cellules
t_d_list createList(int n);


//Affiche une cellule
void displayCell(t_d_cell *cell);

//Affiche une liste
void displayList(t_d_list *list);

//Ajoute une cellule dans une liste en la triant par ordre croissant a partir du niveau head[0]
void addCellInList(t_d_list *list, t_d_cell *cell);


void displayNivList(t_d_list* list,int niv);

//Ajoute une cellule dans une liste en la triant par ordre croissant
t_d_list* createListTrie(int n);

//Ajoute une cellule dans une liste en la triant par ordre croissant
void ajoutreCursifList(t_d_list* list, int val, int niv,int puiss);

#endif //GESTIONNAIRE_AGENDA_FICHIER_H
