#include "Game.hpp"
#include <iostream>

Game::Game() :mPlayer(1)
{
	thisGameState = startMenue;

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

	//menue stuff
	if (thisGameState == startMenue)
	{
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
	}
}

void Game::Update(float dt)
{
	srand(time(NULL));

	//menu stuff
	if (thisGameState == startMenue)
	{
		//if (startButton.getGlobalBounds().intersects(sf::Mouse::getPosition())
		//startButton.setPosition((sf::Vector2f)sf::Mouse::getPosition());
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
			thisGameState = game;
	}

	if (thisGameState == game)
	{
		mPlayer.Update(dt);
		astroidHandler.setPlayerSpritRef(mPlayer.getSprite());
		alienHandler.update(dt);
		astroidHandler.update(dt);

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
	}
}

void Game::addPoints(int points)
{
	score += points;
	std::stringstream ss;
	ss << score;
	scoreCounter.setString(ss.str());
}

void Game::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	if (thisGameState == game)
	{
		target.draw(mBackgroundSprite, states);
		target.draw(mPlayer, states);
		target.draw(astroidHandler, states);
		target.draw(alienHandler, states);
		target.draw(scoreCounter, states);
	}
	//menye stuff
	if (thisGameState == startMenue)
	{
		target.draw(menyWelcome, states);
		target.draw(startButton, states);
	}
}