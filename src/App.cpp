#include <App.hpp>
#include <thread>
#include <Input/Mouse.h>

#define FAKE_TEXTURE "assets/faketexture.png"
#define TIME_HANDLER_SHOW_FPS

#include <Physics.hh>

TimeHandler::TimeHandler()
{
    using namespace std::chrono_literals;
    namespace ch = std::chrono;
    
    SetFramePerSecond(30);
    start = ch::system_clock::now();
}

TimeHandler::TimeHandler(frame_per_second fps)
{
    using namespace std::chrono_literals;
    namespace ch = std::chrono;

    SetFramePerSecond(fps);
    start = ch::system_clock::now();
}

void TimeHandler::SetFramePerSecond(frame_per_second fps)
{
    FPS = fps;
    neededmillisec  = (1.f / (float)FPS) * 1000;
}

void TimeHandler::HandleTime()
{
    using namespace std::chrono_literals;
    namespace ch = std::chrono;

    std::chrono::duration<double, std::milli> elapsed = ch::system_clock::now() - start;
    if(elapsed.count() < neededmillisec)
    {
        auto wait = neededmillisec - elapsed.count();
#ifdef TIME_HANDLER_SHOW_FPS
        std::cout << "FPS: " << (1 / wait) * 1000 << std::endl;
#endif
        std::this_thread::sleep_for(ch::duration<double, std::milli>(wait));
    }
    start = ch::system_clock::now();
}

App::App()
: m_window(1920, 1080, "Challenge!"),
  sun("assets/sun256.png", 256, 3000),
  earth("assets/earth.png", 64, 0.01),
  moon("assets/moon.png", 32, 0.0005)
{
    th.SetFramePerSecond(60);
    backgroundtex.loadFromFile("assets/bckg.jpg");
    background.setTexture(backgroundtex);
    background.setSize({1920, 1080});
}

void App::Run()
{
    float ea = 0;
    float sa = 0;
    float me_angle = 0;
    float es_angle = 0;

    sun.m_sprite.setPosition({900, 500});
    earth.m_sprite.setPosition({1200, 200});
    moon.m_sprite.setPosition({1880, 1000});

    std::vector<Planet*> planets{&sun, &earth, &moon};

    auto dist_earth_sun = Distance(earth.m_sprite.getPosition(), sun.m_sprite.getPosition());
    auto dist_moon_earth = Distance(moon.m_sprite.getPosition(), earth.m_sprite.getPosition());
    earth.velocity = {-5.1, -2.7};
    moon.velocity = {-3.1, -2.7};

    ////////////////////////////////////////////////////////////////////////////////////////////
    go::Texture arrowtex(FAKE_TEXTURE);
    go::Sprite arrow(arrowtex);
    arrow.setColor(255, 0, 0);
    arrow.setSize({Distance(earth.m_sprite.getPosition(), earth.m_sprite.getPosition() + earth.acc)*1000, 5});
    arrow.setOrigin({0, arrow.getSize().y / 2});
    //ActivateGravitionalForce(planets);

    while(!m_window.isClose())
    {
        th.HandleTime();

        m_window.pollEvent();

        earth.m_sprite.setRotatiton(GO_D2R(ea+=2));
        sun.m_sprite.setRotatiton(GO_D2R(sa+=0.5));

        auto angle = atan2(earth.acc.y, earth.acc.x);
        arrow.setSize({Distance(earth.m_sprite.getPosition(), earth.m_sprite.getPosition() + earth.acc)*1000, 5});
        arrow.setPosition(earth.m_sprite.getPosition());
        arrow.setRotatiton(angle);

        for(auto& p : planets)
            p->update();

        //if(go::Mouse::isMousePressed(go::Mouse::Left))
        {
            ActivateGravitionalForce(planets);
            //std::cout << "earth: " << earth.acc.y << std::endl;
            //std::cout << "sun:   " << sun.acc.y << std::endl;

        }

        //TurnAround(sun, earth, es_angle += 0.2f, dist_earth_sun);
        //TurnAround(earth, moon, me_angle += 3.0f, dist_moon_earth);

        m_window.clear();
        m_window.render(background);

        for(auto& p : planets)
            p->draw(m_window);

        m_window.render(arrow);
        m_window.display();   
        
    }

}