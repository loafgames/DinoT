#pragma once

#include "Room.h"

class HResources
{
private:
	static HResources* instance;

public:
	static Room* ROOM_TEST;

	static sf::Image sprTileWater;
	static sf::Image sprDino;

	HResources(void);
	~HResources(void);

	static HResources* getInstance();

	static Room* Room_Load(const char* url);
};

