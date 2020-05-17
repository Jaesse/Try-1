#pragma once

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>

#include "physicalThing.h"

class movingBlock : public sf::RectangleShape, public PhysicalThing
{
public:
	movingBlock() {};
	movingBlock(b2World * world, sf::Vector2f position, sf::Vector2f size, const float orientation, sf::Color colour );

	void moveBlock();

	void update();

private:
	
};

