#ifndef GO_WINDOW_H
#define GO_WINDOW_H

#include "Math/Vectors.h"
#include "Graphics/Renderable.h"
#include "Window/WindowEvent.h"
#include <iostream>
#include <string>

struct GLFWwindow;

namespace go
{
	class Window
	{
	public:

		Window(GOuint width, GOuint height, GOcchar* title);
		Window(Vec2ui screen_size, GOcchar* title);
		~Window();

		//Getters:
		GOuint getWidth() const;
		GOuint getHeight() const;
		Vec3si getColor() const;
		GOfloat getFPS() const;
		//Setters:
		void setFPS(GOfloat FPS);
		void setColor(go::Vec3si);

		//Others:
		void pollEvent();
		GObool isClose() const;
		void clear();
		void render(go::Renderable&);
		void display();

		operator GLFWwindow*() { return m_window; }

	private:
		GObool Init();

	private:
		go::Vec3si m_colors;

	private:
		GLFWwindow* m_window;
		Vec2ui m_size;
		std::string m_title;
	private:
		GObool m_close;
		GOfloat m_aspectRatio;
		GOfloat m_FPS;
	
	
	};

}

#endif //GO_WINDOW_H