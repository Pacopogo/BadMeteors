#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Vector2.h"
using rectangle = sf::RectangleShape;

namespace sf {
	class RenderWindow;
}

class Player
{
public:

	Player();


	void DrawPlayer(sf::RenderWindow& render);
	
	void CheckPlayerInput();
	void ReleasePlayerInput();

	void PlayerUpdate();

	void PhysicsUpdate();
	void BorderCheck();

	void TakeDamage();

	int GetHealth();
	
	PabloPhysics::Vector2 playerPosition;
	PabloPhysics::Vector2 playerSize;


private:

	rectangle playerShape;
	
	int health;

	float speed;
	bool isMoving;

	float drag;
	float acceliration;
	float velocity;

	int direction;

};

