
//Meteor bad is a parachute panic inspired game
//You have to dodge the red cubes and get to 100 points

#include <vld.h>
#include <iostream>
#include <optional>
#include <vector>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Player.h"
#include "Enemy.h"
#include "UIHandler.h"
#include "Score.h"

#define BACKGROUND_COLOR sf::Color{100,100,190}

int main()
{
	printf("START\n");

	sf::RenderWindow window(sf::VideoMode({ 600, 700 }), "Meteor bad");
	printf("render done\n");

	sf::Event event;

	UIHandler uiHandler;

	Score score;

	Player player;

	std::vector<Enemy> enemy;
	enemy.resize(5);
	
	window.setFramerateLimit(60);

	for (size_t i = 0; i < 5; i++)
	{
		enemy[i] = Enemy{};
		enemy[i].Inizialize();
	}


	while (window.isOpen())
	{
		window.clear(BACKGROUND_COLOR);

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::KeyPressed:

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
					window.close();

				player.CheckPlayerInput();
				break;

			case sf::Event::KeyReleased:
				player.ReleasePlayerInput();
				break;

			default:
				break;
			}
		}

		if (score.GetScore() >= 100)
		{
			score.SetScore(100);
			uiHandler.UpdateScoreText(score.GetScore());
			uiHandler.DisplayWinScreen(window);
			window.display();
			continue;
		}


		if (player.GetHealth() <= 0) 
		{
			uiHandler.DisplayGameOver(window);
			window.display();
			continue;
		}

		//Game Update
		player.PlayerUpdate();
		player.DrawPlayer(window);
		uiHandler.UpdateHealthText(player.GetHealth());
		uiHandler.UpdateScoreText(score.GetScore());
		uiHandler.DrawText(window);

		for (size_t i = 0; i < 5; i++)
		{
			enemy[i].Move();
			enemy[i].DrawEnemy(window);

			if (enemy[i].BorderCheck())
				score.AddScore();

			if (enemy[i].ColliderCheck(player))
				player.TakeDamage();
		}

		window.display();
	}

	enemy.clear();

	//delete window;
	window.close();


	return 0;
}


