/*
** Exemple minimal : Création d'une fenêtre CSFML
*/

// Rapelle : gcc windows.c -o windows -lcsfml-graphics -lcsfml-window -lcsfml-system ./windows

#include "../include/my.h"

int window(void)
{
    // Définition de la taille et des paramètres de la fenêtre
    sfVideoMode mode = {1920, 1080, 32};

    // Création de la fenêtre
    sfRenderWindow *window = sfRenderWindow_create(mode,
                                                   "Fenetre CSFML",
                                                   sfResize | sfClose,
                                                   NULL);

    // Set sprite
    sfSprite *background = createSprite((sfVector2f){0, 0}, "assets/pictures/background.png", (sfVector2f){1.333f,1.35f}, (sfIntRect){0,0,1440,800});

    // Limite de FPS
    sfRenderWindow_setFramerateLimit(window, 60);

    // Boucle principale
    while (sfRenderWindow_isOpen(window))
    {
        sfEvent event;

        // Gestion des événements
        while (sfRenderWindow_pollEvent(window, &event))
        {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }

        // Effacer la fenêtre avec une couleur noire
        sfRenderWindow_clear(window, sfBlack);

        // Afficher le contenu
        sfRenderWindow_drawSprite(window, background, NULL);
        sfRenderWindow_display(window);
    }

    // Détruire la fenêtre à la fin
    sfSprite_destroy(background);
    sfRenderWindow_destroy(window);
    return 0;
}
