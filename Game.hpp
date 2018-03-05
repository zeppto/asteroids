#ifndef GAME_HPP
#define GAME_HPP

#include <SFML\Graphics.hpp>
#include "Player.hpp"
#include "BigAsteroid.h"
#include "MediumAsteroid.h"
#include "AsteroidHandler.h"
#include "AlienHandeler.h"
#include "highScore.h"
#include <sstream>
#include "BaseState.h"

class Game : public BaseState
{
public:
	Game();

	void update(float dt);
	void addPoints(int points);
	void enterPlayerName(char enterd);
	bool isGameOverState();
	void reset();

private:
	//vet inte var man sätter enums -_-
	enum gameState { startMenue, game, gameOver, highScoreBord };
	sf::Texture mBackgroundTex;
	sf::Sprite mBackgroundSprite;
	Player mPlayer;
	AlienHandeler alienHandler;
	AsteroidHandler astroidHandler;
	HighScore theHighScore;
	sf::Text scoreCounter,
		menyWelcome,
		startButton,
		gameOverText,
		enterNameText,
		nameEnterd,
		scores,
		playerNamesScore,
		scoreBord,
		youreScore;
	sf::Font font;
	int score;
	gameState thisGameState;
	std::string playerName;

	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};
#endif