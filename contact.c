//
// Created by Coko on 05/11/2023.
//

#include "contact.h"

char *scanString() {
    char texte[201];

    if (scanf("%s", texte) ==1 ) {
        // Lire au plus 199 caractères pour éviter le dépassement de tampon
        char *copie = (char *)malloc(strlen(texte) + 1);

            strcpy(copie, texte);
            return copie;

    }

}
int scanInt(int max) {
    int num;
    while (scanf("%d", &num) != 1 || num <0 || num >= max) {
        // Si la saisie n'est pas un entier, vider le tampon d'entrée
        while (getchar() != '\n');
        printf("\nVeuillez saisir un entier valide :\n>>>");
    }
    return num;
}

int sizeChar(char* str){

    int size=0;
    if (str == NULL) {
        // Gestion du cas où la chaîne est NULL
        return size;
    }else{
        while (str[size] != '\0') {
            size++;
        }
    }return size;
}



void addNewContact(List_contact* listContact,Contact * newContact){
    if(contactExists(listContact,newContact)!=NULL){
        printf("Le contact existe deja");
    }
    else{
        listContact->contact[0] = newContact;
        listContact->max_contact++;
        printf("Le contact a bien ete ajoute");
    }


}

Contact *contactExists(List_contact *listContact,Contact *contact){ //Faire une recherhche par niveau
    Contact *temp = listContact->contact[0];
    while (temp != NULL) {
        if (temp->nom == contact->nom && temp->prenom == contact->prenom)
            return contact;
        temp = temp;
    }
    return NULL;
}
List_contact *createListContact(){
    List_contact *listContact = malloc(sizeof(List_contact));
    listContact->contact = (Contact **)malloc(MAX_LEVEL * sizeof(Contact *));
    for (int i = 0; i < MAX_LEVEL; i++)  { //initialisation des head à NULL
        listContact->contact[i] = NULL;
    }
    return listContact;
}
Contact *createContact(){
    Contact *newContact = malloc(sizeof(Contact));
    printf("Saisir le nom du contact :\n>>>");
    newContact->nom = scanString();

    printf("Saisir le prenom du contact :\n>>>");
    newContact->prenom = scanString();
    newContact->rendez_vous = NULL;
    newContact->next = NULL;
    return newContact;

}

//void displayList(List_contact list) {
//
//    Contact * temp, *prev;
//    for (int i = 0; i <list.max_contact; i++){  // on parcourt les niveaux de la liste
//        temp = list.contact[i];                  // pointeur vers la cellule à afficher
//        prev = list.contact[0];                  // pointeur vers la cellule précédente
//        printf("[list head_%d @-]", i);
//        while (prev != NULL){
//            if (temp!=prev || temp==NULL) {
//
//                ////////////////////////////////Calcul de la taille de la cellule
//                int size= sizeChar(prev->nom);
//                ////////////////////////////////
//
//                ////////////////////////////////Ajout du bon nombre de tirer si il y a un écart entre les cellules
//                for (int j = 0; j < size+10; j++) { //+10 car on affiche 10 caractères pour chaque cellule [ valeur |@-]
//                    printf("-");
//                }
//                ////////////////////////////////
//
//            } else {
//
////                temp = temp->next[i];
//            }
////            prev = prev->next[0];
//
//        }
//        printf("--->NULL\n");
//    }
//
//}

void displayContact(Contact contact){

    printf("--------------\n");
    printf("|   Contact :                \n");
    printf("|   Nom : %s\n",contact.nom);
    printf("|   Prenom : %s\n",contact.prenom);
    printf("|   Rendez-vous :\n");
//    displayRendezVous(contact);
    printf("--------------\n");

}

void createRendezVous(Contact *contact){
    Rendez_vous *newRV = malloc(sizeof(Rendez_vous));
    printf("\nSaisir le jour du rendez-vous :\n>>>");
    newRV->date.jour =scanInt(32);
    printf("\nSaisir le mois du rendez-vous :\n>>>");
    newRV->date.mois =scanInt(13);
    printf("\nSaisir l'annee du rendez-vous :\n>>>");
    newRV->date.annee = scanInt(100);
    printf("\nSaisir l'heure du rendez-vous :\n>>>");
    newRV->heure_rendez_vous.heure =scanInt(60);
    printf("\nSaisir les minutes du rendez-vous :\n>>>");
    newRV->heure_rendez_vous.minute =scanInt(60);
    printf("\nSaisir la duree du rendez-vous :\n>>>");
    newRV->durée.heure =scanInt(60);
    printf("\nSaisir l'objet du rendez-vous :\n>>>");
    newRV->objet = scanString();
//    addNewRendezVous(contact,newRV);

}


void displayMenu(List_contact *listContact) {
    int choice;

    do {
        printf("-----------------------------------------------------------------\n");
        printf("|                       Menu:                                   |\n");
        printf("|             1. Creer un nouveau contact                       |\n");
        printf("|             2. Ajouter un rendez-vous                         |\n");
        printf("|             3. Supprimer un rendez-vous                       |\n");
        printf("|             4. Rechercher un contact                          |\n");
        printf("|             5. Afficher les rendez-vous d'un contact          |\n");
        printf("|             6. Sauvegarder dans un fichier                    |\n");
        printf("|             0. Quitter                                        |\n");
        printf("-----------------------------------------------------------------\n");


        do {
            printf("Entrez votre choix (0 - 8)\n>>>");
            if (scanf("%d", &choice) != 1) {
                while (getchar() != '\n');                      // Si l'entrée n'est pas un entier, on vide le tampon d'entrée
            } else if (choice < 0 || choice > 5) {
                printf("Veuillez entrer un nombre valide entre 0 et 6 :\n");// Si l'entier n'est pas dans la plage souhaitée
            }
        } while (choice < 0 || choice > 5);
        printf("\n");

        switch (choice) {
            case 1:
//                Contact *new =createContact();
//                addNewContact(listContact,*new);
                break;
            case 2:
                createRendezVous(listContact);
                break;
            case 3:
//                deleteAppointment(listContact);
                break;
            case 4:
//                searchContact(listContact);
                break;
            case 5:
                // Assuming you want to display appointments for a specific contact
//                displayRendezVous(*contactExists(listContact,contact));
                break;
            case 6:
                //sacve
                break;
            case 0:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix non valide. Veuillez réessayer.\n");
        }

    } while (choice != 0);
}