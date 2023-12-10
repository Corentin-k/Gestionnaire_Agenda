# Projet-L2-Algorithme et structure de données 2 

Par

- [Corentin-K](https://github.com/Corentin-k)
- [Nathan-P](https://github.com/nathp94)
- [Bastien-P](https://github.com/bouboumako)

Étudiants à l'EFREI en L2 semestre 3 (2023)
### Ce projet vise à réaliser une application qui permet de gérer un agenda en utilisant une structure de données intermédiaire entre les listes chaînées et les arbres. 

---
⚠️ **Remarque importante:**
Si le projet ne se lance pas, essayez de supprimer le dossier `cmake-build-debug` et relancez-le. Assurez-vous également d'accepter la reconstruction de ce même dossier.
---
## <u>Partie 1 - Implémentation des listes à niveaux – stockage d’entiers </u>

Cahier des charges :

Vous créerez des modules (ensemble fichier.c / fichier.h) pour :
    
 1. - [x]  Les cellules à niveau, avec les fonctionnalités suivantes :
    
        - [x] • Créer une cellule : on donne sa valeur et le nombre de niveaux que possède cette
cellule, pour obtenir un pointeur vers cette cellule

2. - [x]  Les listes à niveau, avec les fonctionnalités suivantes :

        - [x] • Créer une liste à niveau vide : on donnera le nombre maximal de niveaux que
        possède cette liste

        - [x] • Insérer une cellule à niveaux en tête de liste (attention à bien tenir compte du
        nombre de niveaux de la cellule)

        - [x] • Afficher l’ensemble des cellules de la liste pour un niveau donné

        - [x] • Afficher tous les niveaux de la liste

        - [x] • En option : afficher tous les niveaux de la liste, en alignant les cellules

        - [x] • Insérer une cellule à niveau dans la liste, au bon endroit, de manière à ce que la liste reste triée par ordre croissant

Voir le fichier [liste.h](fichier.h) et [liste.c](fichier.h)

---


## <u> Partie 2 – Complexité de la recherche dans une liste à niveau </u>

Voir les fichiers [research.h](research.h) et [research.c](research.h) et les fichiers timer

---
## <u> Partie 3 – Stockage des contacts dans une liste à niveau </u>


Voir les fichiers [contact.h](contact.h) et [contact.c](contact.h) 

---
# Pour voir la suite aller dans [Consigne et rapport > Rapport-KERVAGORET-PEGE-PELTIER.pdf](https://github.com/Corentin-k/Gestionnaire_Agenda/blob/main/Consigne%20et%20rapport/Rapport-KERVAGORET-PEGE-PELTIER.pdf)