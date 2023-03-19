// Bitmap Demo 
// Copyright (c) 2021, Nguyen Minh Huy, nmhuy@fit.hcmus.edu.vn
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
// This file is only compiled on MS-Windows platform.
// Remove or comment out the file if compiling on Linux or MacOS.
//
// This file contains implementation of bmp draw on MS-Windows.
// It uses specific MS-Windows gdi32 library.
//
// * Compile on MS-Windows with MS-Visual Studio:
// 		- No need to do anything further.
//		- MS-Visual Studio automatically link to gdi32 when compiling.
//
// * Compile on MS-Windows with GCC/MSYS2:
//		- Compile with link option set to gdi32 library.
//		- Example: compile command from project root folder
//			g++ src/*cpp -o bin/bmpdemo -g -l gdi32 
// ****************************************************************
#include "BmpDraw.h"
#include <Windows.h>     // MS-Windows library for drawing.

void drawBmpByPixels(const Bmp &bmp) {
	HWND console = GetForegroundWindow();	// Get current focus window.
	HDC hdc = GetDC(console);          		// Get window screen.

	for (int i = 0; i < bmp.dib.imageHeight; ++i)
		for (int j = 0; j < bmp.dib.imageWidth; ++j) {
			Color pixel = bmp.pixelArray.pixels[i][j];

            // Draw pixel to window screen with RGB color mixer.
			SetPixel(hdc, j, i, RGB(pixel.red, pixel.green, pixel.blue));
		}

	ReleaseDC(console, hdc);
}

void drawBmpByLib(const Bmp &bmp) {
	HWND console = GetForegroundWindow(); 	// Get current focus window.
	HDC hdc = GetDC(console);          		// Get window screen.

	int w = bmp.dib.imageWidth + 1;
	int h = bmp.dib.imageHeight;
    PixelArray pa = createMovingPixelArray(bmp); // Create moving pixel array by adding blank column.
	
	BITMAPINFO bmi;                         // MS-Windows built-in struct for Bmp File.
	ZeroMemory(&bmi, sizeof(BITMAPINFO));   // This struct is used to display Pixel Array.
	bmi.bmiHeader.biWidth = w;
	bmi.bmiHeader.biHeight = h;
	bmi.bmiHeader.biBitCount = 24;
	bmi.bmiHeader.biPlanes = 1;
	bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	
	for (int i = 0; i < 500; ++i) {
		StretchDIBits(hdc, i, 0, w, h, 0, 0, w, h, pa.rawData, &bmi, DIB_RGB_COLORS, SRCCOPY);
		Sleep(0);
	}
	
	ReleaseDC(console, hdc);
}
