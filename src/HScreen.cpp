#include "HScreen.h"

HScreen* HScreen::instance;
sf::Color HScreen::BACKGROUND_COLOR = sf::Color(255, 255, 255);

HScreen::HScreen()
{
	instance = this;
	screen = new sf::RenderWindow(sf::VideoMode(800, 600), "DinoTurret");
}


HScreen::~HScreen()
{
}

HScreen* HScreen::getInstance()
{
	return instance;
}

sf::RenderWindow* HScreen::getScreen()
{
	return getInstance()->screen;
}
