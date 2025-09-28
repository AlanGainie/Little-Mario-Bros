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
    sfSprite *background = createSprite((sfVector2f){0, 0}, "assets/pictures/background.png", (sfVector2f){1.333, 1.333}, (sfIntRect){0, 0, 1440, 800});
    //sfSprite *rat = createSprite((sfVector2f){position_abscice_sprite_rat, position_ordonner_sprite_rat}, "assets/pictures/sprites/rat.png", (sfVector2f){1, 1}, (sfIntRect){2, 2, 60, 60});
    //sfSprite *rat2 = createSprite((sfVector2f){x, y}, "assets/pictures/sprites/rat.png", (sfVector2f){1, 1}, (sfIntRect){2, 132, 60, 60});

    // Limite de FPS
    sfRenderWindow_setFramerateLimit(window, 60);

    // Set clock
    sfClock *clock = sfClock_create();
    // sprite_t rat = {(){}; (){}; (){}; (){};};
    // Boucle principale
    int setleft = 2;
    while (sfRenderWindow_isOpen(window))
    {
        sfEvent event;

        // rat.setRect;
        if (setleft != 122){
            sfSprite_setTextureRect(rat, (sfIntRect){setleft, 132, 60, 60});
            sfClock_getElapsedTime(clock);
            if (clock >= 1 / 4) {setleft = setleft + 60; sfClock_restart(clock);}
        } else {setleft = 2;}

        // Gestion des événements
        while (sfRenderWindow_pollEvent(window, &event))
        {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
            if (event.type == sfEvtKeyPressed && event.key.code == sfKeyD)
            {
                if (position_abscice_sprite_rat <= 1865.0)
                {
                position_abscice_sprite_rat = position_abscice_sprite_rat + 15.0;
                my_printf("+mouvXD =%f", position_abscice_sprite_rat);
                sfSprite_setPosition(rat, (sfVector2f){position_abscice_sprite_rat, position_ordonner_sprite_rat});
                }
            }
            if (event.type == sfEvtKeyPressed && event.key.code == sfKeyA)
            {
                if (position_abscice_sprite_rat >= -0.0)
                {
                position_abscice_sprite_rat = position_abscice_sprite_rat - 15.0;
                my_printf("+mouvXA =%f", position_abscice_sprite_rat);
                sfSprite_setPosition(rat, (sfVector2f){position_abscice_sprite_rat, position_ordonner_sprite_rat});
                }
            }
            if (event.type == sfEvtKeyPressed && event.key.code == sfKeyZ)
                if (position_ordonner_sprite_rat >= -0.0)
                {
                position_ordonner_sprite_rat = position_ordonner_sprite_rat - 15.0;
                my_printf("+mouvYZ =%f", position_ordonner_sprite_rat);
                sfSprite_setPosition(rat, (sfVector2f){position_abscice_sprite_rat, position_ordonner_sprite_rat});
                }
            if (event.type == sfEvtKeyPressed && event.key.code == sfKeyS)
            {
                if (position_ordonner_sprite_rat <= 1005.0)
                {
                position_ordonner_sprite_rat = position_ordonner_sprite_rat + 15.0;
                my_printf("+mouvYS =%f", position_ordonner_sprite_rat);
                sfSprite_setPosition(rat, (sfVector2f){position_abscice_sprite_rat, position_ordonner_sprite_rat});
                }
            }
        }

        // Effacer la fenêtre avec une couleur noire
        sfRenderWindow_clear(window, sfBlack);

        // Afficher le contenu
        sfRenderWindow_drawSprite(window, background, NULL);
        sfRenderWindow_drawSprite(window, rat, NULL);
        //sfRenderWindow_drawSprite(window, rat2, NULL);
        sfRenderWindow_display(window);
    }

    // TODO: Créer un fichier end qui prendra en compte tous les libérations mémoire et détruira les composants restant
    // Détruire la fenêtre à la fin
    sfSprite_destroy(background);
    sfSprite_destroy(rat);
    sfClock_destroy(clock);
    sfRenderWindow_destroy(window);
    return 0;
}
