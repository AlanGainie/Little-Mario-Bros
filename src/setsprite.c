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