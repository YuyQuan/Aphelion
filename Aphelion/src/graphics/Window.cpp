#include "Window.h"
#include "opengl.h"
#include "../utilities/log.h"

namespace aphelion
{
	namespace graphics
	{
		Window::Window(const char* pTitle, const int width, const int height)
		{
			Create(pTitle, width, height);
		}

		Window::~Window()
		{
			Destroy();
		}

		bool Window::Create(const char* pTitle, const int width, const int height)
		{
			m_pTitle = pTitle;

			m_width = width;
			m_height = height;

			if(!PlatformInitialize()) {
				utilities::logError("Failed to create the window!\n");

				return false;
			}

			//glewExpiremental = true;
			  
			//if(glewInit() != GLEW_OK) {
			//	utilities::logError("Failed to initialize OpenGL!\n");
			//	
			//	return false;
			//}
			  
			utilities::logWarning("OpenGL %s\n", glGetString(GL_VERSION));
			
			m_isOpen = true;

			return true;
		}

		void Window::Update()
		{
			PlatformUpdate();
		}

		void Window::Display()
		{
			glClearColor(0.0f, 0.25f, 0.5f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			PlatformDisplay();
		}

		void Window::Destroy()
		{
			PlatformDestroy();
		}

		const char* Window::GetTitle() const
		{
			return m_pTitle;
		}

		const int Window::GetWidth() const
		{
			return m_width;
		}

		const int Window::GetHeight() const
		{
			return m_height;
		}

		const bool Window::IsOpen() const
		{
			return m_isOpen;
		}
	}
}
