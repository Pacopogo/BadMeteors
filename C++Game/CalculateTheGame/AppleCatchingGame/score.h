#pragma once
class Score
{
public:

	Score();

	void AddScore();

	void SetScore(int amount);
	int GetScore();

private:
	int currentScore;
};

