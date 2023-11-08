//
// Created by Coko on 30/10/2023.
//

#include "research.h"
#include <stdlib.h>
#include <stdio.h>
#include "timer.h"

int rechercheClassique(t_d_list* list, int val)
{
    t_d_cell* temp = list->heads[0]; // recherche classique d'un élément au niveau 0
    while (temp != NULL) // on cherche et on renvoit 0 si on a pas trouvé
    {
        if (temp->value == val) return val;
        temp = temp->next[0];
    }
    return 0; // 0 == pas trouvé valeur renvoyé == trouvé
}


int rechercheIntello(t_d_list* list,int val,int niv,t_d_cell* start,t_d_cell* save)
{

    if (start->value == val ) return val;
    if (niv == -1) return 0;
    if (niv == 0) return 0;
    if (val > start->value)
    {
        //printf("%d",start->next[niv-1]->value);

        return rechercheIntello(list,val,niv-1,start->next[niv-1],start);
    }
    else
    {
        if (start == list->heads[niv])
        {

            return rechercheIntello(list,val,niv-1,list->heads[niv-1],save);
        }
        else
        {
            t_d_cell* temp = save;
            while (temp->next[niv-1] != start) temp=temp->next[niv-1];

            return rechercheIntello(list,val,niv-1,temp,save);
            //printf("valeur de temp : %d valeur de start : %d",temp->value,start->value);
        }
    }

}

int rechercheInt(t_d_list* list, int val)
{

    return rechercheIntello(list,val,list->max_levels -1 ,list->heads[list->max_levels - 1],list->heads[list->max_levels -1]);
}

void timeSearch(){
    srand(time(NULL));
    FILE *log_file = fopen("log.txt","w");
    char format[] = "%d\t%s\t%s\n" ;

    char *time_lvl0;
    char *time_all_levels;
    for( int i=7;i<19 ;i++) {


        printf("en cours %d\n",i);


        t_d_list list = createList(i);
        displayList(&list);
        startTimer();
        for(int g=0;g<100000;g++){
            rechercheClassique(&list, g);
        }
        stopTimer();
        displayTime();
        time_lvl0 = getTimeAsString();


        startTimer();
        for(int g=0;g<100000;g++){
        rechercheInt(&list,g);}//rand() % 10001
        stopTimer();
        time_all_levels = getTimeAsString();
        displayTime();

        fprintf(log_file, format, i, time_lvl0, time_all_levels);
        free(time_lvl0);
        free(time_all_levels);
    }

    fclose(log_file);
};