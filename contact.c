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
        printf("Le contact existe deja"); return;
    }
    if (listContact->contact[0] == NULL ) listContact->contact[0] == newContact;
    int y=1; int pos_found = 0;
    for (int x = 0; x < y ; x ++) {
        Contact *temp = listContact->contact[0];
        while (temp!= NULL && pos_found != 1 )
        {
            
            temp = temp->next[x];
        }
        int compteur = 0;
    }

}

Contact *contactExists(List_contact *listContact,Contact *contact){ //Faire une recherhche par niveau
    Contact *temp = listContact->contact[0];
    while (temp != NULL) {
        if (temp->nom == contact->nom && temp->prenom == contact->prenom)
            return contact;
        temp = temp->next[0];
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
    conversionminuscule(newContact->nom);

    printf("Saisir le prenom du contact :\n>>>");
    newContact->prenom = scanString();conversionminuscule(newContact->prenom);
    newContact->rendez_vous = NULL;
    newContact->next = malloc(4*sizeof(*newContact));
    for (int x=0;x<4;x++) newContact->next[0]=NULL;
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

void    displayContact(Contact contact){

    printf("--------------\n");
    printf("|   Contact :                \n");
    printf("|   Nom : %s\n",contact.nom);
    printf("|   Prenom : %s\n",contact.prenom);
    printf("|   Rendez-vous :\n");
    Rendez_vous* temp = contact.rendez_vous;
    while (temp!=NULL)
    {
        displayRendezVous(temp);
        temp = temp->next;
    }
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
    printf("\nSaisir la duree du rendez-vous (en heure) :\n>>>");
    newRV->duree.heure =scanInt(60);
    printf("\nSaisir la duree du rendez-vous (en minute) :\n>>>");
    newRV->duree.minute =scanInt(60);
    printf("\nSaisir l'objet du rendez-vous :\n>>>");
    newRV->objet = scanString();
    //addNewRendezVous(contact,newRV);
    Rendez_vous * temp = contact->rendez_vous;
    if (temp==NULL) contact->rendez_vous = newRV;
    else {
        while (temp->next != NULL) temp = temp->next;
        temp->next = newRV;
    }



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
        printf("|             6. display tout les contacts listes 0 for now     |\n"); //Sauvegarder dans un fichier
        printf("|             0. Quitter                                        |\n");
        printf("-----------------------------------------------------------------\n");


        do {
            printf("Entrez votre choix (0 - 6)\n>>>");
            if (scanf("%d", &choice) != 1) {
                while (getchar() != '\n');                      // Si l'entrée n'est pas un entier, on vide le tampon d'entrée
            } else if (choice < 0 || choice > 6) {
                printf("Veuillez entrer un nombre valide entre 0 et 6 :\n");// Si l'entier n'est pas dans la plage souhaitée
            }
        } while (choice < 0 || choice > 6);
        printf("\n");
        Contact* new;
        switch (choice) {
            case 1:
                new =createContact();
                addNewContacttemp(listContact,new);
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

//                //displayRendezVous(*contactExists(listContact,contact));
                break;
            case 6:
                new = listContact->contact[0];
                if (new!= NULL) {
                    do {
                        displayContact(*new);
                        new = new->next[0];
                    }
                    while (new!=NULL);
                }

                break;
            case 0:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix non valide. Veuillez réessayer.\n");
        }

    } while (choice != 0);
}

void displayRendezVous(Rendez_vous*  rdv)
{
    printf("------ Objet: %s ------",rdv->objet);
    printf("\n| Date : %d/%d/%d",rdv->date.jour,rdv->date.mois,rdv->date.annee);
    printf("\n| Heure: %d:%d",rdv->heure_rendez_vous.minute,rdv->heure_rendez_vous.heure);
    printf("\n| Duree: %d:%d",rdv->duree.heure,rdv->duree.minute);

}

void addNewContacttemp(List_contact *listContact, Contact *newContact)
{
    if (listContact->contact[0]==NULL) listContact->contact[0] = newContact;
    else
    {
        Contact* temp = listContact->contact[0];
        while (temp->next[0]!= NULL) { temp =  temp->next[0];}
        temp->next[0] = newContact;
    }
}

void conversionminuscule(char* str)
{
    for (int i = 0; str[i]!='\0'; i++) {
        // si les caractères sont en majuscules, convertissez-les en minuscule en ajoutant 32 à leur valeur ASCII.
        if(str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] +32;
        }
    }
}



void readNamesFromFile( List_contact listContact){
    FILE* file = fopen("tes.txt", "r");
    if (file == NULL) {
        printf("Impossible d'ouvrir le fichier.\n");
        exit(EXIT_FAILURE);
    }
    char name[50];
    char chaine[50] = ""; // Chaîne vide de taille TAILLE_MAX
    while (fgets(chaine, 50, file) != NULL) // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
    {
        printf("%s", chaine); // On affiche la chaîne qu'on vient de lire
    }
//        Contact* new =createContact();
//       addNewContact(listContact,new)
//
       }