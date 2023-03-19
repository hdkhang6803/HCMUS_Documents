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
// ****************************************************************************
// This file contains bitmap struct declarations and basic function prototypes.
// ****************************************************************************

#pragma once

#include <stdio.h>	// For FILE * I/O
#include <stdint.h>	// For fix-sized integer.

#pragma pack(push, 1)	// Save the current byte packing scheme,
		                // and set new 1-byte packing sheme.

struct BmpHeader {
	unsigned char signature[2];
	uint32_t fileSize;
	uint16_t reserved1;
	uint16_t reserved2;
	uint32_t pixelArrayOffset;
};

struct BmpDib {
	uint32_t dibSize;
	int32_t  imageWidth;
	int32_t  imageHeight;
	uint16_t colorPlaneCount;
	uint16_t colorDepth;
	uint32_t compressMethod;
	uint32_t pixelArraySize;
	int32_t  horizontalResolution;
	int32_t  verticalResolution;
	uint32_t colorCount;
	uint32_t importantColorCount;
};

struct Color {
	uint8_t blue;
	uint8_t green;
	uint8_t red;
};

struct ColorTable {		// No need for 24-bit bitmap
	Color*   colors;
	uint32_t length;
};

struct PixelArray {
	char     *rawData;
	int       rawDataSize;
	char      padding;
	int       lineSize;
	Color   **pixels;
};

struct Bmp {		//  Wrapper for all bitmap sections.
	BmpHeader   header;
	BmpDib	    dib;
	ColorTable	colorTable;
	PixelArray	pixelArray;
};

#pragma pack(pop)		// Revert to the default packing scheme.
int readBmpFile(const char *filename, Bmp &bmp);

void readHeader(FILE *f, Bmp &bmp);
void readDib(FILE *f, Bmp &bmp);
void readPixelArray(FILE *f, Bmp &bmp);

void printHeader(const Bmp &bmp);
void printDib(const Bmp &bmp);

void initPixelArray(PixelArray &pa, int width, int height, int depth);
void releasePixelArray(Bmp &bmp);

void copyBmp(Bmp &source, int x, int y, int w, int h, Bmp &dest);

//my funct
bool isBmpFile(const char file[]);