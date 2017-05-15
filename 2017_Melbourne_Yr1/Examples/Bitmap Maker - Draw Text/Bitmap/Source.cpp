#include <iostream>
#include <fstream>

#include <Windows.h>
#include <complex>

#include "Text.h"

#define IMAGE_WIDTH 256
#define IMAGE_HEIGHT 128

#define COLOUR_CHANNELS 3
#define LINE_HEIGHT 70
#define CHAR_SPACING 1
#define LINE_SPACING 1
#define PADDING 1

int main(void)
{
	//.bmp headers
	BITMAPFILEHEADER header;
	header.bfType = 0x4D42;
	header.bfSize = IMAGE_WIDTH * IMAGE_HEIGHT * COLOUR_CHANNELS * sizeof(char);
	header.bfReserved1 = 0;
	header.bfReserved2 = 0;
	header.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

	BITMAPINFOHEADER info;
	info.biSize = sizeof(BITMAPINFOHEADER);
	info.biWidth = IMAGE_WIDTH;
	info.biHeight = -IMAGE_HEIGHT;
	info.biPlanes = 1;
	info.biBitCount = 24;
	info.biCompression = BI_RGB;
	info.biSizeImage = 0;
	info.biXPelsPerMeter = 0;
	info.biYPelsPerMeter = 0;
	info.biClrUsed = 0;
	info.biClrImportant = 0;

	//Open the file for writing
	std::fstream file("file.bmp", std::ios::out | std::ios::binary);
	if(file.good()) 
	{
		//Write the .bmp headers
		file.write((char*)&header, sizeof(BITMAPFILEHEADER));
		file.write((char*)&info, sizeof(BITMAPINFOHEADER));

		//Allocate memory for the image
		int nDataSize = IMAGE_WIDTH * IMAGE_HEIGHT * COLOUR_CHANNELS;
		unsigned char* pPixels = new unsigned char[nDataSize];
		memset(pPixels, 0, nDataSize);

		std::cout << "Enter text: (letters and spaces only)" << std::endl;
		char buffer[256];
		std::cin.getline(buffer, 256);

		int length = strlen(buffer);
		int charPerLine = IMAGE_WIDTH / (CHAR_WIDTH + CHAR_SPACING);
		
		for(int inputCharIndex = 0; inputCharIndex < length; ++inputCharIndex)
		{
			int glyphIndex;
			if(buffer[inputCharIndex] >= 'a')
				glyphIndex = (int)buffer[inputCharIndex] - (int)'a';
			else
				glyphIndex = (int)buffer[inputCharIndex] - (int)'A';

			if(glyphIndex >= 0 && glyphIndex < 26)
			{
				int line = inputCharIndex / charPerLine;
				int characterIndex = inputCharIndex % charPerLine;

				for(int charY = 0; charY < CHAR_HEIGHT; ++charY)
				{
					for(int charX = 0; charX < CHAR_WIDTH; ++charX)
					{
						int pixelIndexX = (characterIndex * (CHAR_WIDTH + CHAR_SPACING)) + charX + PADDING;
						int pixelIndexY = (line * (CHAR_HEIGHT + CHAR_SPACING)) + charY + PADDING;
						int byteIndex = ((pixelIndexY * IMAGE_WIDTH) + pixelIndexX) * COLOUR_CHANNELS;

						int colour = pixels[glyphIndex][charY][charX] * 255;
						pPixels[byteIndex] = colour;
						pPixels[byteIndex + 1] = colour;
						pPixels[byteIndex + 2] = colour;
					}
				}
			}
		}

		file.write((char*)pPixels, nDataSize);
		
		file.close();

		delete pPixels;
	}

	return EXIT_SUCCESS;
}