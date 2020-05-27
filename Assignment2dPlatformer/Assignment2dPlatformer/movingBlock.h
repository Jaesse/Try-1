#pragma once

/*!
\file movingBlock.h
*/

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>

#include "physicalThing.h"

/*! \class movingBlock
\brief Initiation of a physical block which moves across the window
*/

class movingBlock : public sf::RectangleShape, public PhysicalThing
{
public:
	movingBlock() {}; //!< Default constructor
	movingBlock(b2World * world, sf::Vector2f position, sf::Vector2f size, const float orientation, sf::Color colour );//!< Complete constructor of moving block

	void moveBlock();//!< Moves block

	void update();//!< Updates the position and data of the block.

private:
	
};

