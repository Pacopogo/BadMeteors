#include "UIHandler.h"
#include <iostream>
#include <cstdlib>

#define FONT_LOCATION_EXE "..\\Fonts\\Gameplay.ttf"
#define CONVERT_STRING(Str) std::to_string({Str})



UIHandler::UIHandler()
{
	std::string finalPath;
	std::string fontPath = FONT_LOCATION_EXE;
	char absolutePath[_MAX_PATH];
	if (_fullpath(absolutePath, fontPath.c_str(), _MAX_PATH))
	{
		finalPath = absolutePath;
	}
	else
	{
		perror("Font failed to find path");
		return;
	}

	font.loadFromFile(finalPath);
	healthText.setFont(font);
	scoreText.setFont(font);

	healthText.setPosition(270, 20);
	scoreText.setPosition(300, 70);
}

void UIHandler::DrawText(sf::RenderWindow& render)
{
	render.draw(healthText);
	render.draw(scoreText);
}

void UIHandler::UpdateHealthText(int player)
{
	healthText.setString("HP: " + CONVERT_STRING(player));
}

void UIHandler::UpdateScoreText(int score)
{
	displayScore = score;
	scoreText.setString(CONVERT_STRING(score));
}

void UIHandler::DisplayWinScreen(sf::RenderWindow& window)
{
	window.clear(sf::Color{ 150,255,150 });

	scoreText.setCharacterSize(32);
	healthText.setCharacterSize(86);

	healthText.setPosition(100, 200);
	scoreText.setPosition(140, 350);

	healthText.setString("YOU WON");
	scoreText.setString("Your score is: " + CONVERT_STRING(displayScore));


	window.draw(healthText);
	window.draw(scoreText);
}

void UIHandler::DisplayGameOver(sf::RenderWindow& window)
{
	window.clear(sf::Color{ 255,100,100 });

	scoreText.setCharacterSize(16);

	healthText.setPosition(200, 300);
	scoreText.setPosition(220, 350);

	healthText.setString("GAME OVER");
	scoreText.setString("Your score is: " + CONVERT_STRING(displayScore));


	window.draw(healthText);
	window.draw(scoreText);
}



