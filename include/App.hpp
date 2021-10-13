#ifndef APP_HPP
#define APP_HPP

//includes
#include <Window/Window.h>
#include <Entities.hpp>

#include <chrono>
using frame_per_second = unsigned int;
struct TimeHandler
{
    TimeHandler();
    TimeHandler(frame_per_second FPS);
    
    frame_per_second FPS;
    unsigned int neededmillisec;
    std::chrono::system_clock::time_point start;

    inline void SetFramePerSecond(frame_per_second FPS);
    inline void HandleTime();
    
};

class App final
{
public:
    explicit App();

public:
    void Run();

private:
    go::Window m_window;
    
    Planet earth;
    Planet moon;
    Planet sun;

    go::Sprite background;
    go::Texture backgroundtex;

private:
    TimeHandler th;

};

#endif//APP_HPP