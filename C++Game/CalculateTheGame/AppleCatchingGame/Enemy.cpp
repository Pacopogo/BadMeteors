#include "Enemy.h"

//enemy that moves side to side
//spawns at top (maybe use an enemy spawner for that
//Move with forces and frictions

#define ENEMY_COLOR sf::Color{ 190,100,100}

#define ENEMY_Y_TOP player.playerPosition.y - (player.playerSize.y * 0.75)
#define ENEMY_Y_BOTTOM player.playerPosition.y + (player.playerSize.y * 0.75)

Enemy::Enemy() :
	position{ 0,0 },
	size{ 50,50 },
	EnemyShape{ V_Convert(size) },

	xOrigin{ 0 },
	xDirection{ false },

	moveRange{ 50 },

	force{ 0.1 },
	acceliration{ 0.1 },
	velocity{ 0 },
	startVelocity{ 0 }
{
	EnemyShape.setPosition(V_Convert(position));
	EnemyShape.setFillColor(ENEMY_COLOR);
}

void Enemy::DrawEnemy(sf::RenderWindow& render)
{
	render.draw(EnemyShape);
}

void Enemy::Inizialize()
{
	position.x = rand();

	if (position.x < 50 || position.x > 550)
	{
		Inizialize();
		return;
	}

	xOrigin = position.x;
	position.y = 0 - size.y;

	velocity = startVelocity;
	startVelocity += acceliration * 2;

	//printf("\npos: %f", startVelocity);
}

void Enemy::Move()
{
	velocity += acceliration;
	position.y += velocity;

	if (position.x > xOrigin + moveRange) 
	{
		xDirection = true;
	}
	if (position.x < xOrigin - moveRange) 
	{
		xDirection = false;
	}

	if (xDirection) 
	{
		position.x -= startVelocity;
	}
	else
	{
		position.x += startVelocity;
	}

	EnemyShape.setPosition(V_Convert(position));
}

bool Enemy::ColliderCheck(Player player)
{
	bool isColided = false;

	float boundLeft = player.playerPosition.x - player.playerSize.x;
	float boundRight = player.playerPosition.x + player.playerSize.x;

	if (position.x >= boundRight || position.x <= boundLeft)
	{

		isColided = false;
	}
	else
	{
		if (position.y >= ENEMY_Y_TOP && position.y <= ENEMY_Y_BOTTOM)
		{
			isColided = true;
			Inizialize();
		}
	}

	return isColided;
}

bool Enemy::BorderCheck()
{
	bool isBottom;

	if (position.y > 700)
	{
		isBottom = true;
		Inizialize();
	}
	else
	{
		isBottom = false;
	}

	return isBottom;
}
