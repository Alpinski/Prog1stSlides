#include "Application2D.h"

int main() 
{
	Application2D* app = new Application2D();
	app->run("AIE", 1280, 720, false);
	delete app;

	return 0;
}