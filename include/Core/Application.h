#ifndef GO_APPLICATION_H
#define GO_APPLICATION_H

#define GLFW_INCLUDE_NONE

#include "Definitions.h"
#include "Window/Window.h"
#include "Graphics/Shader.h"
#include "Graphics/Sprite.h"
#include "Graphics/Text.h"
#include "Input/Mouse.h"
#include "Input/Keyboard.h"
#include "Audio/SoundBuffer.h"
#include "Audio/SoundSource.h"
/*----------------------------------*/
/*----------------------------------*/
#include <chrono>
#include <thread>
#include <exception>


namespace go
{
	class Application
	{
	public:
	
		virtual void Start() = 0;
		virtual void Update() = 0;
		virtual void Draw() = 0;
		virtual void Destroy() = 0;

	public:

		virtual void GO()
		{
			GOuint start, delta = 1;
			float delay;


			Start();

			while (!window->isClose())
			{
				start = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
				/////////////////////////////////////////////////////////////////////

				window->pollEvent();

				Update();

				window->clear();
				Draw();
				window->display();

				/////////////////////////////////////////////////////////////////////
				delay = (1000 / window->getFPS()) - delta;
				if (delay > 0)
				{
					std::this_thread::sleep_for(std::chrono::milliseconds((int(delay))));
					//std::cout << 1000 / delta << std::endl;
				}

				delta = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() - start;
			}

			Destroy();


		}

	protected:
		Window* window;
	};
}


#endif // GO_APPLICATION_H