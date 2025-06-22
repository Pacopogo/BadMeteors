#include "score.h"
#include <stdio.h>

Score::Score() :
	currentScore{ 0 }
{
}

void Score::AddScore()
{
	currentScore += 1;
}

void Score::SetScore(int amount)
{
	currentScore = amount;
}

int Score::GetScore()
{
	return currentScore;
}


