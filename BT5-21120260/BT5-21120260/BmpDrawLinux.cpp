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
// This file is only compiled on Linux platform.
// Remove or comment out the file if compiling on Windows.
//
// This file contains implementation of bmp draw on Linux.
// It uses specific Linux X11 library.
//
// * Compile on Linux with GCC:
//      - Compile with link option set to X11 library.
//      - Example: compile from project root folder
//          g++ src/*cpp -o bin/bmpdemo -g -l X11
// ****************************************************************
//#include "BmpDraw.h"
//#include <X11/Xlib.h>   // Linux library for drawing.
//#include <unistd.h>     // Linux library for sleep/delay.
//
//// Mix color from red, green, blue.
//int RGB(uint8_t red, uint8_t green, uint8_t blue) {
//    return blue + (green << 8) + (red << 16);
//}
//
//void drawBmpByPixels(const Bmp &bmp) {
//    // Open the display.
//    Display *dpy = XOpenDisplay(NULL);
//
//    // Cannot draw on console window in Linux.
//    // Create a new window for draw the image.
//    Window w = XCreateSimpleWindow(dpy, DefaultRootWindow(dpy), 
//        0, 0, bmp.dib.imageWidth, bmp.dib.imageHeight, 
//        0, RGB(0, 0, 0), RGB(0, 0, 0));
//
//    // Create graphics context (drawing tool) to draw on window.
//    GC gc = XCreateGC(dpy, w, 0, NULL);
//
//    // Get MapNotify events.
//    XSelectInput(dpy, w, StructureNotifyMask);
//
//    // Display window to the screen.
//    XMapWindow(dpy, w);
//
//    // Wait for the display to finish.
//    while (true) {
//	    XEvent e;
//	    XNextEvent(dpy, &e);
//	    if (e.type == MapNotify)
//            break;
//    }
//
//    // Draw the image.
//    for (int i = 0; i < bmp.dib.imageHeight; ++i)
//	    for (int j = 0; j < bmp.dib.imageWidth; ++j) {
//			Color pixel = bmp.pixelArray.pixels[i][j];
//
//            // Draw pixel to the console screen with RGB color mixer
//            XSetForeground(dpy, gc, RGB(pixel.red, pixel.green, pixel.blue));
//            XDrawPoint(dpy, w, gc, j, i);
//		}
//
//    // Update the screen with the image.
//    XFlush(dpy);
//}
//
//void drawBmpByLib(const Bmp &bmp) {
//    // Open the display.
//    Display *dpy = XOpenDisplay(NULL);
//
//    // Cannot draw on console window in Linux.
//    // Create a new window for draw the image.
//    Window w = XCreateSimpleWindow(dpy, DefaultRootWindow(dpy), 
//        0, 0, bmp.dib.imageWidth + 500, bmp.dib.imageHeight, 
//        0, RGB(0, 0, 0), RGB(0, 0, 0));
//
//    // Create graphics context (drawing tool) to draw on window.
//    GC gc = XCreateGC(dpy, w, 0, NULL);
//
//    // Get MapNotify events.
//    XSelectInput(dpy, w, StructureNotifyMask);
//
//    // Display window to the screen.
//    XMapWindow(dpy, w);
//
//    // Wait for the display to finish.
//    while (true) {
//	    XEvent e;
//	    XNextEvent(dpy, &e);
//	    if (e.type == MapNotify)
//            break;
//    }
//
//    // Create 32-bit pixel data from 24-bit pixel data.
//    // Also add blank column for moving image.
//    int width = bmp.dib.imageWidth + 1;
//    int height = bmp.dib.imageHeight;
//    char* data = new char[width * height * 4](); // initialize zero all elements.
//
//    for (int i = 0; i < height; ++i) {
//        for (int j = 1; j < width; ++j) { // ignore first column.
//            char* pixel32 = data + width * 4 * i + 4 * j;
//            Color* pixel24 = &bmp.pixelArray.pixels[i][j - 1];// width different by 1.
//
//            pixel32[0] = pixel24->blue;
//            pixel32[1] = pixel24->green;
//            pixel32[2] = pixel24->red;
//            pixel32[3] = 0;
//        }
//    }
//
//    // Create 24-bit buffer image from 32-bit pixel data.
//    // Buffer image only support 32-bit pixel data.
//    int scr = XDefaultScreen(dpy);
//    Visual* vsl = XDefaultVisual(dpy, scr);
//
//    XImage* img = XCreateImage(dpy, vsl, 24, ZPixmap, 0, data, width, height, 8, 0);
//
//    // Apply buffer image to screen.
//    for (int i = 0; i < 500; ++i) {
//        XPutImage(dpy, w, gc, img, 0, 0, i, 0, width, height);
//        usleep(500);
//    }
//
//    delete[] data;
//}
