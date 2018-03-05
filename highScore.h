#ifndef HIGHSCORE_H
#define HIGHSCORE_H
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

const int nrOfTopScores= 10;

class HighScore
{
private:
	int topScores[nrOfTopScores];
	std::string topNames[nrOfTopScores];
	int nrOfHighScores;

public:
	HighScore();

	void readFromFile();
	void writeToFile(int score, std::string name);
	void sortInNewScore( int score, std::string name);
	std::string scoreToString() const;
	std::string nameToString() const;

};


#endif // !HIGHSCORE_H

