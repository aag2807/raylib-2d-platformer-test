#ifndef SIMPLEPLATFORMER_COLLECTABLE_H
#define SIMPLEPLATFORMER_COLLECTABLE_H

#include <vector>
#include <raylib.h>

class Collectable
{
public:
    Collectable() = default;
    ~Collectable() = default;

    virtual void Render(float deltaTime) = 0;

    virtual std::vector<Rectangle> GetCollidables() = 0;

    virtual void CheckCollision(std::vector<Rectangle> collidables) = 0;
};

#endif //SIMPLEPLATFORMER_COLLECTABLE_H
