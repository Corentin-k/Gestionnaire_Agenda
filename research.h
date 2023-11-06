//
// Created by Coko on 30/10/2023.
//

#ifndef GESTIONNAIRE_AGENDA_RESEARCH_H
#define GESTIONNAIRE_AGENDA_RESEARCH_H
#include "fichier.h"
#include "timer.h"
int rechercheclassique(t_d_list* list, int val);

int rechercheintello(t_d_list* list,int val,int niv,t_d_cell* start,t_d_cell* save);

int rechercheint(t_d_list* list, int val);
void timesearch();
#endif //GESTIONNAIRE_AGENDA_RESEARCH_H
