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
// ***********************************************************
// This file contains common function prototypes for bmp draw.
// ***********************************************************

#pragma once

#include "bmp.h"

void drawBmpByPixels(const Bmp &bmp); // slow draw each pixel.
void drawBmpByLib(const Bmp &bmp);    // fast draw entire pixel array using library.
PixelArray createMovingPixelArray(const Bmp &bmp);
