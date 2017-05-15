#include <iostream>
#include <fstream>

#include "ImageBuilder.h"
#include "Music.h"

int main(void)
{
	Music_MarioStarTheme();
	Music_MariosTheme();
	Music_NewSound();

	system("pause");
	return EXIT_SUCCESS;     
}