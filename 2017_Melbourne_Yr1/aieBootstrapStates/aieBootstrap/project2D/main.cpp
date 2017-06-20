#include "Application2D.h"
#include <crtdbg.h>
int main() 
{
	Application2D* app = new Application2D();
	_ASSERT(app);
	app->run("AIE", 1280, 720, false);
	delete app;

	return 0;
}