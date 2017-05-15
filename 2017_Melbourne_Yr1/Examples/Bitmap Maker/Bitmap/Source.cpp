#include <iostream>
#include <fstream>

#include <Windows.h>

int main(void)
{
	int nWidth = 512;
	int nHeight = 512;

	BITMAPFILEHEADER header;
	header.bfType = 0x4D42;
	header.bfSize = nWidth * nHeight * 3 * sizeof(char);
	header.bfReserved1 = 0;
	header.bfReserved2 = 0;
	header.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

	BITMAPINFOHEADER info;
	info.biSize = sizeof(BITMAPINFOHEADER);
	info.biWidth = nWidth;
	info.biHeight = -nHeight;
	info.biPlanes = 1;
	info.biBitCount = 24;
	info.biCompression = BI_RGB;
	info.biSizeImage = 0;
	info.biXPelsPerMeter = 0;
	info.biYPelsPerMeter = 0;
	info.biClrUsed = 0;
	info.biClrImportant = 0;

	//fill in the array here
	std::ofstream file("file.bmp", std::ios::out | std::ios::binary);
	if(file.good()) 
	{
		file.write((char*)&header, sizeof(BITMAPFILEHEADER));
		file.write((char*)&info, sizeof(BITMAPINFOHEADER));

		for (int j = 0; j < nHeight; ++j)
		{
			for (int i = 0; i < nWidth; ++i)
			{
				static unsigned char color[3];
				color[0] = i % 256;			// blue 
				color[1] = j % 256;			// green 
				color[2] = (i * j) % 256;	// red
				file.write((char*)&color, 3 * sizeof(char));
			}
		}

		file.close();
	}

	return EXIT_SUCCESS;
}