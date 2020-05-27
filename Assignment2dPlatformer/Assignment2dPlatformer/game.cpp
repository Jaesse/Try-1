/*!
\file game.cpp
*/
#include "game.h"

Game::Game()
{
	m_view.setCenter(0.f, 0.f);
	m_view.setSize(m_worldSize);

	m_pWorld = new b2World(mk_gravity);

	m_debugDraw.setWorld(m_pWorld);

	m_puck = DynamicCircle(m_pWorld, sf::Vector2f(0.f, -1.5f), 0.13f, 0.0f, sf::Color::Magenta);
	m_puck.setUserData(&m_puck);

	m_staticBlocks.resize(4);
	m_staticBlocks[0] = StaticBlock(m_pWorld, sf::Vector2f(0.f, 2.0f), sf::Vector2f(1.0f, 0.25f), 0.f, sf::Color::Green);
	m_staticBlocks[1] = StaticBlock(m_pWorld, sf::Vector2f(1.0f, 1.0f), sf::Vector2f(1.0f, 0.25f), 0.f, sf::Color::Green);
	m_staticBlocks[2] = StaticBlock(m_pWorld, sf::Vector2f(2.0f, 0.0f), sf::Vector2f(1.0f, 0.25f), 0.f, sf::Color::Green);
	m_staticBlocks[3] = StaticBlock(m_pWorld, sf::Vector2f(3.0f, -1.0f), sf::Vector2f(1.0f, 0.25f), 0.f, sf::Color::Green);

	m_collectableCoin.resize(1);
	m_collectableCoin[0] = Collectable(m_pWorld, sf::Vector2f(0.f, 1.f), sf::Vector2f(0.2f, 0.2f), 0.f, sf::Color::Yellow);

	m_leftPaddle = Paddle(m_pWorld, sf::Vector2f(-0.5f, 1.5f), sf::Vector2f(0.1f, 0.8f), 0.0f, sf::Color::Red);
	m_leftPaddle.setUserData(&m_leftPaddle);

	m_rightPaddle = Paddle(m_pWorld, sf::Vector2f(3.5f, -1.5f), sf::Vector2f(0.1f, 0.8f), 0.0f, sf::Color::Blue);
	m_rightPaddle.setUserData(&m_rightPaddle);


	m_movingPlat = movingBlock(m_pWorld, sf::Vector2f(0.f, -0.5f), sf::Vector2f(0.5f, 0.5f), 0.0f, sf::Color::Magenta);
	m_movingPlat.setUserData(&m_movingPlat);
	
	
	_contactListener = new	MyContactListener();
	m_pWorld->SetContactListener(_contactListener);

}


void Game::Loop()
{

	sf::RenderWindow window(sf::VideoMode(800, 600), "Box2D Demo"); // Open main window
	Game game;
	DynamicCircle dynamicCircle(m_pWorld, sf::Vector2f(0.f, 0.f), 0.13f, 0.0f, sf::Color::Magenta);

	float fFrameTime = 1.f / 60.f;

	// Start a clock to provide time for the physics
	sf::Clock clock;

	// Run a game loop
	while (window.isOpen())
	{
		window.clear(sf::Color::White);

		sf::Event event;
		while (window.pollEvent(event))
		{
			// window closed button pressed
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Tab)
				{
					game.toggleDebug();
				}

				dynamicCircle.keyPress(event.key.code);

			}


		}

		

	/*	std::vector<MyContact>::iterator pos;
		for (pos = _contactListener->_contacts.begin();
			pos != _contactListener->_contacts.end(); ++pos) {
			MyContact contact = *pos;
			if ((contact.fixtureA == m_puck && contact.fixtureB == m_collectableCoin) ||
				(contact.fixtureA == m_collectableCoin && contact.fixtureB == m_puck)) {


			}

		}*/


		// Find out how much time has elapsed

		float fElapsedTime = clock.getElapsedTime().asSeconds();
		// If a frame has past then update the physics
		if (fElapsedTime > fFrameTime)
		{
			game.update(fElapsedTime);
			clock.restart();
		}

		window.draw(game);
		window.display();
	}

}

Game::~Game()
{
	delete m_pWorld;
	m_pWorld = nullptr;
	delete _contactListener;
}

void Game::update(float timestep)
{
	// Update the world
	m_pWorld->Step(timestep, mk_iVelIterations, mk_iVelIterations);

	// Update all game objects - updates rendering positions
	
	
	
	m_puck.update();
	m_leftPaddle.update();
	m_rightPaddle.update();
	m_movingPlat.update();

	// Delete debug shapes
	if (m_debug) m_debugDraw.clear();
}





void Game::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	// Set the view
	target.setView(m_view);

	// Draw all game objects
	for (auto block : m_staticBlocks) target.draw(block);
	for (auto block : m_collectableCoin) target.draw(block);

	target.draw(m_leftPaddle);
	target.draw(m_rightPaddle);
	target.draw(m_puck);
	target.draw(m_movingPlat);

	// Debug Draw
	if (m_debug) target.draw(m_debugDraw);
}

void Game::toggleDebug()
{
	m_debug = !m_debug;
}



