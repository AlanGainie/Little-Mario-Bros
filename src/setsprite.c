#include "../include/my.h"
#include <stdlib.h>

// Ma fonction créer un sprite
// TODO: Mettre en place des gestions d'erreurs afin d'éviter de lancer le program avec des erreurs
sprite_t createSprite(sfVector2f setPossition, char *img, sfVector2f setScale, sfIntRect setRect)
{
    sfSprite *constructsprite = malloc(sizeof(sfSprite *));
    constructsprite = sfSprite_create();
    sfClock *clock = sfClock_create();
    sfTexture *constructspritetexture = sfTexture_createFromFile(img, NULL);
    sprite_t newsprite = {
        img,
        setPossition,
        setScale,
        setRect,
        clock,
        constructsprite,
        constructspritetexture};

    sfSprite_setTexture(newsprite.constructsprite, newsprite.constructspritetexture, sfTrue);
    sfSprite_setPosition(newsprite.constructsprite, newsprite.position);
    sfSprite_setScale(newsprite.constructsprite, newsprite.decoupage);
    sfSprite_setTextureRect(newsprite.constructsprite, newsprite.rect);
    return newsprite;
}