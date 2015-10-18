#include "graphics/Window.h"
#include "utilities/log.h"
#include <cstdlib>

int main(int argc, char* argv[])
{
	using namespace aphelion;
	using namespace graphics;
	using namespace utilities;

	Window* window = new Window("Aphelion Window", 1280, 720);

	while(window->IsOpen()) {
		window->Update();
		window->Display();
	}

	window->Destroy();

	system("PAUSE");

	return 0;
}
