#include <SFML/Graphics.hpp>
#include "Game.hpp"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	sf::RenderWindow window(sf::VideoMode(1600, 900), "Game Window");
	Game game;
	sf::Clock gameTime;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// Update()
		game.Update(gameTime.restart().asSeconds());

		// Draw()
		window.clear();
		window.draw(game);
		window.display();
	}

	return 0;
}