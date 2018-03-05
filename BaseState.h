#pragma once
#include <SFML\Graphics.hpp>

class BaseState : public sf::Drawable
{
public:
	virtual void update(float dt) = 0;
	
private:
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const = 0;
};
