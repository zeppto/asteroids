#ifndef GAME_HPP
#define GAME_HPP

#include <SFML\Graphics.hpp>
#include "Player.hpp"
#include "BigAsteroid.h"
#include "MediumAsteroid.h"
#include "AsteroidHandler.h"
#include "AlienHandeler.h"
#include <sstream>

class Game : public sf::Drawable
{
public:
	Game();

	void Update(float dt);
	void addPoints(int points);

private:
	//vet inte var man sätter enums -_-
	enum gameState { startMenue, game, gameOver };
	sf::Texture mBackgroundTex;
	sf::Sprite mBackgroundSprite;
	Player mPlayer;
	AlienHandeler alienHandler;
	AsteroidHandler astroidHandler;
	sf::Text scoreCounter,
		menyWelcome,
		startButton;
	sf::Font font;
	int score;
	gameState thisGameState;

	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};
#endif