#include "ScoreManager.h"

void ScoreManager::AddScore(int scoreToAdd)
{
    score += scoreToAdd;
}

int ScoreManager::GetScore() const
{
    return score;
}

