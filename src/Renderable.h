#ifndef SIMPLEPLATFORMER_RENDERABLE_H
#define SIMPLEPLATFORMER_RENDERABLE_H

class Renderable
{
public:
    virtual void Render(float deltaTime) = 0;

    virtual ~Renderable() = default;

    virtual std::vector<Rectangle> GetCollidables() = 0;

    void deactivate()
    {
        is_active = false;
    }
public:
    char *GetTag()
    {
        return _tag;
    }
protected:
    char *_tag;
    bool is_active = true;

    void SetTag(char *tag)
    {
        _tag = tag;
    }
};

#endif //SIMPLEPLATFORMER_RENDERABLE_H
