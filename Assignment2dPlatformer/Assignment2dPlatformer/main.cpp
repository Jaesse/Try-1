/*!
\file main.cpp
\brief Contains the entry point for the application
*/

#include <Box2D/Box2D.h>

#include <SFML/Graphics.hpp>

#include "game.h"



void main() /** Entry point for the application */
{

	Game game;
	game.Loop();

	/*
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




	*/


}



	/*sf::RenderWindow window(sf::VideoMode(800, 600), "2D Platformer"); //Window Render
	cout << "Rendered window of 800 x 600 y\n" << endl;


	//Main Camera Creation
	sf::View mainView;
	mainView.setSize(400.f, 300.f);
	mainView.setCenter(200.f, 150.f);
	window.setView(mainView);

	/////////////////////////////
	

	

	/*Shape Creations
	sf::RectangleShape player(sf::Vector2f(100.f, 100.f));
	player.setFillColor(sf::Color::White);
	player.setPosition(0.f, 0.f);
	cout << "Drew player" << endl;


	sf::RectangleShape rect(sf::Vector2f(300.f, 100.f));
	rect.setFillColor(sf::Color::White);
	rect.setPosition(150.f, 250.f);
	cout << "Drew rect" << endl;


	/////////////////////////////////////////////////////*/


	/*/Textures
	sf::Texture playerTexture;
	playerTexture.loadFromFile("Creature2.png");
	
	player.setTexture(&playerTexture);

	sf::Texture platform0Texture;
	platform0Texture.loadFromFile("Platform0.png");

	rect.setTexture(&platform0Texture);
	
	

	//*Window Show
	while (window.isOpen()) {

		sf::Event event;

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) 
		{
			player.move(0.0f, -0.5f);
			
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		{
			player.move(-0.5f, 0.0f);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		{
			player.move(0.0f, 0.5f);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		{
			player.move(0.5f, 0.0f);

		}
		


		window.clear(sf::Color::White);
		
		
		
		//window.draw(rect);
		//window.draw(player);
		
		
		window.display();
	}







	system("PAUSE");
	return 0;
	*/





