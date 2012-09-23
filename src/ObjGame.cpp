#include "ObjGame.h"
#include "ObjTileWater.h"

#include "HScreen.h"
#include <cstdlib>

#include "ObjDino.h"

ObjGame::ObjGame(double x, double y)
{
    this->x = x;
    this->y = y;

    for(int i=0; i<300; i++)
    {
        new ObjTileWater((rand() % static_cast<int>(floor(HScreen::SCREEN_WIDTH / 16))) * 16, (rand() % static_cast<int>(floor(HScreen::SCREEN_HEIGHT / 16))) * 16);
    }

    new ObjDino(16, 16);
}

void ObjGame::onStep()
{

}

ObjGame::~ObjGame()
{
    //dtor
}
