#ifndef SIMPLEPLATFORMER_COIN_H
#define SIMPLEPLATFORMER_COIN_H

#include "Collectable.h"
#include "Renderable.h"
#include "CommandQueue.h"
#include <vector>
#include <raylib.h>

class Coin : public Collectable, public Renderable
{
public:
    explicit Coin(Vector2 position);

    void Render(float deltaTime) override;

    std::vector<Rectangle> GetCollidables() override;

    void CheckCollision(std::vector<Rectangle> collidables) override;
private:

    Rectangle coinRect{};
    float radius = 20.0f;
    Vector2 coinPosition{};
    Color coinColor = GOLD;
};

#endif //SIMPLEPLATFORMER_COIN_H
