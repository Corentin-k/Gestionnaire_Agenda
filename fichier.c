//
// Created by Bastien Peltier on 23/10/2023.
//

#include "fichier.h"
#include <stdlib.h>
#include <stdio.h>
#include<math.h>

//Créer une cellule : on donne sa valeur et le nombre de niveaux que possède cette
//cellule, pour obtenir un pointeur vers cette cellule
t_d_cell *create_d_cell(int value, int nb_levels) {


    t_d_cell *cell = malloc(sizeof(t_d_cell));

    cell->value = value;
    cell->level = nb_levels;

    cell->next = (t_d_cell **)malloc(nb_levels * sizeof(t_d_cell *)); //tableau dynamique de nb_level pointeurs.vers des cellules

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

void displayCell(t_d_cell *cell) {
    if (cell == NULL) { //Si la cellule est NULL, on ne fait rien
        printf("NULL");
        return;
    }

    printf("--->[ %d|@-]", cell->value);
}
void displayList(t_d_list *list) {
    int test=0;
    printf("\n");
    for(int i = 0; i < list->max_levels; i++) {
        printf("[list head_%d @-]", i);
        t_d_cell *temp = list->heads[i];
        t_d_cell *precedent_aficher = NULL;

        while (temp != NULL) {
            if (i!=0 ) {
                int nb_espace_requis = 0;

                // La valeur a afficher est la premiere du niveau donc on compte le nombre d'espace entre la premiere cellule du premier niveaux et la cellule que l'on veut affciher
                if (precedent_aficher== NULL) {


                    t_d_cell *temp2 = list->heads[0];
                    // on regarde donc dans head[0] quelle est la premiere cellule qui est sur le niveau i+1. i+i Car les niveaux commencent à 1 et les indices des niveaux à 0
                    while (temp2->level< i+1 && temp2!=NULL) {

                        temp2 = temp2->next[0];
                        nb_espace_requis++;
                    }
                }
                else{
                    //cherche le precdent afficher et compte le nombre d'espace entre le prochain a afficher et affiche le nombre d'espace necessaire

                    t_d_cell *temp2 = list->heads[i];

                    while (temp2 != precedent_aficher && temp2!=NULL) { // On avance jusqu'a la cellule precedemment afficher

                        temp2 = temp2->next[0];
                    }

                    while (temp2 != temp && temp2!=NULL) { // On avance jusqu'a la cellule a afficher et on compte donc le nombre d'espace entre ces deux valeurs
                        temp2 = temp2->next[0];
                        nb_espace_requis++;
                    }
                    nb_espace_requis--;
                }


                for (int g = 0; g < nb_espace_requis; g++) {

                    printf("-----------");
                }
            }
            // Affiche la cellule sur le niveau
            displayCell(temp);


            precedent_aficher=temp;
            temp=temp->next[i];
        }printf("-->NULL\n");
    }


}




void add_cell_in_list(t_d_list *list, t_d_cell *cell)
{
    if ( cell->level > list->max_levels) {
        return; // on stop la erreur niv de cellule au dessus du max level liste
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
        if (prev == NULL) {   // cas ou on insere au debut de la liste de niveau x
            cell->next[x] = list->heads[x];
            list->heads[x] = cell;
        }
        else { //Sinon on insere apres prev

            cell->next[x] = temp;
            prev->next[x] = cell;
        }
//          int compteur = 0;
//        if (temp->value > cell->value) // cas a part pour le premier élément
//        {
//            cell->next[x] = temp;
//            list->heads[x] = cell;
//            compteur++;
//        }
//        while (temp->next[x] != NULL && compteur ==0)// onva jusqu'au dernier
//        {
//            if (temp->next[x]->value >  cell->value)
//            {
//                cell->next[x] = temp->next[x];
//                temp->next[x]=cell;
//                compteur++;
//            }
//            temp = temp->next[x];
//        }
//        if (compteur==0) // cas ou c'est le dernier élément cad la tail  ( meme si on en a pas )
//        {
//            // temp s'arrete a la derniere case justement pour ce cas.
//            temp->next[x] = cell;
//        }
//        // on fait ca pour tous les niveaux.
    }
}

void add_head_in_list(t_d_list *list, t_d_cell *cell)
{
    for ( int x = 0; x < cell->level ; x++)
    {
        list->heads[x] = cell;
    }
}

void displaynivList(t_d_list* list,int niv)
{
    printf("[list head_%d @-]-->", niv);
    t_d_cell *temp = list->heads[niv];
    int test=0;
    while (temp != NULL) {
        if(niv!=0 && test==0){
            for(int j = 0; j <list->heads[niv]->level ; j++) {
                printf("----");
            }
            test=1;
        }

        displayCell(temp);
        temp = temp->next[niv];
    }
    printf("NULL\n");
}

void displaylistaligné(t_d_list * list)
{
    for(int i = 0; i < list->max_levels; i++) {
        printf("[list head_%d @-]-->", i);
        t_d_cell *temp = list->heads[i];
        int test=0;
        while (temp != NULL) {
            if(i!=0 && test==0){
                for(int j = 0; j <list->heads[i]->level ; j++) {
                    printf("----");
                }
                test=1;
            }

            displayCell(temp);
            temp = temp->next[i];
        }
        printf("NULL\n");

    }
}

t_d_list*  createlisttrie(int n){
    t_d_list* list = create_d_list(n);
    ajoutrecursiflist(list, pow(2,n)/2,n,n-1);
    return list;
}

void ajoutrecursiflist(t_d_list* list, int val, int niv,int puiss)
{// le principe est d'ajouter du niveaux le plus profond et de remonter comme un arbre avec ses voisins
    if (niv==0) return; // condition d'arrêt
    add_cell_in_list(list,create_d_cell(val,niv));
    printf("ok val : %d",val);
    ajoutrecursiflist(list,val+ pow(2,puiss-1),niv-1,puiss-1);
    ajoutrecursiflist(list,val- pow(2,puiss-1),niv-1,puiss-1);
}

int rechercheclassique(t_d_list* list, int val)
{
    t_d_cell* temp = list->heads[0]; // recherche classique d'un élément au niveau 0
    while (temp != NULL) // on cherche et on renvoit 0 si on a pas trouvé
    {
        if (temp->value == val) return val;
        temp = temp->next[0];
    }
    return 0; // 0 == pas trouvé valeur renvoyé == trouvé
}
int rechercheintello(t_d_list* list,int val,int niv,t_d_cell* start,t_d_cell* save)
{
    if (start->value == val ) return val;
    if (niv == -1) return 0;
    if (val > start->value)
    {
        //printf("%d",start->next[niv-1]->value);
        rechercheintello(list,val,niv-1,start->next[niv-1],start);
    }
    else
    {
        if (start == list->heads[niv])
        {
            rechercheintello(list,val,niv-1,list->heads[niv-1],save);
        }
        else
        {
            t_d_cell* temp = save;
            while (temp->next[niv-1] != start) temp=temp->next[niv-1];
            rechercheintello(list,val,niv-1,temp,save);
            //printf("valeur de temp : %d valeur de start : %d",temp->value,start->value);
        }
    }
}

int rechercheint(t_d_list* list, int val)
{
    return rechercheintello(list,val,list->max_levels -1 ,list->heads[list->max_levels - 1],list->heads[list->max_levels -1]);
}