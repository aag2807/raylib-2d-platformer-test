#ifndef SIMPLEPLATFORMER_WORLD_H
#define SIMPLEPLATFORMER_WORLD_H

#include <raylib.h>
#include <vector>
#include "Renderable.h"

struct Platform
{
    Vector2 position;
    float width;
    float height;
    float length;
    Color color;
};

class World : public Renderable
{
public :
    const char* TAG = "World";

    World(int _windowWidth, int _windowHeight);

    ~World() override;

    void Render(float deltaTime) override;

    std::vector<Rectangle> GetCollidables() override;
private:
    std::vector<Platform> platforms{};

protected:
    void BootstrapPlatform(int _windowWidth, int _windowHeight);
};


#endif //SIMPLEPLATFORMER_WORLD_H
