#pragma once

#include <SFML/Graphics.hpp>

#include <string>
#include <iostream>

#include "ScoreManager.h"

class ScoreManager
{
	sf::Font font;
	sf::Text scoretxt;
	sf::Text overtxt;

	std::string scorestr;

	int score;

	bool gameover;

public:
	ScoreManager();

	void reset();
	void incrementScore();
	void gameOver();
	void draw(sf::RenderWindow& win);
};

