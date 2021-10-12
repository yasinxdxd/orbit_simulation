#ifndef ENTITIES_HPP
#define ENTITIES_HPP

namespace go
{
    class Window;
}
#include <Graphics/Sprite.h>

struct Entity
{
    Entity(const char* texture_path, float r, float m);
    virtual void update() = 0;
    virtual void draw(go::Window& window) = 0;

    float mass;
    float radius;

    go::Vec2f velocity;
    go::Vec2f acc;

    go::Sprite m_sprite;
    go::Texture m_texture;
};

class Planet : public Entity
{
public:
    Planet(const char* texture_path, float r, float m);
    
    void update() override;
    void draw(go::Window& window) override;
};

#endif//ENTITIES_HPP