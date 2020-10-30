#include "ScoreManager.h"


ScoreManager::ScoreManager() : score(0), gameover(false) {
	if (!font.loadFromFile("Fonts/Roboto-Light.ttf"))
		std::cout << "ERROR: Font not found";
	
	scorestr = "Score: " + std::to_string(score);

	scoretxt.setFont(font);
	scoretxt.setString(scorestr);
	scoretxt.setFillColor(sf::Color::White);
}

void ScoreManager::incrementScore() {
	score++;
}

void ScoreManager::reset() {
	int oldScore = score;
	overtxt.setString("gg ur ded\n Score: " + std::to_string(oldScore));
	overtxt.setFont(font);
	overtxt.setFillColor(sf::Color::White);
	overtxt.setPosition(350, 250);
	overtxt.setScale(1.5f, 1.5f);
}

void ScoreManager::gameOver() {
	gameover = true;
}

void ScoreManager::draw(sf::RenderWindow& win) {
	scorestr = "Score: " + std::to_string(score);
	scoretxt.setString(scorestr);
	
	if (gameover)
		win.draw(overtxt);
	else 
		win.draw(scoretxt);
}