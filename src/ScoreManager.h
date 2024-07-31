#ifndef SIMPLEPLATFORMER_SCOREMANAGER_H
#define SIMPLEPLATFORMER_SCOREMANAGER_H

class ScoreManager
{
public:
    ~ScoreManager() = default;

    void AddScore(int scoreToAdd);

    int GetScore() const;

    static ScoreManager &GetInstance()
    {
        static ScoreManager instance;
        return instance;
    }

private:
    int score = 0;

    ScoreManager() = default;
};


#endif //SIMPLEPLATFORMER_SCOREMANAGER_H
