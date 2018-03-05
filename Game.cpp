#include "Game.hpp"
#include <iostream>

Game::Game() :mPlayer(1)
{
	thisGameState = startMenue;
	//thisGameState = gameOver;

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

	//gameOver stuff
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

	//scorebord stuff
	scores.setFont(font);
	scores.setString("");
	scores.setCharacterSize(50);
	scores.setColor(sf::Color::White);
	scores.setPosition(sf::Vector2f(330, 210));

	playerNamesScore.setFont(font);
	playerNamesScore.setString("");
	playerNamesScore.setCharacterSize(50);
	playerNamesScore.setColor(sf::Color::White);
	playerNamesScore.setPosition(sf::Vector2f(1030, 210));

	youreScore.setFont(font);
	youreScore.setString("");
	youreScore.setCharacterSize(50);
	youreScore.setColor(sf::Color::White);
	youreScore.setPosition(sf::Vector2f(330, 810));

	scoreBord.setFont(font);
	scoreBord.setString("High Score");
	scoreBord.setCharacterSize(90);
	scoreBord.setColor(sf::Color::White);
	scoreBord.setPosition(sf::Vector2f(530, 50));

}

void Game::update(float dt)
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
				thisGameState = gameOver;
			}
		if (alienHandler.alienExist())
		{
			for (int i = 0; i < alienHandler.getNrOfBullets(); i++)
			{
				if (alienHandler.getABulletCollision(i, mPlayer.getSprite()))
				{
					mPlayer.die();
					thisGameState = gameOver;
				}
			}
			if (mPlayer.getPlayerCollision(alienHandler.getSprite()))
			{
				//game over
				mPlayer.die();
				thisGameState = gameOver;
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
	//gameOver stuff
	if (thisGameState == gameOver)
	{
	}

	//highScoreBord stuff
	if (thisGameState == highScoreBord)
	{

		/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
		{
			thisGameState = startMenue;
			astroidHandler.resetNrToSpwan();
			score = 0;
			playerNamesScore.setString("");
		}*/
	}
}

void Game::addPoints(int points)
{
	score += points;
	std::stringstream ss;
	ss << score;
	scoreCounter.setString(ss.str());
}

void Game::enterPlayerName(char enterd)
{
	static std::string EnterdCaracter;

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))	
		//kan sabas om du tar bort caraktärer somm inte finns
		EnterdCaracter.pop_back();
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	{
		thisGameState = highScoreBord;
		EnterdCaracter += "/n";
		theHighScore.writeToFile(score, nameEnterd.getString());
		playerNamesScore.setString(theHighScore.nameToString());
		scores.setString(theHighScore.scoreToString());
		youreScore.setString("Youre score: " + std::to_string(score));
	}
	else
		EnterdCaracter += enterd;

	nameEnterd.setString(EnterdCaracter);
}

bool Game::isGameOverState()
{
	return thisGameState == gameOver;
}

void Game::reset()
{
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
	//gameOver stuff
	if (thisGameState == gameOver)
	{
		target.draw(gameOverText, states);
		target.draw(enterNameText, states);
		target.draw(nameEnterd, states);
	}

	if (thisGameState == highScoreBord)
	{
		target.draw(scores, states);
		target.draw(scoreBord, states);
		target.draw(playerNamesScore, states);
		target.draw(youreScore, states);
	}
}