#include "World.h"

World::World(int _windowWidth, int _windowHeight)
{
    SetTag(const_cast<char *>(TAG));
    BootstrapPlatform(_windowWidth, _windowHeight);
}

void World::BootstrapPlatform(int _windowWidth, int _windowHeight)
{
    const int bottom = _windowHeight - 20;
    platforms.push_back(
            Platform{Vector2{0, static_cast<float>(bottom)}, static_cast<float>(_windowWidth), 20.0f, 2.0f, BROWN}
    );

    platforms.push_back(
            Platform{Vector2{0, static_cast<float>(bottom - 50)}, 100.0f, 20.0f, 2.0f, BROWN}
    );

    platforms.push_back(
            Platform{Vector2{200, static_cast<float>(bottom - 100)}, 100.0f, 20.0f, 2.0f, BROWN}
    );

    platforms.push_back(
            Platform{Vector2{400, static_cast<float>(bottom - 150)}, 100.0f, 20.0f, 2.0f, BROWN}
    );

    platforms.push_back(
            Platform{Vector2{600, static_cast<float>(bottom - 200)}, 100.0f, 20.0f, 2.0f, BROWN}
    );
}

World::~World()
{
    platforms.clear();
    delete this;
}

std::vector<Rectangle> World::GetCollidables()
{
    std::vector<Rectangle> collidables;
    for (auto &platform: platforms)
    {
        collidables.push_back(Rectangle{platform.position.x, platform.position.y, platform.width, platform.height});
    }
    return collidables;

}

void World::Render(float deltaTime)
{
    for (auto &platform: platforms)
    {
        DrawRectangle(static_cast<int>(platform.position.x), static_cast<int>(platform.position.y),
                      static_cast<int>(platform.width), static_cast<int>(platform.height), platform.color);
    }
}

