#pragma once

/*!
\file paddle.h
*/

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>

#include "physicalThing.h"

/*! \class Paddle
\brief A simple block which is moved by a motor joint
*/

class Paddle : public sf::RectangleShape, public PhysicalThing
{
public:
	Paddle() {}; //!< Default Constructor
	Paddle(b2World * world, sf::Vector2f position, sf::Vector2f size, const float orientation, sf::Color colour); //!< Complete contructor
	void update(); //!< Update rendering infomation 
};