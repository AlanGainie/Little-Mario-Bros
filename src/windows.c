/*
** Exemple minimal : Création d'une fenêtre CSFML
*/

// Rapelle : gcc windows.c -o windows -lcsfml-graphics -lcsfml-window -lcsfml-system ./windows

#include <SFML/Graphics.h>
#include <SFML/Window.h>

int main(void)
{
    // Définition de la taille et des paramètres de la fenêtre
    sfVideoMode mode = {800, 600, 32};

    // Création de la fenêtre
    sfRenderWindow *window = sfRenderWindow_create(mode,
                                                   "Fenetre CSFML",
                                                   sfResize | sfClose,
                                                   NULL);
    // sprite
    sfSprite *background = sfSprite_create();
    sfTexture *backgroundtexture = sfTexture_createFromFile("assets/pictures/background.png", NULL);
    // jsp
    sfSprite_setTexture(background,backgroundtexture, sfTrue);
    sfSprite_setPosition(background, (sfVector2f){100, 100});

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
    sfRenderWindow_destroy(background);
    sfRenderWindow_destroy(window);
    return 0;
}
