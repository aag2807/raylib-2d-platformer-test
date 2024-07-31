#ifndef SIMPLEPLATFORMER_PLAYER_H
#define SIMPLEPLATFORMER_PLAYER_H

#include <raylib.h>
#include <MacTypes.h>
#include <vector>
#include "Renderable.h"

class Player : public Renderable
{
public:
    Player();

    ~Player() override = default;

    void Render(float deltaTime) override;

    std::vector<Rectangle> GetCollidables() override;

    void CheckCollision(std::vector<Rectangle> collidables);

private:
    Rectangle playerRect{};
    Vector2 playerPosition{};
    Color playerColor{};
    float playerGravity;
    float playerJumpForce;
    bool isGrounded;
    bool isJumping;
    float verticalVelocity{};

    void Jump(float deltaTime);

    void Move(float deltaTime);

    void ApplyGravity(float deltaTime);

    void UpdatePlayerRectFromPositions();
};


#endif //SIMPLEPLATFORMER_PLAYER_H
