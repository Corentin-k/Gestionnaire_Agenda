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

t_d_cell *createEmptyCell(int value, int num_levels);

t_d_list *createEmptyList(int max_levels);

t_d_list createList(int n);

void displayCell(t_d_cell *cell);
void displayList(t_d_list *list);
void addCellInList(t_d_list *list, t_d_cell *cell);


void displayNivList(t_d_list* list,int niv);
t_d_list* createListTrie(int n);
void ajoutreCursifList(t_d_list* list, int val, int niv,int puiss);

#endif //GESTIONNAIRE_AGENDA_FICHIER_H
