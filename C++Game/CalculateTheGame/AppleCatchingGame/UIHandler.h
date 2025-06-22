#pragma once
#include <SFML/Graphics.hpp>
#include <sstream>
#include <iomanip>
#include "Player.h"
#include "Score.h"

class UIHandler
{
public:
	UIHandler();

	void DrawText(sf::RenderWindow& render);

	void UpdateHealthText(int player);
	void UpdateScoreText(int score);

	void DisplayWinScreen(sf::RenderWindow& render);
	void DisplayGameOver(sf::RenderWindow& render);

private:
	sf::Font font;
	sf::Text healthText;
	sf::Text scoreText;

	int displayScore;
};

