#ifndef GRAPHIC_H
#define GRAPHIC_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <errno.h>
#include <string.h>

#define WIDTH 800
#define HEIGHT 600

#define COLS 8
#define ROWS 6
#define CELL_WIDTH  (WIDTH/COLS)
#define CELL_HEIGHT (HEIGHT/ROWS)

#define return_defer(value) do{ result = value; goto defer; }while(0)

static uint32_t pixels[WIDTH * HEIGHT];

// 0xAABBGGRR
#define BACKGROUND_COLOR 0xFF202020
#define RED 0xFF0000FF
#define GREEN 0xFF00FF00

typedef int Errno;

void graphic_fill(uint32_t* pixels, size_t width, size_t height, uint32_t color);
void graphic_fill_rect(uint32_t * pixels, size_t pixels_width, size_t pixels_height, 
	int x, int y, size_t w, size_t h, uint32_t color);

Errno graphic_save_to_ppm_file(uint32_t* pixels, size_t width, size_t height, const char* file_path);

#endif // !GRAPHIC_H
