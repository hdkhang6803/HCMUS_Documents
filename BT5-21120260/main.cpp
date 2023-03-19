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
// ****************************************************************
// This file contains entry point and demonstration of Bitmap Demo.
// ****************************************************************
#pragma warning(disable:4996)
#include "bmp.h"
#include "BmpDraw.h"
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include "myfunction.h"


//#define BMP_SOURCE		"colors.bmp"

void changeBmp(Bmp &bmp) {
	for (int i = 0; i < bmp.dib.imageHeight; ++i)
		for (int j = 0; j < bmp.dib.imageWidth; ++j) {
			Color *c = &bmp.pixelArray.pixels[i][j];
            //Color *d = &bmp.pixelArray.pixels[i - i % 8][j - j % 8];
			c->red = c->red; 
			c->green = c->green;
			c->blue = c->blue;
		}
}

int main(int argc, char **argv) {
	Bmp bmpSource;
	int sophancat = 0;
	Bmp* list = NULL;
	int FLAG = 0;
	if (argc == 4 && strcmp(argv[2], "-h") == 0 && isBmpFile(argv[1])) {
		if (readBmpFile(argv[1], bmpSource)) FLAG = 1;
		sophancat = atoi(argv[3]);
		list = gridcut(bmpSource, atoi(argv[3]), 1);
	}
	else if (argc == 6 && strcmp(argv[2], "-h") == 0 && strcmp(argv[4], "-w") == 0 && isBmpFile(argv[1])) {
		if (readBmpFile(argv[1], bmpSource)) FLAG = 1;
		sophancat = atoi(argv[3]) * atoi(argv[5]);
		list = gridcut(bmpSource, atoi(argv[3]), atoi(argv[5]));
	}
	else {
		printf("Khong hop le!\n");
		printf("Vui long nhap dung cu phap:\n");
		printf("<ten file exe> <file bitmap> -h <chi so cat doc> -w <chi so cat ngang>\n");
	}
	if (FLAG == 1){
		printHeader(bmpSource);
		printDib(bmpSource);
		createOutFile(list, sophancat);
		releasePixelArray(bmpSource);
		for (int i = 0; i < sophancat; i++) {
			releasePixelArray(list[i]);
		}
	}
}
