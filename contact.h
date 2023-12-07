//
// Created by Coko on 05/11/2023.
//

#ifndef GESTIONNAIRE_AGENDA_CONTACT_H
#define GESTIONNAIRE_AGENDA_CONTACT_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_LEVEL 4


struct  Date{
    int jour;
    int mois;
    int annee;
};
struct Heure{
    int heure;
    int minute;
};


typedef struct  rendez_vous{
    struct Date date;
    struct Heure heure_rendez_vous;
    struct Heure duree;
    struct rendez_vous *next;
    char* objet;

}*Rendez_vous;


typedef struct  s_contact{
    char * nom;
    char * prenom;
    Rendez_vous rendez_vous;
    struct Contact **next;
}Contact;



typedef struct  list_contact{
    Contact **contact; // Tableau de pointeurs vers les têtes de chaque niveau
    int max_contact;
}List_contact;



char *scanString();
int sizeChar(char* str);
int scanInt(int);
void conversionminuscule(char* str);  // conversion en minuscule

List_contact *createListContact();

/////////////////////////CONTACT/////////////////////////////
//fonction qui regarde si le contact existe
Contact *contactExists(List_contact *listContact,Contact *contact);
// Fonction pour créer un contact vide
Contact *createEmptyContact();
// Fonction pour créer un nouvel contact et l'insère dans la liste listContact
Contact *createContact();
void addNewContact(List_contact *listContact, Contact *newContact);
void addNewContacttemp(List_contact *listContact, Contact *newContact);
void displayContact(Contact contact);
// Fonction pour rechercher un contact avec complétion automatique
void searchContact(const List_contact *listContact);

/////////////////////////RENDEZ-VOUS/////////////////////////////

// Fonction pour créer un nouveau rendez-vous pour un contact
Rendez_vous createRendezVous();

// Fonction pour mettre au bon endroit le rdv
void addNewRendezVous(Contact *personne);

// Fonction pour afficher les rendez-vous d'un contact
void displayRendezVous(Contact *personne);


// Fonction pour supprimer un rendez-vous pour un contact
void deleteRendezVous(Contact );

// Fonction pour comparer 2 rendez-vous pour savoir qui est le plus tôt
int compareRendezVous(Rendez_vous rdv1, Rendez_vous rdv2);



/////////////////////////FICHIER_SAUVEGARDE/////////////////////////////

// Fonction pour sauvegarder les rendez-vous dans un fichier
void saveInFile(List_contact listContact);

// Fonction pour lire le fichier et stocker les prénoms dans la liste
void readNamesFromFile( List_contact* listContact);

/////////////////////////////////////////////////////////////////////



#endif //GESTIONNAIRE_AGENDA_CONTACT_H
