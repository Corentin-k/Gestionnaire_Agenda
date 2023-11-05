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
}Contact;

typedef struct  agenda{
    Contact * contact;
    Rendez_vous* rendez_vous; //correspond a
}agenda;

typedef struct  list_contact{
    Contact * contact;

}List_contact;

char *scanString();

//fonction qui regarde si le contact existe
int contactExists(List_contact *listContact);


// Fonction pour créer un nouvel contact et l'insère dans la liste listContact
void add_new_contact(List_contact *listContact);

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
