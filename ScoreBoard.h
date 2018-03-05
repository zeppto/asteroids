#ifndef SCOREBOARD_H
#define SCOREBOARD_H
#include "BaseState.h"
#include <iostream>
#include <sstream>
#include <fstream>

const int nrOfTopScores = 10;

class ScoreBoard : public BaseState
{
private:
	int score,
		timmer,
		nrOfHighScores,
		topScores[nrOfTopScores];
	std::string name,
		topNames[nrOfTopScores];
	sf::Font font;
	sf::Text scores,
		playerNamesScore,
		scoreBord,
		youreScore;

	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
public:
	ScoreBoard(int score, std::string name);

	void handelEvent(sf::Event event);
	void readFromFile();
	void writeToFile(int score, std::string name);
	void sortInNewScore(int score, std::string name);
	std::string scoreToString() const;
	std::string nameToString() const;

	BaseState * update(float dt);
};


//ska var på scorebordet
/*theHighScore.writeToFile(score, nameEnterd.getString());
playerNamesScore.setString(theHighScore.nameToString());
scores.setString(theHighScore.scoreToString());
youreScore.setString("Youre score: " + std::to_string(score));*/



#endif // !SCOREBOARD_H
