#include "Coin.h"
#include <iostream>

Coin::Coin(Vector2 position)
{
    SetTag("Coin");
    coinPosition = position;
    coinRect = Rectangle{coinPosition.x - radius, coinPosition.y - radius, radius * 2, radius * 2};
}

void Coin::Render(float deltaTime)
{
    if (is_active)
    {
        DrawCircle(coinPosition.x, coinPosition.y, radius, coinColor);
    }
}

std::vector<Rectangle> Coin::GetCollidables()
{
    std::vector<Rectangle> collidables;
    collidables.push_back(coinRect);
    return collidables;
}

void Coin::CheckCollision(std::vector<Rectangle> collidables)
{
    if (!is_active)
    {
        return;
    }

    for (auto &collidable: collidables)
    {
        if (CheckCollisionCircleRec(coinPosition, radius, collidable))
        {
            CommandQueue::Dispatch(Command::PickUpCollectable);
            deactivate();
            return;
        }
    }
}