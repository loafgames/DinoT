#include "ObjDino.h"

#include "SprDino.h"

#include "HScreen.h"

const int ObjDino::WALK_DELAY = 5;
const int ObjDino::SHOOT_DELAY = 30;

ObjDino::ObjDino(double x, double y)
{
    objectType = OBJ_DINO;

    this->x = x;
    this->y = y;

    sprite = new SprDino();

    walkDelay = 0;
    shootDelay = 0;
}

void ObjDino::onStep()
{
    if(HScreen::getScreen()->GetInput().IsKeyDown(sf::Key::W))
    {
        if(Obj::getCollisionPoint(x, y-16, OBJ_TILE_WATER) == NULL)
        {
            if(walkDelay <= 0)
            {
                y -= 16;
                walkDelay = WALK_DELAY;
            }
        }
    }
    if(HScreen::getScreen()->GetInput().IsKeyDown(sf::Key::A))
    {
        if(Obj::getCollisionPoint(x-16, y, OBJ_TILE_WATER) == NULL)
        {
            if(walkDelay <= 0)
            {
                x -= 16;
                walkDelay = WALK_DELAY;
            }
        }
    }
    if(HScreen::getScreen()->GetInput().IsKeyDown(sf::Key::S))
    {
        if(Obj::getCollisionPoint(x, y+16, OBJ_TILE_WATER) == NULL)
        {
            if(walkDelay <= 0)
            {
                y += 16;
                walkDelay = WALK_DELAY;
            }
        }
    }
    if(HScreen::getScreen()->GetInput().IsKeyDown(sf::Key::D))
    {
        if(Obj::getCollisionPoint(x+16, y, OBJ_TILE_WATER) == NULL)
        {
            if(walkDelay <= 0)
            {
                x += 16;
                walkDelay = WALK_DELAY;
            }
        }
    }
    if(walkDelay > 0)
    {
        walkDelay--;
    }
    if(shootDelay > 0)
    {
        shootDelay--;
    }

    Obj::onStep();
}

ObjDino::~ObjDino()
{
    delete sprite;
}
