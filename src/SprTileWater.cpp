#include "SprTileWater.h"

#include "HResources.h"

SprTileWater::SprTileWater()
{
    image = &HResources::sprTileWater;
    imageCount = 1;

    setup();
    setHitboxFull(HITBOX_RECTANGLE);
}

SprTileWater::~SprTileWater()
{
    //dtor
}
