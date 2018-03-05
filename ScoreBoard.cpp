#include "ScoreBoard.h"
#include "Menu.h"

void ScoreBoard::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(scores, states);
	target.draw(scoreBord, states);
	target.draw(playerNamesScore, states);
	target.draw(youreScore, states);
}

ScoreBoard::ScoreBoard(int score, std::string name)
{
	this->score = score;
	this->name = name;
	timmer = 0;
	nrOfHighScores = 0;

	if (!font.loadFromFile("../Resources/Anasthesia.ttf"))
	{
		std::cout << "error no font" << std::endl;
	}

	scores.setFont(font);
	scores.setString("");
	scores.setCharacterSize(50);
	scores.setColor(sf::Color::White);
	scores.setPosition(sf::Vector2f(330, 210));

	playerNamesScore.setFont(font);
	playerNamesScore.setString("");
	playerNamesScore.setCharacterSize(50);
	playerNamesScore.setColor(sf::Color::White);
	playerNamesScore.setPosition(sf::Vector2f(1030, 210));

	youreScore.setFont(font);
	youreScore.setString("");
	youreScore.setCharacterSize(50);
	youreScore.setColor(sf::Color::White);
	youreScore.setPosition(sf::Vector2f(330, 810));

	scoreBord.setFont(font);
	scoreBord.setString("High Score");
	scoreBord.setCharacterSize(90);
	scoreBord.setColor(sf::Color::White);
	scoreBord.setPosition(sf::Vector2f(530, 50));

	writeToFile(score, name);
	playerNamesScore.setString(nameToString());
	scores.setString(scoreToString());
	youreScore.setString("Youre score: " + std::to_string(score));

}

void ScoreBoard::handelEvent(sf::Event event)
{
}

void ScoreBoard::readFromFile()
{
	std::ifstream fromFile;
	fromFile.open("highScores");

	for (int i = 0; i < nrOfTopScores + 2; i++)
	{
		if (fromFile.eof())  // check for End Of File
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

void ScoreBoard::writeToFile(int score, std::string name)
{
	readFromFile();
	if (nrOfHighScores == 0)
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

void ScoreBoard::sortInNewScore(int score, std::string name)
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

	for (int i = nrOfHighScores - 2; i >= 0; i--)
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

std::string ScoreBoard::scoreToString() const
{
	std::stringstream ss;
	for (int i = 0; i < nrOfHighScores; i++)
		ss << topScores[i] << std::endl;
	return ss.str();
}

std::string ScoreBoard::nameToString() const
{
	std::string returnString;
	for (int i = 0; i < nrOfHighScores; i++)
		returnString += topNames[i] + "\n";
	return returnString;
}


BaseState * ScoreBoard::update(float dt)
{
	timmer++;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && timmer > 300)
		return new Menu();

	return nullptr;
}
