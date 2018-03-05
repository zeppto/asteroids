#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "BaseState.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	sf::RenderWindow window(sf::VideoMode(1600, 900), "Asteroid");
	Game game;
	sf::Clock gameTime;
	BaseState* currentState = new Game();

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::TextEntered)
			{
				if (game.isGameOverState() && ((event.text.unicode >= 33 && event.text.unicode <= 122)
					||event.text.unicode == 8 || event.text.unicode == 13))
					game.enterPlayerName((char)event.text.unicode);
			}
		}

		// Update()
		currentState->update(gameTime.restart().asSeconds());
		//game.Update(gameTime.restart().asSeconds());

		// Draw()
		window.clear();
		window.draw(*currentState);
		//window.draw(game);
		window.display();
	}

	return 0;
}