#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "BaseState.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	sf::RenderWindow window(sf::VideoMode(1600, 900), "Asteroid");

	sf::Clock gameTime;
	BaseState* currentState = new Menu();

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window.close();
			currentState->handelEvent(event);
		}

		// Update()
		BaseState* newState = currentState->update(gameTime.restart().asSeconds());
		if (newState != nullptr)
		{
			delete currentState;
			currentState = newState;
		}

		// Draw()
		window.clear();
		window.draw(*currentState);
		window.display();
	}

	delete currentState;
	return 0;
}