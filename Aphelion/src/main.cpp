#include "graphics/Window.h"
#include "graphics/opengl.h"
#include "utilities/log.h"
#include <cstdlib>

int main(int argc, char* argv[])
{
	using namespace aphelion;
	using namespace graphics;
	using namespace utilities;

	Window* window = new Window("Aphelion Window", 1280, 720);

	while(window->IsOpen()) {
		window->Clear(0.0f, 0.0f, 0.0f);

		glBegin(GL_TRIANGLES);

		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(0.0f, 0.75f);

		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex2f(-0.75f, -0.75f);

		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex2f(0.75f, -0.75f);

		glEnd();

		window->Update();
		window->Display();
	}

	window->Destroy();

	return 0;
}
