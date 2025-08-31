#include "../include/my.h"

// Ma fonction créer un sprite
sfSprite *createSprite(sfVector2f setPossition, char *img, sfVector2f setScale)
{
    sfSprite *constructsprite = sfSprite_create();
    sfTexture *constructspritetexture = sfTexture_createFromFile(img, NULL);

    sfSprite_setTexture(constructsprite, constructspritetexture, sfTrue);
    sfSprite_setPosition(constructsprite, setPossition);
    sfSprite_setScale(img, setScale);
    return constructsprite;
}