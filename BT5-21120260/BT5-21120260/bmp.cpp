// Bitmap Demo 
// Copyright (c) 2015, Nguyen Minh Huy, nmhuy@fit.hcmus.edu.vn
//
// This software is provided 'as-is', without any implied warranty.
// The authors will not be held liable for any damages arising from
// the use of this software.
//
// Permission is granted to anyone to use, alter, and redistribute
// this software freely, subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
// 2. This notice may not be removed or altered from any source distribution.
//
// *********************************************************************
// This file contains basic function implementation (no drawing here!!).
// *********************************************************************
#pragma warning (disable: 4996)
#include "bmp.h"

bool isBmpFile(const char file[]) {
	FILE* f = fopen(file, "rb");
	if (!f)
		return false;

	BmpHeader header;
	fseek(f, 0, SEEK_SET);		// Read from the beginning.
	fread(header.signature, sizeof(header.signature), 1, f);

	return (header.signature[0] == 'B' && header.signature[1] == 'M');
}

int readBmpFile(const char *filename, Bmp &bmp) {
	FILE* f = fopen(filename, "rb");
	if (!f || !isBmpFile(filename)) {
		printf("Error: cannot open or invalid bmp file.\n");
		return 0;
	}

	readHeader(f, bmp);
	readDib(f, bmp);
	readPixelArray(f, bmp);

	fclose(f);
	return 1;
}

void readHeader(FILE *f, Bmp &bmp) {
	if (!f)
		return;

	fseek(f, 0, SEEK_SET);		// Read from the beginning.
	fread(&bmp.header, sizeof(BmpHeader), 1, f);
}

void readDib(FILE *f, Bmp &bmp) {
	if (!f)
		return;

	fseek(f, sizeof(BmpHeader), SEEK_SET);	// Skip the header.
	fread(&bmp.dib, sizeof(BmpDib), 1, f);
}

void printHeader(const Bmp &bmp) {
	BmpHeader header = bmp.header;

	printf("*** BMP Header ***\n");
	printf("- File Size         : %d byte(s)\n", header.fileSize);
	printf("- Reserved1         : %d\n",         header.reserved1);
	printf("- Reserved2         : %d\n",         header.reserved2);
	printf("- Pixel Array Offset: %d byte(s)\n", header.pixelArrayOffset);
}

void printDib(const Bmp &bmp) {
	BmpDib dib = bmp.dib;

	printf("\n*** BMP Dib ***\n");
	printf("- DIB Size              : %d byte(s)\n", dib.dibSize);
	printf("- Image Width           : %d\n",         dib.imageWidth);
	printf("- Image Height          : %d\n",         dib.imageHeight);
	printf("- Number of Color Planes: %d\n",         dib.colorPlaneCount);
	printf("- Color Depth           : %d bit(s)\n",  dib.colorDepth);
	printf("- Compress Method       : %d\n",         dib.compressMethod);
	printf("- Pixel Array Size      : %d byte(s)\n", dib.pixelArraySize);
	printf("- Horizontal Resolution : %d\n",         dib.horizontalResolution);
	printf("- Vertical Resolution   : %d\n",         dib.verticalResolution);
	printf("- Number of Colors      : %d\n",         dib.colorCount);
	printf("- Number of Impt Colors : %d\n",         dib.importantColorCount);
}

void readPixelArray(FILE *f, Bmp &bmp) {
	if (!f)
		return;

	initPixelArray(bmp.pixelArray, bmp.dib.imageWidth, bmp.dib.imageHeight, bmp.dib.colorDepth);

	fseek(f, bmp.header.pixelArrayOffset, SEEK_SET);	// Jump to the Pixel Array section.
	fread(bmp.pixelArray.rawData, bmp.pixelArray.rawDataSize, 1, f); // Read raw pixel data.
}

void initPixelArray(PixelArray &pa, int width, int height, int depth) {
	int widthSize = width * (depth / 8);    // Calculate pixel array information.
	pa.padding = (4 - (widthSize % 4)) % 4;
	pa.lineSize = widthSize + pa.padding;

	pa.rawDataSize = pa.lineSize * height;  // Initialize raw pixel data.
	pa.rawData = new char[pa.rawDataSize]();// All elements set to zero.

	pa.pixels = new Color *[height];        // Initialize pixel matrix.
	for (int i = 0; i < height; ++i)        // Matrix line points to pixel raw data.
		pa.pixels[i] = (Color *)(pa.rawData + pa.lineSize * (height - 1 - i));
}

void releasePixelArray(Bmp &bmp) {
	delete[] bmp.pixelArray.pixels;
	delete[] bmp.pixelArray.rawData;

    bmp.pixelArray.pixels = NULL;
    bmp.pixelArray.rawData = NULL;
}

void copyBmp(Bmp &source, int x, int y, int w, int h, Bmp &dest) {
    dest.header = source.header;
    dest.dib = source.dib;

    dest.dib.imageWidth = w;
    dest.dib.imageHeight = h;
    
    initPixelArray(dest.pixelArray, w, h, source.dib.colorDepth);

    Color **sPixels = source.pixelArray.pixels;
    Color **dPixels = dest.pixelArray.pixels;

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j)
            dPixels[i][j] = sPixels[y + i][x + j];
    }
}

