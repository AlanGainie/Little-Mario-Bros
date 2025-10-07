/*
** Exemple minimal : Création d'une fenêtre CSFML
*/

#include "../include/my.h"

int window(void)
{
    // TODO: Rendre les noms de variable x et y plus clair et si c'est des floats mettre un chiffre à virgule
    //  sfVector2f mouv;
    float position_abscice_sprite_rat = 50.0;
    float position_ordonner_sprite_rat = 50.0;

    // Définition de la taille et des paramètres de la fenêtre
    sfVideoMode mode = {1920, 1080, 32};

    // Création de la fenêtre
    sfRenderWindow *window = sfRenderWindow_create(mode,
                                                   "Fenetre CSFML",
                                                   sfResize | sfClose,
                                                   NULL);

    // set icon
    sfImage *icon = sfImage_createFromFile("assets/pictures/icon.png");
    const sfUint8 *pixels = sfImage_getPixelsPtr(icon);
    sfVector2u sizeicon = sfImage_getSize(icon);
    sfRenderWindow_setIcon(window, (unsigned int)16, (unsigned int)16, pixels);

    // Set sprite
    sprite_t background = createSprite((sfVector2f){0, 0}, "assets/pictures/background.png", (sfVector2f){1.333, 1.333}, (sfIntRect){0, 0, 1440, 800});
    sprite_t rat = createSprite((sfVector2f){position_abscice_sprite_rat, position_ordonner_sprite_rat}, "assets/pictures/sprites/rat.png", (sfVector2f){1, 1}, (sfIntRect){2, 2, 60, 60});
    // sfSprite *rat2 = createSprite((sfVector2f){x, y}, "assets/pictures/sprites/rat.png", (sfVector2f){1, 1}, (sfIntRect){2, 132, 60, 60});

    // Limite de FPS
    sfRenderWindow_setFramerateLimit(window, 60);

    // structure setsprite
    // Boucle principale
    rat.rect.left = 2;
    rat.rect.top = 132;
    //sfMicroseconds
    //sfSeconds
    //sfTime_asSeconds
    //sfTime time;
    while (sfRenderWindow_isOpen(window))
    {
        sfEvent event;

        // rat.setRect;
        if (rat.rect.left != 122)
        {
            sfSprite_setTextureRect(rat.constructsprite, rat.rect);
            sfClock_getElapsedTime(rat.clock);
            if (rat.clock >= 1 / 4)
            {
                rat.rect.left = rat.rect.left + 60;
                sfClock_restart(rat.clock);
            }
        }
        else
        {
            rat.rect.left = 2;
        }

        // Gestion des événements
        while (sfRenderWindow_pollEvent(window, &event))
        {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
            if (event.type == sfEvtKeyPressed && event.key.code == sfKeyD)
            {
                if (rat.position.x <= 1865.0)
                {
                    rat.position.x = rat.position.x + 15.0;
                    my_printf("+mouvXD =%f", rat.position.x);
                    sfSprite_setPosition(rat.constructsprite, rat.position);
                }
            }
            if (event.type == sfEvtKeyPressed && event.key.code == sfKeyA)
            {
                if (rat.position.x >= -0.0)
                {
                    rat.position.x = rat.position.x - 15.0;
                    my_printf("+mouvXA =%f", rat.position.x);
                    sfSprite_setPosition(rat.constructsprite, rat.position);
                }
            }
            if (event.type == sfEvtKeyPressed && event.key.code == sfKeyZ)
                if (rat.position.y >= -0.0)
                {
                    rat.position.y = rat.position.y - 15.0;
                    my_printf("+mouvYZ =%f", rat.position.y);
                    sfSprite_setPosition(rat.constructsprite, rat.position);
                }
            if (event.type == sfEvtKeyPressed && event.key.code == sfKeyS)
            {
                if (rat.position.y <= 1005.0)
                {
                    rat.position.y = rat.position.y + 15.0;
                    my_printf("+mouvYS =%f", rat.position.y);
                    sfSprite_setPosition(rat.constructsprite, rat.position);
                }
            }
        }

        // Effacer la fenêtre avec une couleur noire
        sfRenderWindow_clear(window, sfBlack);

        // Afficher le contenu
        sfRenderWindow_drawSprite(window, background.constructsprite, NULL);
        sfRenderWindow_drawSprite(window, rat.constructsprite, NULL);
        // sfRenderWindow_drawSprite(window, rat2, NULL);
        sfRenderWindow_display(window);
    }

    // TODO: Créer un fichier end qui prendra en compte tous les libérations mémoire et détruira les composants restant
    // Détruire la fenêtre à la fin
    sfSprite_destroy(background.constructsprite);
    sfSprite_destroy(rat.constructsprite);
    sfClock_destroy(rat.clock);
    free(rat.constructsprite);
    sfRenderWindow_destroy(window);
    return 0;
}
