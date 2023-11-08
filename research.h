//
// Created by Coko on 30/10/2023.
//

#ifndef GESTIONNAIRE_AGENDA_RESEARCH_H
#define GESTIONNAIRE_AGENDA_RESEARCH_H
#include "fichier.h"
#include "timer.h"
int rechercheClassique(t_d_list* list, int val);

int rechercheIntEllo(t_d_list* list,int val,int niv,t_d_cell* start,t_d_cell* save);

int rechercheInt(t_d_list* list, int val);
void timeSearch();
#endif //GESTIONNAIRE_AGENDA_RESEARCH_H
