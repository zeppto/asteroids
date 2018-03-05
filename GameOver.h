#ifndef GAMEOVER_H
#define GAMEOVER_H
#include "BaseState.h"

class GameOver : public BaseState
{
private:
	int score;
	std::string EnterdCaracter;
	sf::Font font;
	sf::Text gameOverText,
		enterNameText,
		nameEnterd;
	BaseState* returnForUpdate;

	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
public:
	GameOver(int score);

	void handelEvent(sf::Event event);
	void enterPlayerName(char enterd);
	BaseState * update(float dt);
};

#endif // !GameOver_H
