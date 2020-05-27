#pragma once

/*!
\file game.h
*/

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>

#include <vector>

#include "SFMLDebugDraw.h"

#include "Collectable.h"
#include "paddle.h"
#include "dynamicCircle.h"
#include "staticBlock.h"
#include "movingBlock.h"
#include "MyContactListener.h"

/*! \class Game
\brief Holds all information about the game, blocks, balls etc and allows updating and rendering.
*/

class Game : public sf::Drawable {
private:
	sf::View m_view; //!< The view maps from physical co-ordinates to rendering co-ordinates
	sf::Vector2f m_worldSize = sf::Vector2f(8.f, 6.f); //!< Size of the physical worlds is 8 X 6 metres

	b2World* m_pWorld = nullptr; //!< Pointer to the Box2D world.  Using pointers as BOX2D has it's own memory management
	const int mk_iVelIterations = 7; //!< On each update there will be 7 velocity iterations in the physics engine
	const int mk_iPosIterations = 5; //!< On each update there will be 5 position iterations on each update
	const b2Vec2 mk_gravity = b2Vec2(0.f, 1.f); //!< Standard earth gravity will be used (negate the value ofcourse!)

	bool m_debug = false; //!< Toggle for debug drawing
	SFMLDebugDraw m_debugDraw; //!< Box2D debug drawing

	DynamicCircle m_puck; //!< Pong puck
	std::vector<StaticBlock> m_staticBlocks; //!< Walls
	Paddle m_leftPaddle; //!< Moving block
	Paddle m_rightPaddle; //!< Moving block

	movingBlock m_movingPlat;

	MyContactListener *_contactListener;

	std::vector<Collectable> m_collectableCoin;

public:
	Game(); //!< Constructor which sets up the game
	~Game(); //!< Destructor which cleans all the pointer memory up
	void Loop(); //!< Sets up game loop (Renders events etc..)




	void update(float timestep); //!< Update the game with give timestep
	void draw(sf::RenderTarget &target, sf::RenderStates states) const; //!< Draw the game to the render context
	void toggleDebug(); //!< Toggle for debug drawing
	
};
