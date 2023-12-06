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

Rendez_vous *createRendezVous() {
    Rendez_vous *newRV = malloc(sizeof(Rendez_vous));
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
    return newRV;
}

void addNewRendezVous(Contact *personne){
    Rendez_vous *newRV = createRendezVous();

}






void displayRendezVous(Rendez_vous*  rdv)
{
    printf("------ Objet: %s ------",rdv->objet);
    printf("\n| Date : %d/%d/%d",rdv->date.jour,rdv->date.mois,rdv->date.annee);
    printf("\n| Heure: %d:%d",rdv->heure_rendez_vous.minute,rdv->heure_rendez_vous.heure);
    printf("\n| Duree: %d:%d",rdv->duree.heure,rdv->duree.minute);
    printf("\n--------------------------\n");
}


/////////////////////////////////////////CONTACT/////////////////////////////////////////
void addNewContact(List_contact* listContact,Contact * newContact){
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
Contact *createEmptyContact(){
    Contact *newContact = malloc(sizeof(Contact));

    newContact->nom = NULL;
    conversionminuscule(newContact->nom);
    newContact->prenom = NULL;
    conversionminuscule(newContact->prenom);
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
    FILE* file = fopen("noms2008nat_txt.txt", "r");
    if (file == NULL) {
        printf("Impossible d'ouvrir le fichier.\n");
        exit(EXIT_FAILURE);
    }
    char name[50];
    char chaine[50] = ""; // Chaîne vide de taille TAILLE_MAX
    while (fgets(chaine, 50, file) != NULL) // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
    {
        printf("%s", chaine); // On affiche la chaîne qu'on vient de lire
        Contact* new =createEmptyContact();
        new->nom = chaine;
       addNewContact(listContact,new);
       printf("%s", new->nom);
    }



    fclose(file);
}
void saveInFile(List_contact listContact){
    FILE* file = fopen("noms.txt", "w");
    if (file == NULL) {
        printf("Impossible d'ouvrir le fichier.\n");
        exit(EXIT_FAILURE);
    }
    Contact *temp = listContact.contact[0];
    while (temp != NULL) {
        fprintf(file, "%s\n", temp->nom);
        temp = temp->next[0];
    }
    fclose(file);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////