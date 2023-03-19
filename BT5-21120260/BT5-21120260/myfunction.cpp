#pragma warning (disable: 4996)
#include "myfunction.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bmp.h"
#include "BmpDraw.h"

Bmp* gridcut(Bmp bmp, int h, int w) {
	int newfile_num = h * w;
	Bmp* cutfile_list = new Bmp[newfile_num];

	int height = bmp.dib.imageHeight;
	int width = bmp.dib.imageWidth;
	int32_t small_h = height / h;
	int32_t small_w = width / w;
	int dem = 0;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			copyBmp(bmp, j * small_w, i * small_h, small_w, small_h, cutfile_list[dem]);
			drawBmpByPixels(cutfile_list[dem++]);
		}
	}
	return cutfile_list;
}
void Bmp_struct2file(Bmp file, FILE* f) {
	fwrite(&file.header, sizeof(BmpHeader), 1, f);
	fwrite(&file.dib, sizeof(BmpDib), 1, f);
	fwrite(file.pixelArray.rawData, file.pixelArray.rawDataSize, 1, f);
}
void createOutFile(Bmp file[], int filenum) {
	char temp[10];
	for (int i = 0; i < filenum; i++) {
		// Tao file moi
		char filename[100] = "bmpOut";
		itoa((i + 1), temp, 10);
		strcat(filename, temp);
		strcat(filename, ".bmp");
		//ghi vao file moi
		FILE* f = fopen(filename, "wb");
		if (!f) {
			printf("Loi tao file output thu %d!\n", i + 1);
		}
		else {
			Bmp_struct2file(file[i], f);
			fclose(f);
		}
	}
}