#include <raylib.h>
#include "src/World.h"
#include "src/Player.h"
#include "src/Coin.h"

const int WIDTH = 800;
const int HEIGHT = 600;
const int TARGET_FPS = 60;

int main()
{
    InitWindow(WIDTH, HEIGHT, "Platformer");
    SetTargetFPS(TARGET_FPS);

    auto world = new World(WIDTH, HEIGHT);
    auto player = new Player();

    auto coin = new Coin{Vector2{40, 400}}; // Center of the screen

    while (!WindowShouldClose())
    {
        float dt = GetFrameTime();
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Platformer", 10, 10, 20, DARKGRAY);
        std::string text = "Score: " + std::to_string(ScoreManager::GetInstance().GetScore());
        DrawText(text.c_str(), 10, 30, 20, DARKGRAY);

        world->Render(dt);
        coin->Render(dt);

        player->CheckCollision(world->GetCollidables());
        player->Render(dt);
        coin->CheckCollision(player->GetCollidables());

        CommandQueue::Process();

        EndDrawing();
    }

    return 0;
}
