#include "SprDino.h"

#include "HResources.h"

SprDino::SprDino()
{
    image = &HResources::sprDino;
    imageCount = 1;

    setup();
    setHitboxFull(HITBOX_RECTANGLE);
}

SprDino::~SprDino()
{
    //dtor
}
