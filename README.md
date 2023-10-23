# Projet-L2-Algorithme et structure de données 2
 
Par [@Corentin-k](https://github.com/Corentin-k)

### Ce projet vise à réaliser une application qui permet de gérer un agenda en utilisant une structure de données intermédiaire entre les listes chaînées et les arbres. 

---
## <u>Partie 1 - Implémentation des listes à niveaux – stockage d’entiers </u>

Cahier des charges :

Vous créerez des modules (ensemble fichier.c / fichier.h) pour :
    
 1. - [ ]  Les cellules à niveau, avec les fonctionnalités suivantes :
    
        - [ ] • Créer une cellule : on donne sa valeur et le nombre de niveaux que possède cette
cellule, pour obtenir un pointeur vers cette cellule

2. - [ ]  Les listes à niveau, avec les fonctionnalités suivantes :

        - [ ] • Créer une liste à niveau vide : on donnera le nombre maximal de niveaux que
        possède cette liste

        - [ ] • Insérer une cellule à niveaux en tête de liste (attention à bien tenir compte du
        nombre de niveaux de la cellule)

        - [ ] • Afficher l’ensembles des cellules de la liste pour un niveau donné

        - [ ] • Afficher tous les niveaux de la liste

        - [ ] • En option : afficher tous les niveaux de la liste, en alignant les cellules

        - [ ] • Insérer une cellule à niveau dans la liste, au bon endroit, de manière à ce que la liste reste triée par ordre croissant

Pour cette dernière fonctionnalité, il est possible de faire une ‘simple’ insertion à
chaque niveau en partant du début de la liste, mais il est possible d’être plus
efficace, à vous de trouver comment.

Vous écrirez un programme (fonction main()) qui illustre toutes ces fonctionnalités 

---

## <u> Partie 2 – Complexité de la recherche dans une liste à niveau </u>

L’utilisation de liste à niveaux permet d’accélérer les recherches pour obtenir une complexité
qui s’approche de celle de la recherche par dichotomie. Pour l’illustrer, nous allons construire
une grande liste à niveau, et comparer :
Le temps mis pour des recherches en utilisant uniquement le niveau 0 (donc comme une liste
chaînée simple)
Le temps mis pour des recherches en utilisant tous les niveaux.
Le principe de recherche est le suivant : on commence la recherche au niveau le plus haut. Si
on ne trouve pas la valeur à ce niveau, on continue la recherche au niveau précédent en
repartant de la cellule à laquelle on était arrivé.
Pour cela, nous allons construire des listes à niveau avec le principe suivant.
Soit un entier  :
La liste stockera 2
  1 cellules, avec les valeurs de 1 à 2
  1
Chaque niveau pointera une cellule sur deux du niveau précédent. Il y aura donc 
niveaux 