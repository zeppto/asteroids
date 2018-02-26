#ifndef ALIENHANDELER_H
#define ALIENHANDELER_H
#include "Alien.hpp"

class AlienHandeler : public sf::Drawable
{
private:
	//se till att den int gör minnes läckor
	Alien * aAlien;
	int alienSpwanTimer;

	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
public:
	AlienHandeler();
	~AlienHandeler();
	AlienHandeler(const AlienHandeler& other);
	AlienHandeler& operator=(const AlienHandeler& other);

	void alienSpwaner();
	void remove();
	bool alienExist();
	void setAlienPlayerPosRefrens(sf::Vector2f playerPos);
	sf::Sprite getSprite() const;
	bool getABulletCollision(int index, sf::Sprite collider);
	int getNrOfBullets() const;

	void update(float dt);
};




#endif // !ALIENHANDELER_H

