#pragma once

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>

#include "physicalThing.h"
class Collectable : public sf::RectangleShape, public PhysicalThing
{
public:
	//Collectable(float posX, float posY);

	Collectable() {}

	Collectable(b2World * world, sf::Vector2f position, sf::Vector2f size, float orientation, sf::Color colour);

	

};

