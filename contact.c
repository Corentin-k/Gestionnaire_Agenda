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
void addNewContact(List_contact* listContact,Contact * newContact){
    listContact->contact[0] = newContact;
    listContact->max_contact++;
}

Contact *contactExists(List_contact *listContact,Contact *contact){
    Contact *temp = listContact->contact[0];
    while (temp != NULL) {
        if (temp->nom == contact->nom && temp->prenom == contact->prenom)
            return contact;
        temp = temp;
    }
    return NULL;
}

void createContact(List_contact *listContact){
    Contact *newContact = malloc(sizeof(Contact));
    printf("Saisir le nom du contact : ");
    newContact->nom = scanString();
    printf("Saisir le prenom du contact : ");
    newContact->prenom = scanString();
    newContact->rendez_vous = NULL;
    newContact->next = NULL;
    if(contactExists(listContact,newContact)!=NULL){
        printf("Le contact existe deja");
    }
    else{
        addNewContact(listContact,newContact);
        printf("Le contact a bien ete ajoute");
    }

}
void createRendezVous(List_contact *){
    Rendez_vous *newRV = malloc(sizeof(Rendez_vous));
    printf("Saisir le jour du rendez-vous : ");
    newRV->date.jour =0;
    printf("Saisir le mois du rendez-vous : ");
    newRV->date.mois =0;
    printf("Saisir l'annee du rendez-vous : ");
    newRV->date.annee = 0;
    printf("Saisir l'heure du rendez-vous : ");
    newRV->heure_rendez_vous.heure = 0;
    printf("Saisir les minutes du rendez-vous : ");
    newRV->heure_rendez_vous.minute =0;
    printf("Saisir la duree du rendez-vous : ");
    newRV->durée.heure =0;
    printf("Saisir l'objet du rendez-vous : ");
    newRV->objet = scanString();

}