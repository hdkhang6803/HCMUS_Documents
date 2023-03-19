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
// *****************************************************
// This file contains common implementation of bmp draw.
// *****************************************************

#include "BmpDraw.h"

PixelArray createMovingPixelArray(const Bmp &bmp) {
    PixelArray pa; // contain dest data.
    int width = bmp.dib.imageWidth + 1;
    int height = bmp.dib.imageHeight;
    int depth = bmp.dib.colorDepth;

    initPixelArray(pa, width, height, depth);

    // Copy source data to dest data.
    for (int i = 0; i < height; ++i)
        for (int j = 0; j < bmp.pixelArray.lineSize; ++j) { // Copy each line.
            int sourceId = i * bmp.pixelArray.lineSize;
            int destId = i * pa.lineSize + depth / 8; // Ignore first pixel.

            pa.rawData[destId + j] = bmp.pixelArray.rawData[sourceId + j];
        }

    return pa;
}
