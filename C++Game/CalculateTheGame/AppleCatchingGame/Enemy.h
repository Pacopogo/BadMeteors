#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Vector2.h"
#include "Player.h"
#include "Score.h"

using rectangle = sf::RectangleShape;

namespace sf {
	class RenderWindow;
}

class Enemy
{
public:

	Enemy();

	void DrawEnemy(sf::RenderWindow& render);

	void Inizialize();
	void Move();

	bool ColliderCheck(Player player);
	bool BorderCheck();

	PabloPhysics::Vector2 position;
	PabloPhysics::Vector2 size;

	float velocity;

private:

	rectangle EnemyShape;

	bool xDirection;

	float xOrigin;
	float moveRange;

	float force;
	float acceliration;
	float startVelocity;
};

