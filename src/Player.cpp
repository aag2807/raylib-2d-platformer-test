#include "Player.h"

Player::Player()
{
    SetTag("Player");
    playerRect = {20, 20, 20, 20};
    playerPosition = {400, 300};
    playerColor = RED;
    playerGravity = 800.0f;
    playerJumpForce = -400.0f;
    isGrounded = false;
    verticalVelocity = 0.0f;
}

std::vector<Rectangle> Player::GetCollidables()
{
    return std::vector<Rectangle>{playerRect};
}

void Player::Render(float deltaTime)
{
    ApplyGravity(deltaTime);
    Move(deltaTime);
    UpdatePlayerRectFromPositions();

    DrawRectangleRec(playerRect, playerColor);
}

void Player::CheckCollision(std::vector<Rectangle> collidables)
{
    isGrounded = false;
    for (Rectangle &collidable: collidables)
    {
        if (CheckCollisionRecs(playerRect, collidable))
        {
            isGrounded = true;
            playerPosition.y = collidable.y - playerRect.height;
            verticalVelocity = 0;
            break;
        }
    }
}

void Player::UpdatePlayerRectFromPositions()
{
    playerRect.y = playerPosition.y;
    playerRect.x = playerPosition.x;
}

void Player::Move(float deltaTime)
{
    if (IsKeyDown(KEY_A))
    {
        playerPosition.x -= 200 * deltaTime;
    }

    if (IsKeyDown(KEY_D))
    {
        playerPosition.x += 200 * deltaTime;
    }

    if (IsKeyDown(KEY_SPACE))
    {
        Jump(deltaTime);
    }
}

void Player::ApplyGravity(float deltaTime)
{
    if (!isGrounded)
    {
        verticalVelocity += playerGravity * deltaTime;
    }

    playerPosition.y += verticalVelocity * deltaTime;
}

void Player::Jump(float deltaTime)
{
    if (isGrounded)
    {
        verticalVelocity = playerJumpForce ;
        isGrounded = false;
    }
}