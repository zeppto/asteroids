#include "Menu.h"
#include "Game.hpp"

void Menu::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(menyWelcome, states);
	target.draw(startButton, states);
}

Menu::Menu()
{
	timmer = 0;
	menyWelcome.setFont(font);
	menyWelcome.setString("Astroides");
	menyWelcome.setCharacterSize(100);
	menyWelcome.setColor(sf::Color::White);
	menyWelcome.setPosition(sf::Vector2f(550, 110));

	startButton.setFont(font);
	startButton.setString("Press enter to start");
	startButton.setCharacterSize(50);
	startButton.setColor(sf::Color::White);
	startButton.setPosition(sf::Vector2f(530, 310));

		if (!font.loadFromFile("../Resources/Anasthesia.ttf"))
	{
		std::cout << "error no font" << std::endl;
	}
	std::cout << "it can work !!!!!!" << std::endl;
}

void Menu::handelEvent(sf::Event event)
{
}

BaseState * Menu::update(float dt)
{
	timmer++;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && timmer > 300)
		return new Game();

	return nullptr;
}
