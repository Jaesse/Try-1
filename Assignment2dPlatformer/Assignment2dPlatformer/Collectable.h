#pragma once
/*!
\file Collectable.h
*/
#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>

#include "physicalThing.h"

/*! \class Collectable
\brief Initiation of a collectable object 
*/

class Collectable : public sf::RectangleShape, public PhysicalThing
{
public:
	//Collectable(float posX, float posY);

	Collectable() {} //!< Default constructor

	Collectable(b2World * world, sf::Vector2f position, sf::Vector2f size, float orientation, sf::Color colour);//!<Set up of collectable class

	

};

