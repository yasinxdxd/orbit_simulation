#ifndef PHYSICS_HH
#define PHYSICS_HH

#include <Entities.hpp>

const constexpr double G_constant = 6.67 * 1;//0.00000000001;

static float Distance(go::Vec2f v1, go::Vec2f v2)
{
    auto distv = v2 - v1;
    return sqrtf((distv.x * distv.x) + (distv.y * distv.y));
}

static void TurnAround(Planet& origin, Planet& turning, float angle, float distance)
{
    go::Vec2f newPosition = {origin.m_sprite.getPosition().x + (distance * cosf(GO_D2R(angle))),
                            origin.m_sprite.getPosition().y + (distance * sinf(GO_D2R(angle)))};

    turning.m_sprite.setPosition(newPosition);
}

static void ActivateGravitionalForce(Planet& planet1, Planet& planet2)
{
    float dx = planet1.m_sprite.getPosition().x - planet2.m_sprite.getPosition().x;
    float dy = planet1.m_sprite.getPosition().y - planet2.m_sprite.getPosition().y;
    float distance = Distance(planet1.m_sprite.getPosition(), planet2.m_sprite.getPosition());

    auto Force = (float)G_constant * (planet1.mass * planet2.mass) / powf(distance, 2);
    
    planet1.acc.x = (Force / planet1.mass) * (-dx / distance);
    planet2.acc.x = (Force / planet2.mass) * (dx / distance);
    planet1.acc.y = (Force / planet1.mass) * (-dy / distance);
    planet2.acc.y = (Force / planet2.mass) * (dy / distance);    
    
}

#endif//PHYSICS_HH