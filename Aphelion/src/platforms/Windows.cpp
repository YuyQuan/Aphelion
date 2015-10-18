#define WIN32_LEAN_AND_MEAN
#define APHELION_CLASS_NAME "Aphelion Class"

#include "../utilities/log.h"
#include "../graphics/Window.h"
#include "../graphics/opengl.h"
#include <cstdio>
#include <cstdarg>
#include <Windows.h>

#pragma comment(lib, "opengl32.lib")

namespace aphelion
{
	namespace graphics
	{
		static LRESULT CALLBACK windowProcedure(HWND hWindow,
												UINT uMessage,
												WPARAM wParameter, LPARAM lParameter);

		static HWND hWindow = NULL;
		
		static HDC hDeviceContext = NULL;

		bool Window::PlatformInitialize()
		{
			WNDCLASS windowClass = {};

			windowClass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
			windowClass.lpfnWndProc = windowProcedure;
			windowClass.hInstance = HINSTANCE();
			windowClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
			windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
			windowClass.hbrBackground = reinterpret_cast<HBRUSH>(COLOR_WINDOW + 1);
			windowClass.lpszClassName = APHELION_CLASS_NAME;

			if(!RegisterClass(&windowClass)) {
				utilities::logError("Failed to register the window class!\n");

				return false;
			}

			RECT windowRectangle = {};

			windowRectangle.right = m_width;
			windowRectangle.bottom = m_height;

			if(!AdjustWindowRect(&windowRectangle, WS_OVERLAPPEDWINDOW, FALSE)) {
				utilities::logError("Failed to adjust the window rectangle!\n");

				return false;
			}

			hWindow = CreateWindow(APHELION_CLASS_NAME, m_pTitle,
								   WS_OVERLAPPEDWINDOW,
								   CW_USEDEFAULT, CW_USEDEFAULT,
								   m_width, m_height, NULL, NULL, GetModuleHandle(NULL), NULL);

			if(!hWindow) {
				utilities::logError("Failed to create the window!\n");

				return false;
			}

			hDeviceContext = GetDC(hWindow);

			if(!hDeviceContext) {
				utilities::logError("Failed to get the device context!\n");

				return false;
			}

			PIXELFORMATDESCRIPTOR pixelFormatDescriptor = {};

			pixelFormatDescriptor.nSize = sizeof(PIXELFORMATDESCRIPTOR);
			pixelFormatDescriptor.nVersion = 1;
			pixelFormatDescriptor.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
			pixelFormatDescriptor.iPixelType = PFD_TYPE_RGBA;
			pixelFormatDescriptor.cColorBits = 32;
			pixelFormatDescriptor.cDepthBits = 16;
			pixelFormatDescriptor.cStencilBits = 8;
			pixelFormatDescriptor.iLayerType = PFD_MAIN_PLANE;

			int pixelFormat = ChoosePixelFormat(hDeviceContext, &pixelFormatDescriptor);

			if(!pixelFormat) {
				utilities::logError("Failed to choose the pixel format!\n");

				return false;
			}

			if(!SetPixelFormat(hDeviceContext, pixelFormat, &pixelFormatDescriptor)) {
				utilities::logError("Failed to set the pixel format!\n");

				return false;
			}

			HGLRC hGLContext = wglCreateContext(hDeviceContext);

			if(!hGLContext) {
				utilities::logError("Failed to create the OpenGL context!\n");

				return false;
			}

			if(!wglMakeCurrent(hDeviceContext, hGLContext)) {
				utilities::logError("Failed to set the OpenGL context!\n");
				
				return false;
			}

			ShowWindow(hWindow, SW_SHOW);
			SetForegroundWindow(hWindow);
			SetFocus(hWindow);

			return true;
		}

		void Window::PlatformUpdate()
		{
			MSG message = {};

			while(PeekMessage(&message, NULL, 0, 0, PM_REMOVE)) {
				TranslateMessage(&message);
				DispatchMessage(&message);

				if(message.message == WM_QUIT) {
					m_isOpen = false;
				}
			}
		}

		void Window::PlatformDisplay()
		{
			SwapBuffers(hDeviceContext);
		}

		void Window::PlatformDestroy()
		{
			wglMakeCurrent(NULL, NULL);

			DeleteDC(hDeviceContext);
			hDeviceContext = NULL;

			DestroyWindow(hWindow);
			hWindow = NULL;

			UnregisterClass(APHELION_CLASS_NAME, GetModuleHandle(NULL));
		}

		static LRESULT CALLBACK windowProcedure(HWND hWindow,
												UINT uMessage,
												WPARAM wParameter, LPARAM lParameter)
		{
			switch(uMessage) {
			case WM_CLOSE:
			case WM_DESTROY:
				PostQuitMessage(0);

				return 0;

			default:
				return DefWindowProc(hWindow, uMessage, wParameter, lParameter);
			}
		}
	}

	namespace utilities
	{
		void logWarning(const char* pWarning, ...)
		{
			va_list vl;

			va_start(vl, pWarning);

			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);

			vprintf(pWarning, vl);

			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

			va_end(vl);
		}

		void logError(const char* pError, ...)
		{

			va_list vl;

			va_start(vl, pError);

			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);

			vprintf(pError, vl);

			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

			va_end(vl);
		}
	}
}
