#include "highScore.h"

HighScore::HighScore()
{
	nrOfHighScores = 0;
}

void HighScore::readFromFile()
{
	std::ifstream fromFile;
	fromFile.open("highScores");

	for (int i = 0; i < nrOfTopScores + 2; i++)
	{
		if (fromFile.eof())                  // check for End Of File
		{
			nrOfHighScores = i - 1;
			i = nrOfTopScores + 2;
		}
		else
		{
			fromFile >> topNames[i];
			fromFile >> topScores[i];
		}
	}
	fromFile.close();
	////plan
	////först hämmta top tio (allt som ska finnas på filen);
	////om spelaren har ett highScore ska den sorteras så att bara top 10 skrivs in i rätt ordning
	////10 stor array
}

void HighScore::writeToFile(int score, std::string name)
{
	readFromFile();
	if(nrOfHighScores == 0)
		sortInNewScore(score, name);
	else if (score >= topScores[nrOfHighScores - 1] || nrOfHighScores < nrOfTopScores)
	{
		sortInNewScore(score, name);
	}

	std::ofstream toFile;
	toFile.open("highScores");

	for (int i = 0; i < nrOfHighScores; i++)
	{
		toFile << topNames[i] << std::endl;
		toFile << topScores[i] << std::endl;
	}
	toFile.close();
}

void HighScore::sortInNewScore(int score, std::string name)
{
	if (nrOfHighScores == nrOfTopScores)
	{
		topScores[nrOfHighScores - 1] = score;
		topNames[nrOfHighScores - 1] = name;
	}
	else
	{
		topScores[nrOfHighScores] = score;
		topNames[nrOfHighScores] = name;
		nrOfHighScores++;
	}

	for (int i = nrOfHighScores-2; i >= 0; i--)
	{
		if (topScores[i + 1] > topScores[i])
		{
			std::swap(topScores[i + 1], topScores[i]);
			std::swap(topNames[i + 1], topNames[i]);
		}
		else
		{
			i = -1;
		}
	}
}

std::string HighScore::scoreToString() const
{
	std::stringstream ss;
	for (int i = 0; i < nrOfHighScores; i++)
		ss << topScores[i] << std::endl;
	return ss.str();
}

std::string HighScore::nameToString() const
{
	std::string returnString;
	for (int i = 0; i < nrOfHighScores; i++)
		returnString += topNames[i] + "\n";
	return returnString;
}

