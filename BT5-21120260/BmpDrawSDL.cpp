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
// This file can be compiled on both MS-Windows and Linux.
//
// This file contains implementation of bmp draw on both MS-Windows and Linux.
// It uses cross-platform SDL2 libary.
//
// 1. Install SDL2 library: http://wiki.libsdl.org/Installation
//
// 2. Compile with link option set to SDL2 library:
// * Compile on MS-Windows with MS-Visual Studio:
//   - Set Project dependency directories: /path/to/SDL2/lib
//   - Set Project dependency libraries: SDL2.lib
//   - Copy shared library SDL2.dll to project executable folder 
//
// * Compile on MS-Windows with GCC/MSYS2:
//   - Be sure path to shared/static library SDL2 can be found by GCC
//   - Compile with link option set to SDL2 library
//   - Example: compile from project root folder
//          g++ src/*cpp -o bin/bmpdemo -g -l SDL2
//
// * Compile on Linux with GCC:
//   - Be sure path to shared/static library SDL2 can be found by GCC
//   - Example: add to ~/.profile "export LD_LIBRARY_PATH=/usr/local/lib"
//   - Compile with link option set to SDL2 library
//   - Example: compile from project root folder
//          g++ src/*cpp -o bin/bmpdemo -g -l SDL2
//#include "BmpDraw.h"
//#include "../lib/SDLInclude/SDL.h"
//
//void drawBmpByPixels(const Bmp &bmp) {
//    SDL_Init(SDL_INIT_VIDEO);
//	SDL_Window* window = SDL_CreateWindow("Bmp Demo - Draw Bmp", 100, 100,
//                            bmp.dib.imageWidth, bmp.dib.imageHeight, SDL_WINDOW_SHOWN);
//    SDL_Renderer* render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
//
//    for (int i = 0; i < bmp.dib.imageHeight; ++i)
//		for (int j = 0; j < bmp.dib.imageWidth; ++j) {
//			Color* pixel = &bmp.pixelArray.pixels[i][j];
//
//            // Draw pixel to window screen.
//            SDL_SetRenderDrawColor(render, pixel->red, pixel->green, pixel->blue, 0);
//			SDL_RenderDrawPoint(render, j, i);
//		}
//    SDL_RenderPresent(render);
//
//    bool quit = false;
//	SDL_Event e;
//
//	while (!quit) {	
//		while (SDL_PollEvent(&e)) {
//			if (e.type == SDL_QUIT)
//				quit = true;
//		}
//	}
//
//    SDL_DestroyRenderer(render);
//    SDL_DestroyWindow(window);
//	SDL_Quit();
//}
//
//void drawBmpByLib(const Bmp &bmp) {
//    SDL_Init(SDL_INIT_VIDEO);
//	SDL_Window* window = SDL_CreateWindow("Bmp Demo - Draw Bmp", 100, 100,
//                            bmp.dib.imageWidth + 500, bmp.dib.imageHeight, SDL_WINDOW_SHOWN);
//    SDL_Renderer* render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
//    SDL_RenderPresent(render);
//
//    PixelArray pa = createMovingPixelArray(bmp); // Create moving pixel array by adding blank column.
//
//    SDL_Surface* bmpSurface = SDL_CreateRGBSurfaceWithFormatFrom(pa.rawData, 
//                                    bmp.dib.imageWidth + 1, bmp.dib.imageHeight, 24, 
//                                    pa.lineSize, SDL_PIXELFORMAT_BGR24);     
//    SDL_Texture* bmpTexture = SDL_CreateTextureFromSurface(render, bmpSurface);
//
//    SDL_Rect rect { .x = 0, .y = 0, .w = bmp.dib.imageWidth + 1, .h = bmp.dib.imageHeight };
//
//    for (int i = 0; i < 500; ++i) {
//        SDL_RenderCopyEx(render, bmpTexture, NULL, &rect, 0, NULL, SDL_FLIP_VERTICAL);
//        SDL_RenderPresent(render);
//        SDL_Delay(1);
//        rect.x++;
//    }
//
//    bool quit = false;
//	SDL_Event e;
//
//	while (!quit) {	
//		while (SDL_PollEvent(&e)) {
//			if (e.type == SDL_QUIT)
//				quit = true;
//		}
//	}
//
//    delete[] pa.rawData;
//    SDL_DestroyTexture(bmpTexture);
//    SDL_DestroyRenderer(render);
//    SDL_DestroyWindow(window);
//	SDL_Quit();
//}
