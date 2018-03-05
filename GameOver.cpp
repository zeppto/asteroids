#include "GameOver.h"
#include "ScoreBoard.h"

void GameOver::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(gameOverText, states);
	target.draw(enterNameText, states);
	target.draw(nameEnterd, states);
}

GameOver::GameOver(int score)
{
	this->score = score;
	returnForUpdate = nullptr;

	if (!font.loadFromFile("../Resources/Anasthesia.ttf"))
	{
		std::cout << "error no font" << std::endl;
	}

	gameOverText.setFont(font);
	gameOverText.setString("GAME OVER");
	gameOverText.setCharacterSize(100);
	gameOverText.setColor(sf::Color::White);
	gameOverText.setPosition(sf::Vector2f(550, 110));

	enterNameText.setFont(font);
	enterNameText.setString("enter name:");
	enterNameText.setCharacterSize(50);
	enterNameText.setColor(sf::Color::White);
	enterNameText.setPosition(sf::Vector2f(530, 310));

	nameEnterd.setFont(font);
	nameEnterd.setString("");
	nameEnterd.setCharacterSize(50);
	nameEnterd.setColor(sf::Color::White);
	nameEnterd.setPosition(sf::Vector2f(830, 310));
}

void GameOver::handelEvent(sf::Event event)
{
	if (event.type == sf::Event::TextEntered)
	{
	if ((event.text.unicode >= 33 && event.text.unicode <= 122)
	||event.text.unicode == 8 || event.text.unicode == 13)
	enterPlayerName((char)event.text.unicode);
	}
}

void GameOver::enterPlayerName(char enterd)
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
		//kan sabas om du tar bort caraktärer somm inte finns
		EnterdCaracter.pop_back();
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	{
		returnForUpdate = new ScoreBoard(score, EnterdCaracter);
	}
	else
		EnterdCaracter += enterd;

	nameEnterd.setString(EnterdCaracter);
}

BaseState * GameOver::update(float dt)
{
	return returnForUpdate;
}
