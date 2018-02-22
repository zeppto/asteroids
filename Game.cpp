#include "Game.hpp"
#include <iostream>

Game::Game() :mPlayer(1)
{
	if (!mBackgroundTex.loadFromFile("../Resources/background1.png"))
	{
		// Handle error: Print error message.
		std::cout << "ERROR: Background image could not be loaded.\n---" << std::endl;
	}
	mBackgroundSprite.setTexture(mBackgroundTex);
}

void Game::Update(float dt)
{
	// Make sure everything in the game is updated (if needed).
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
}

void Game::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	// Make sure everything in the game is drawn.
	target.draw(mBackgroundSprite, states);
	target.draw(mPlayer, states);
	target.draw(astroidHandler, states);
}