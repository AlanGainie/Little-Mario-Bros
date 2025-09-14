/*
** Exemple minimal : Création d'une fenêtre CSFML
*/

#include "../include/my.h"

int window(void)
{
    // TODO: Rendre les noms de variable x et y plus clair et si c'est des floats mettre un chiffre à virgule
    //  sfVector2f mouv;
    float x = 50.0;
    float y = 50.0;

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
    sfSprite *rat = createSprite((sfVector2f){x, y}, "assets/pictures/sprites/rat.png", (sfVector2f){1, 1}, (sfIntRect){2, 2, 60, 60});
    //sfSprite *rat2 = createSprite((sfVector2f){x, y}, "assets/pictures/sprites/rat.png", (sfVector2f){1, 1}, (sfIntRect){2, 132, 60, 60});

    // Limite de FPS
    sfRenderWindow_setFramerateLimit(window, 60);

    // Boucle principale
    int setleft = 2;
    while (sfRenderWindow_isOpen(window))
    {
        sfEvent event;

        // rat.setRect;
        if (setleft != 122){
            sfSprite_setTextureRect(rat, (sfIntRect){setleft, 132, 60, 60});
            setleft = setleft + 60;
        } else {setleft = 2;}

        // Gestion des événements
        while (sfRenderWindow_pollEvent(window, &event))
        {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
            if (event.type == sfEvtKeyPressed && event.key.code == sfKeyD)
            {
                if (x <= 1865.0)
                {
                x = x + 15.0;
                my_printf("+mouvXD =%f", x);
                sfSprite_setPosition(rat, (sfVector2f){x, y});
                }
            }
            if (event.type == sfEvtKeyPressed && event.key.code == sfKeyA)
            {
                if (x >= -0.0)
                {
                x = x - 15.0;
                my_printf("+mouvXA =%f", x);
                sfSprite_setPosition(rat, (sfVector2f){x, y});
                }
            }
            if (event.type == sfEvtKeyPressed && event.key.code == sfKeyZ)
                if (y >= -0.0)
                {
                y = y - 15.0;
                my_printf("+mouvYZ =%f", y);
                sfSprite_setPosition(rat, (sfVector2f){x, y});
                }
            if (event.type == sfEvtKeyPressed && event.key.code == sfKeyS)
            {
                if (y <= 1005.0)
                {
                y = y + 15.0;
                my_printf("+mouvYS =%f", y);
                sfSprite_setPosition(rat, (sfVector2f){x, y});
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
    sfRenderWindow_destroy(window);
    return 0;
}
