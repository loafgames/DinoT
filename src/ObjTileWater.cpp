#include "ObjTileWater.h"

#include "SprTileWater.h"

ObjTileWater::ObjTileWater(double x, double y)
{
    objectType = OBJ_TILE_WATER;
    this->x = x;
    this->y = y;
    sprite = new SprTileWater();
}

ObjTileWater::~ObjTileWater()
{
    //dtor
}
