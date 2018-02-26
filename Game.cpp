#include "Game.hpp"
#include <iostream>

Game::Game() :mPlayer(1)
{
	if (!mBackgroundTex.loadFromFile("../Resources/background1.png"))
	{
		std::cout << "ERROR: Background image could not be loaded.\n---" << std::endl;
	}
	mBackgroundSprite.setTexture(mBackgroundTex);

	if (!font.loadFromFile("../Resources/Anasthesia.ttf"))
	{
		std::cout << "error no font" << std::endl;
	}
	text.setFont(font);
	text.setString("0");
	text.setCharacterSize(30);
	text.setColor(sf::Color::White);
	text.setPosition(sf::Vector2f(10, 10));
	score = 0;
}

void Game::Update(float dt)
{
	srand(time(NULL));

	alienHandler.update(dt);
	mPlayer.Update(dt);
	astroidHandler.update(dt);

	for (int i = 0; i < mPlayer.getNrOfBullets(); i++)
		for (int j = 0; j < astroidHandler.getNrOfAsteroid(); j++)
			if (mPlayer.getBulletCollision(i, astroidHandler.getASprite(j)))
			{
				//hitboxarna är lite för stora på dom stora
				std::cout << "i think it workt" << std::endl;
				astroidHandler.remove(j);
			}

	for (int i = 0; i < astroidHandler.getNrOfAsteroid(); i++)
		if (mPlayer.getPlayerCollision(astroidHandler.getASprite(i)))
		{
			//game over
			mPlayer.die();
		}
	if (alienHandler.alienExist())
	{
		for (int i = 0; i < alienHandler.getNrOfBullets(); i++)
		{
			if (alienHandler.getABulletCollision(i, mPlayer.getSprite()))
			{
				mPlayer.die();
			}
		}
		if (mPlayer.getPlayerCollision(alienHandler.getSprite()))
		{
			//game over
			mPlayer.die();
		}
		for(int i = 0; i < mPlayer.getNrOfBullets(); i++)
			if (mPlayer.getBulletCollision(i,alienHandler.getSprite()))
			{
				alienHandler.remove();
				i = mPlayer.getNrOfBullets();
			}
	}

	//alien bullet calulation
	alienHandler.setAlienPlayerPosRefrens(mPlayer.getPos());

}

void Game::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(mBackgroundSprite, states);
	target.draw(mPlayer, states);
	target.draw(astroidHandler, states);
	target.draw(alienHandler, states);
	target.draw(text, states);
}