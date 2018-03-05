#ifndef BASESTATE_H
#define BASESTATE_H
#include <SFML\Graphics.hpp>
#include <iostream>

class BaseState : public sf::Drawable
{
public:
	virtual BaseState* update(float dt) = 0;
	virtual void handelEvent(sf::Event event) = 0;
	
private:
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const = 0;
};


#endif // !BASESTATE_H