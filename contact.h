//
// Created by Coko on 05/11/2023.
//

#ifndef GESTIONNAIRE_AGENDA_CONTACT_H
#define GESTIONNAIRE_AGENDA_CONTACT_H




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
    struct Heure durée;
    char* objet;
}Rendez_vous;


typedef struct  s_contact{
    char * nom;
    char *prenom;
    struct Rendez_vous **rendez_vous;
    struct Contact *next;
}Contact;



typedef struct  list_contact{
    Contact **heads; // Tableau de pointeurs vers les têtes de chaque niveau
    int max_levels;
}List_contact;

char *scanString();

//fonction qui regarde si le contact existe
Contact *contactExists(List_contact *listContact,Contact *contact);

// Fonction pour créer un nouvel contact et l'insère dans la liste listContact
void createContact(List_contact *listContact);

void addNewContact(List_contact *listContact, Contact *newContact);

// Fonction pour créer un nouveau rendez-vous pour un contact (et insérer le contact si nécessaire)
void createRendezVous(List_contact *listContact);

// Fonction pour supprimer un rendez-vous pour un contact
void deleteAppointment(Contact *);

// Fonction pour rechercher un contact avec complétion automatique
void searchContact(const List_contact *listContact);

// Fonction pour afficher les rendez-vous d'un contact
void displayRendezVous(Contact contact);

// Fonction pour sauvegarder les rendez-vous dans un fichier
void saveInFile(List_contact listContact);


#endif //GESTIONNAIRE_AGENDA_CONTACT_H
