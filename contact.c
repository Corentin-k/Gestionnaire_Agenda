//
// Created by Coko on 05/11/2023.
//

#include "contact.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
char *scanString() {
    char texte[201];

    if (scanf("%s", texte) ==1 ) {
        // Lire au plus 199 caractères pour éviter le dépassement de tampon
        char *copie = (char *)malloc(strlen(texte) + 1);

            strcpy(copie, texte);
            return copie;

    }

}