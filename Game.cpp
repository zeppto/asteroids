#include "Game.hpp"
#include <iostream>
#include "GameOver.h"

Game::Game() :mPlayer(1)
{
	returnToUpdate = nullptr;

	if (!mBackgroundTex.loadFromFile("../Resources/background1.png"))
	{
		std::cout << "ERROR: Background image could not be loaded.\n---" << std::endl;
	}
	mBackgroundSprite.setTexture(mBackgroundTex);

	if (!font.loadFromFile("../Resources/Anasthesia.ttf"))
	{
		std::cout << "error no font" << std::endl;
	}
	scoreCounter.setFont(font);
	scoreCounter.setString("0");
	scoreCounter.setCharacterSize(30);
	scoreCounter.setColor(sf::Color::White);
	scoreCounter.setPosition(sf::Vector2f(10, 10));
	score = 0; 
}

BaseState* Game::update(float dt)
{
	srand(time(NULL));

	//updates
	mPlayer.Update(dt);
	astroidHandler.setPlayerSpritRef(mPlayer.getSprite());
	alienHandler.update(dt);
	astroidHandler.update(dt);

	//colitions
	for (int i = 0; i < mPlayer.getNrOfBullets(); i++)
		for (int j = 0; j < astroidHandler.getNrOfAsteroid(); j++)
			if (mPlayer.getBulletCollision(i, astroidHandler.getASprite(j)))
			{
				//hitboxarna är lite för stora på dom stora
				std::cout << "i think it workt" << std::endl;
				astroidHandler.remove(j);
				addPoints(100);
			}

	for (int i = 0; i < astroidHandler.getNrOfAsteroid(); i++)
		if (mPlayer.getPlayerCollision(astroidHandler.getASprite(i)))
		{
			returnToUpdate = new GameOver(score);
		}
	if (alienHandler.alienExist())
	{
		for (int i = 0; i < alienHandler.getNrOfBullets(); i++)
		{
			if (alienHandler.getABulletCollision(i, mPlayer.getSprite()))
			{
				returnToUpdate = new GameOver(score);
			}
		}
		if (mPlayer.getPlayerCollision(alienHandler.getSprite()))
		{
			returnToUpdate = new GameOver(score);
		}
		for (int i = 0; i < mPlayer.getNrOfBullets(); i++)
			if (mPlayer.getBulletCollision(i, alienHandler.getSprite()))
			{
				alienHandler.remove();
				i = mPlayer.getNrOfBullets();
				addPoints(250);
			}
	}
	if (alienHandler.alienExist())
	{
		for (int i = 0; i < astroidHandler.getNrOfAsteroid(); i++)
		{
			if (astroidHandler.getAAstroidCollition(i, alienHandler.getSprite()))
			{
				alienHandler.remove();
				i = astroidHandler.getNrOfAsteroid();
			}
		}
	}
	//alien bullet calulation
	alienHandler.setAlienPlayerPosRefrens(mPlayer.getPos());

	return returnToUpdate;
}

void Game::addPoints(int points)
{
	score += points;
	std::stringstream ss;
	ss << score;
	scoreCounter.setString(ss.str());
}

void Game::handelEvent(sf::Event event)
{
}

void Game::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(mBackgroundSprite, states);
	target.draw(mPlayer, states);
	target.draw(astroidHandler, states);
	target.draw(alienHandler, states);
	target.draw(scoreCounter, states);
}