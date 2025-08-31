# Little-Mario-Bros
##### A littel Mario Bros game start and go with Yaouen and Alan

## L'objectif du projet

Le but de se projet est de faire une sorte de petit mario bros afin de se remetre dans le bain du CSFML et de la création/ édition de jeux vidéo 2D rétro. Ce que nous allons essayer de réaliser :

- Facile
-> Mettre en place un background animer (parralaxe)
-> Mettre en place les déplacements des personnages
-> Gérer les sprites (croper)
-> Mettre des sounds effect

- - Moyen
-> Mettre en place un system de saut personnaliser (parrabolique)
-> Faire une mini map
-> Ajouter un item de pièce
-> Ajouter un drapeau (condition de fin)

- - - Difficile
-> Mettre en place un boutton cliquable afin de pouvoir sauvegarder la progression
-> Rajoutter des options
-> Faire des chargements de niveaux personnaliser

- - - - Hardcore
-> Ajouter des énemie

## Githelp

Dans ce projet ont utilise github dans se but nous avons besoin des commandes suivantes :

    Commande de base LINUX/WINDOWS en indite de commande:
        git status -> permet de voir l'état des add, commit, push

        git add ... -> Ajouter l'ensemble des fichiers modifier qu'on souhaite envoyé
        git commit -m ... -> Nomme l'envoie (pareil qu'un timbre pour une envelope)
        git push -> envoie le paquet

        git pull -> Pour récupérer le contenue du git
        git merge -> Pour rassembler le contenue local (tien) et celui du git

# Etat du projet

Ce dimanche 31 aout nous avons débuter la création du jeux vidéo par la mise en place d'un background. Dans un premier temps static mais à la taille de notre fenètre et dans un second temps plus tard animer sous la forme d'une paralaxe.

Pour ce faire nous avons du créer une fonction qui définis les paramètres de base des sprites:
```C
// Etat de la fonction le 31/08

#include "../include/my.h"

// Ma fonction créer un sprite
sfSprite *createSprite(sfVector2f possition, char *img)
{
    sfSprite *constructsprite = sfSprite_create();
    sfTexture *constructspritetexture = sfTexture_createFromFile(img, NULL);

    sfSprite_setTexture(constructsprite, constructspritetexture, sfTrue);
    sfSprite_setPosition(constructsprite, possition);
    return constructsprite;
}
```