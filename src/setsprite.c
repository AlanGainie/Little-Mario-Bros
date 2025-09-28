#include "../include/my.h"
#include <stdlib.h>

// Ma fonction créer un sprite
sfSprite *createSprite(sfVector2f setPossition, char *img, sfVector2f setScale, sfIntRect setRect)
{
    sfSprite *constructsprite = malloc(sizeof(sfSprite *));
    constructsprite = sfSprite_create();
    sfTexture *constructspritetexture = sfTexture_createFromFile(img, NULL);
    sfClock *clock = sfClock_create();
    
    sfSprite_setTexture(constructsprite, constructspritetexture, sfTrue);
    sfSprite_setPosition(constructsprite, setPossition);
    sfSprite_setScale(constructsprite, setScale);
    sfSprite_setTextureRect(constructsprite, setRect);
    return constructsprite;
}