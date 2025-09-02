/*
** Exemple minimal : Création d'une fenêtre CSFML
*/

#include "../include/my.h"

int window(void)
{
    // TODO: Rendre les noms de variable x et y plus clair et si c'est des floats mettre un chiffre à virgule
    //  sfVector2f mouv;
    float x = 50;
    float y = 50;
    // Définition de la taille et des paramètres de la fenêtre
    sfVideoMode mode = {1920, 1080, 32};

    // Création de la fenêtre
    sfRenderWindow *window = sfRenderWindow_create(mode,
                                                   "Fenetre CSFML",
                                                   sfResize | sfClose,
                                                   NULL);

    // Set sprite
    sfSprite *background = createSprite((sfVector2f){0, 0}, "assets/pictures/background.png", (sfVector2f){1.333f, 1.35f}, (sfIntRect){0, 0, 1440, 800});
    sfSprite *rat = createSprite((sfVector2f){x, y}, "assets/pictures/sprites/rat.png", (sfVector2f){1, 1}, (sfIntRect){2, 2, 60, 60});

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
            if (event.type == sfEvtKeyPressed && event.key.code == sfKeyA)
            {
                x = x + 15.0;
                my_printf("+mouv =%f", x);
                sfSprite_setPosition(rat, (sfVector2f){x, y});
            }
        }

        // Effacer la fenêtre avec une couleur noire
        sfRenderWindow_clear(window, sfBlack);

        // Afficher le contenu
        sfRenderWindow_drawSprite(window, background, NULL);
        sfRenderWindow_drawSprite(window, rat, NULL);
        sfRenderWindow_display(window);
    }

    // TODO: Créer un fichier end qui prendra en compte tous les libérations mémoire et détruira les composants restant
    // Détruire la fenêtre à la fin
    sfSprite_destroy(background);
    sfSprite_destroy(rat);
    sfRenderWindow_destroy(window);
    return 0;
}
