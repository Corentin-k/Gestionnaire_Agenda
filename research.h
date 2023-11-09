//
// Created by Coko on 30/10/2023.
//

#ifndef GESTIONNAIRE_AGENDA_RESEARCH_H
#define GESTIONNAIRE_AGENDA_RESEARCH_H

#include "fichier.h"
#include "timer.h"
#include <stdlib.h>
#include <stdio.h>


//Fonction de recherche classique qui cherche uniquement la valeur dans le niveau head[0]
int rechercheClassique(t_d_list* list, int val);


//Fonction de recherche intelligente qui cherche la valeur dans tous les niveaux
//en partant du niveaux le plus bas et en remontant jusqu'au niveau 0
int rechercheIntEllo(t_d_list* list,int val,int niv,t_d_cell* start,t_d_cell* save);


// Fonction qui appelle la fonction de recherche intelligente en lui donnant les paramètres nécessaires
int rechercheInt(t_d_list* list, int val);

// Fonction qui teste les temps de recherche pour des listes de taille 2^7 à 2^18 et les écrit dans un fichier log.txt
// En utilisant les deux types de recherche (classique et intelligente)
void timeSearch();
void timeSearch2();


#endif //GESTIONNAIRE_AGENDA_RESEARCH_H
