#ifndef MENU_H
#define MENU_H
#include "BaseState.h"

class Menu : public BaseState
{
private:
	sf::Font font;
	sf::Text menyWelcome,
		startButton;
	int timmer;

	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
public:
	Menu();
	void handelEvent(sf::Event event);
	BaseState* update(float dt);
};

#endif // !Menu_H

