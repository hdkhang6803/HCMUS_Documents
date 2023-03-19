#pragma once
#include "bmp.h"
Bmp* gridcut(Bmp bmp, int h, int w);
void Bmp_struct2file(Bmp file, FILE* f);
void createOutFile(Bmp file[], int filenum);

