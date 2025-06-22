#include "Player.h"
#include "Vector2.h"

#include <SFML/Window.hpp>

//Control player with arrow keys.
//Move with forces and frictions
//add collision check

using namespace PabloPhysics;


#define A_BUTTON sf::Keyboard::Key::A
#define D_BUTTON sf::Keyboard::Key::D

#define PLAYER_COLOR sf::Color{ 100,190,100}

Player::Player() :
	playerPosition{ 300,400 },
	playerSize{ 50,50 },
	playerShape{ V_Convert(playerSize) },
	speed{ 2 },
	isMoving{ false },
	drag{ 0.2 },
	acceliration{ 0.4 },
	velocity{ 0 },
	direction{ 0 },
	health{ 5 }
{
	playerShape.setPosition(V_Convert(playerPosition));
	playerShape.setFillColor(PLAYER_COLOR);
}

void Player::DrawPlayer(sf::RenderWindow& render)
{
	render.draw(playerShape);
}

void Player::PlayerUpdate()
{
	playerPosition.x += direction * velocity;
	playerShape.setPosition(V_Convert(playerPosition));

	BorderCheck();
	PhysicsUpdate();
}

void Player::PhysicsUpdate()
{

	if (isMoving == false && velocity > 0)
	{
		velocity -= drag;

		if (velocity <= 0)
			velocity = 0;
	}

}

void Player::BorderCheck()
{
	if (playerPosition.x > 600 + (playerSize.x / 2))
		playerPosition.x = 0 - (playerSize.x / 2);

	if (playerPosition.x < 0 - (playerSize.x / 2))
		playerPosition.x = 600 + (playerSize.x / 2);
}

void Player::TakeDamage()
{
	health -= 1;
}

int Player::GetHealth()
{
	return health;
}

void Player::CheckPlayerInput()
{

	if (velocity < 15)
	{
		velocity += acceliration;
	}

	if (sf::Keyboard::isKeyPressed(A_BUTTON)) {
		direction = -1;
	}
	else if (sf::Keyboard::isKeyPressed(D_BUTTON)) {
		direction = 1;
	}
	else
	{
		isMoving = false;
		return;
	}


	isMoving = true;
}

void Player::ReleasePlayerInput()
{
	isMoving = false;
}

