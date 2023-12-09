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

void conversionminuscule(char* str)
{
    for (int i = 0; str[i]!='\0'; i++) {
        // si les caractères sont en majuscules, convertissez-les en minuscule en ajoutant 32 à leur valeur ASCII.
        if(str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] +32;
        }
    }
}
/////////////////////////////////////////RENDEZ-VOUS/////////////////////////////////////////

Rendez_vous createRendezVous() {
    Rendez_vous newRV = malloc(sizeof(struct rendez_vous));
    printf("\nSaisir le jour du rendez-vous :\n>>>");
    newRV->date.jour = scanInt(32);
    printf("\nSaisir le mois du rendez-vous :\n>>>");
    newRV->date.mois = scanInt(13);
    printf("\nSaisir l'annee du rendez-vous :\n>>>");
    newRV->date.annee = scanInt(100);
    printf("\nSaisir l'heure du rendez-vous :\n>>>");
    newRV->heure_rendez_vous.heure = scanInt(60);
    printf("\nSaisir les minutes du rendez-vous :\n>>>");
    newRV->heure_rendez_vous.minute = scanInt(60);
    printf("\nSaisir la duree du rendez-vous (en heure) :\n>>>");
    newRV->duree.heure = scanInt(60);
    printf("\nSaisir la duree du rendez-vous (en minute) :\n>>>");
    newRV->duree.minute = scanInt(60);
    printf("\nSaisir l'objet du rendez-vous :\n>>>");
    newRV->objet = scanString();
    printf("\nRendez-vous cree !\n");
    newRV->next = NULL;
    return newRV;
}

void addNewRendezVous(Contact *personne){
    Rendez_vous newRV = createRendezVous();

    Rendez_vous temp = personne->rendez_vous;

    // S'il n'y a pas déjà de rdv, celui créer sera direct en tête
    if (temp == NULL){
        printf("test2");
        personne->rendez_vous= newRV;
        return;}

    // Si le premier rdv est plus grand alors il prend la première place
    if(compareRendezVous(personne->rendez_vous, newRV) == 0){
        newRV->next = personne->rendez_vous;
        personne->rendez_vous = newRV;
        return;
    }

    // on parcourt la liste pour savoir où placer le rdv
    while (temp != NULL && compareRendezVous(temp->next,newRV) != 0)
        temp = temp->next;

    newRV->next = temp->next;
    temp->next = newRV;

    return;


}

int compareRendezVous(Rendez_vous rdv1, Rendez_vous rdv2) {
    // Comparaison des années
    if (rdv1 == NULL)
        return 0;
    if (rdv1->date.annee < rdv2->date.annee) {
        return 1;
    } else if (rdv1->date.annee > rdv2->date.annee) {
        return 0;
    }

    // Si les années sont les mêmes, comparer les mois
    if (rdv1->date.mois < rdv2->date.mois) {
        return 1;
    } else if (rdv1->date.mois > rdv2->date.mois) {
        return 0;
    }

    // Si les mois sont les mêmes, comparer les jours
    if (rdv1->date.jour < rdv2->date.jour) {
        return 1;
    } else if (rdv1->date.jour > rdv2->date.jour) {
        return 0;
    }

    // Si les dates sont les mêmes, comparer les heures
    if (rdv1->heure_rendez_vous.heure < rdv2->heure_rendez_vous.heure) {
        return 1;
    } else if (rdv1->heure_rendez_vous.heure > rdv2->heure_rendez_vous.heure) {
        return 0;
    }

    // Si les heures sont les mêmes, comparer les minutes
    if (rdv1->heure_rendez_vous.minute < rdv2->heure_rendez_vous.minute) {
        return 1;
    } else if (rdv1->heure_rendez_vous.minute > rdv2->heure_rendez_vous.minute) {
        return 0;
    }

    // Les rendez-vous sont identiques.
    return 2;
}





void displayRendezVous(Contact *personne)
{
    Rendez_vous temp = personne->rendez_vous;
    int conteur = 0;
    if(temp == NULL){
        printf("Ce contact ne possede pas encore de rendez-vous ! \n");
        return;
    }
    while(temp != NULL){
        conteur ++;
        printf("Rendez-vous n%d\n",conteur);
        printf("------ Objet: %s ------",temp->objet);
        printf("\n| Date : %d/%d/%d",temp->date.jour,temp->date.mois,temp->date.annee);
        printf("\n| Heure: %d:%d",temp->heure_rendez_vous.minute,temp->heure_rendez_vous.heure);
        printf("\n| Duree: %d:%d",temp->duree.heure,temp->duree.minute);
        printf("\n--------------------------\n");
        temp= temp->next;
    }
    return;
}

void deleteRendezVous(Contact *personne,int indexe){
    Rendez_vous temp = personne->rendez_vous;
    Rendez_vous prevtemp = personne->rendez_vous;
    if (indexe==0){
        personne->rendez_vous = temp->next;
        free(temp->objet);
        free(temp);
    }
    for(int i = 0; i < indexe ; i++){
        if(temp->next == NULL && i < indexe){
            printf("\n--------------------------\n");
            printf("Vous avez saisie un Rendez-vous qui n'existe pas \n");
            printf("--------------------------\n\n");

            return;
        }
        temp = temp->next;
        if(i+1 == indexe){
            prevtemp->next = temp->next;
            free(temp->objet);
            free(temp);
        }
        prevtemp = prevtemp->next;
    }
    return;
}


/////////////////////////////////////////CONTACT/////////////////////////////////////////
void addNewContact(List_contact* listContact,Contact * newContact){
    printf("Ajout du contact : %s %s\n",newContact->nom,newContact->prenom);
    if(contactExists(listContact,newContact)!=NULL){
        printf("Le contact existe deja"); return;
    }
    if (listContact->contact[0] == NULL ){
        listContact->contact[0] == newContact;
        return;
    }
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

Contact *contactExists(List_contact *listContact,Contact *contact){

    Contact *temp = listContact->contact[0];
    while (temp != NULL) {
        if (strcmp(temp->nom, contact->nom) == 0){
            return contact;}

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
Contact *createEmptyContact(){
    Contact *newContact = malloc(sizeof(Contact));

    newContact->nom = NULL;
    newContact->prenom = NULL;
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
    printf("--------------\n");

}


Contact* askContact(List_contact* listContact){
    Contact *contact = createEmptyContact();
    printf("Veuillez entrer le nom du contact :\n>>>");
    contact->nom = scanString();
    printf("\nVeuillez entrer le prenom du contact :\n>>>");
    contact->prenom = scanString();
    if(contactExists(listContact,contact)==NULL){
        printf("Le contact n'existe pas\n");
        free(contact->nom);
        free(contact->prenom);
        free(contact);
        return NULL;
    }
    return contact;
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



/////////////////////////////////////////FICHIER_SAUVEGARDE/////////////////////////////////////////


void readNamesFromFile( List_contact *listContact){
    printf("Ouverture des contact ...\n");
    FILE* file = fopen("noms2008nat_txt.txt", "r");
    if (file == NULL) {
        printf("Impossible d'ouvrir le fichier.\n");
        exit(EXIT_FAILURE);
    }
    printf("Recuperation des contact en cours ...");
    char name[50];
    char chaine[50] = ""; // Chaîne vide de taille TAILLE_MAX
    int i=0;
    while (fgets(chaine, 50, file) != NULL && i!=100) // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
    {
        chaine[strcspn(chaine, "\n")] = '\0'; //Pour retirer le \n à la fin de la chaine
        //printf("%s", chaine);
        Contact* new =createEmptyContact();
         printf("%s", chaine);
        strcpy(name, chaine);
        conversionminuscule(name);
        printf("%s", name);

        new->nom = (char*)malloc(strlen(name) + 1);
        strcpy(new->nom , name);
        new->prenom = NULL;

        addNewContacttemp(listContact, new);


        i++;
    }printf("\nRecuperation terminée !\n");



    fclose(file);
}
void saveInFile(List_contact listContact){
    printf("Ouverture du fichier Contact ou Recuperation du fichier Contact ...\n");
    FILE* file = fopen("noms.txt", "w");
    if (file == NULL) {
        printf("Impossible d'ouvrir le fichier.\n");
        exit(EXIT_FAILURE);
    }
    Contact *temp = listContact.contact[0];
    printf("Sauvegarde des contact ...");

    while (temp != NULL ) {
        fprintf(file, "%s\n", temp->nom);
        temp = temp->next[0];

    }
    fclose(file);
    printf("\nSauvegarde terminee !\n");
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////