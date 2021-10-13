#ifndef PHYSICS_HH
#define PHYSICS_HH

#include <Entities.hpp>

const constexpr double G_constant = 6.67 * 1;//0.00000000001;

template<typename _Type>
static _Type Distance(go::Vec2<_Type> v1, go::Vec2<_Type> v2)
{
    auto distv = v2 - v1;
    return sqrtf((distv.x * distv.x) + (distv.y * distv.y));
}

template<typename _Type>
static _Type SquaredDistance(go::Vec2<_Type> v1, go::Vec2<_Type> v2)
{
    auto distv = v2 - v1;
    return (distv.x * distv.x) + (distv.y * distv.y);
}

static void TurnAround(Planet& origin, Planet& turning, float angle, float distance)
{
    go::Vec2f newPosition = {origin.m_sprite.getPosition().x + (distance * cosf(GO_D2R(angle))),
                            origin.m_sprite.getPosition().y + (distance * sinf(GO_D2R(angle)))};

    turning.m_sprite.setPosition(newPosition);
}

static inline float CalculateForce(Planet& planet1, Planet& planet2)
{
    float squared_distance = SquaredDistance<float>(planet1.m_sprite.getPosition(), planet2.m_sprite.getPosition());
    float Force = (float)G_constant * (planet1.mass * planet2.mass) / squared_distance;
    
    return Force;
}

static void ActivateGravitionalForce(Planet& planet1, Planet& planet2)
{
    float dx = planet1.m_sprite.getPosition().x - planet2.m_sprite.getPosition().x;
    float dy = planet1.m_sprite.getPosition().y - planet2.m_sprite.getPosition().y;
    float distance = Distance<float>(planet1.m_sprite.getPosition(), planet2.m_sprite.getPosition());
    float Force = CalculateForce(planet1, planet2);
    
    planet1.acc.x = (Force / planet1.mass) * (-dx / distance);
    planet2.acc.x = (Force / planet2.mass) * (dx / distance);
    planet1.acc.y = (Force / planet1.mass) * (-dy / distance);
    planet2.acc.y = (Force / planet2.mass) * (dy / distance);     
}

static go::Vec2<go::Vec2f> ReturnGravitionalAcceleration(Planet& planet1, Planet& planet2)
{
    float dx = planet1.m_sprite.getPosition().x - planet2.m_sprite.getPosition().x;
    float dy = planet1.m_sprite.getPosition().y - planet2.m_sprite.getPosition().y;
    float distance = Distance<float>(planet1.m_sprite.getPosition(), planet2.m_sprite.getPosition());
    float Force = CalculateForce(planet1, planet2);
    
    go::Vec2f acc1, acc2;

    acc1.x = (Force / planet1.mass) * (-dx / distance);
    acc2.x = (Force / planet2.mass) * (dx / distance);
    acc1.y = (Force / planet1.mass) * (-dy / distance);
    acc2.y = (Force / planet2.mass) * (dy / distance);

    return {acc1, acc2};
}

static void ActivateGravitionalForce(std::vector<Planet*>& planets)
{
    std::vector<go::Vec2f> netacc(planets.size(), {0, 0}); //fill with zeros
    std::vector<std::vector<go::Vec2<go::Vec2f>>> arr(planets.size());
    //std::vector<std::vector<go::Vec2f>> arr(5);


    for(size_t i = 0; i < planets.size(); ++i)//planets.size()
    {
        for(size_t j = i + 1; j < planets.size(); ++j)//planets.size()
        {       
            arr[i].push_back(ReturnGravitionalAcceleration(*planets[i], *planets[j]));
            //arr[i].push_back({(float)i, (float)j});
        }
    }
    
    for(int i = 0; i < arr.size(); i++)
    {
        for(int j = 0; j < arr[i].size(); j++)
        {
            //std::cout << arr[i][j].x << "," << arr[i][j].y << "  ";
            netacc[i] += arr[i][j].x;
        }
        //std::cout << std::endl;
    }
    
    for(int i = 0; i < arr.size(); i++)//int i = arr.size() - 1; i >=0 ; i--
    {
        int in = 0;
        for(int j = arr[i].size() - 1; j >= 0 ; --j)//int j = 0; j < arr[i].size(); j++
        {
            //std::cout << arr[in][j].x << "," << arr[in][j].y << "  ";
            netacc[i] += arr[in][j].y;
            //netacc[planets.size() - i - 1] += arr[i][planets.size() - i - 1].y;
            in++;
        }
        //std::cout << std::endl;
    }

    for(int i = 0; i < planets.size(); i++)
    {
        planets[i]->acc = netacc[planets.size() - i - 1];
    }
}

#endif//PHYSICS_HH