#include <Entities.hpp>
#include <Window/Window.h>

Entity::Entity(const char* texture_path, float r, float m)
: m_texture(texture_path),
  m_sprite(m_texture),
  radius(r),
  mass(m)
{ }

Planet::Planet(const char* texture_path, float r, float m)
: Entity(texture_path, r, m)
{
    m_sprite.setPosition({300, 300});
    m_sprite.setSize({radius, radius});
    m_sprite.setOrigin({radius/2, radius/2});
    m_sprite.setRotatiton(GO_D2R(180));
}

void Planet::update()
{
    velocity += acc;
    m_sprite.setPosition(m_sprite.getPosition() + velocity);
}


void Planet::draw(go::Window& window)
{
    window.render(m_sprite);
}