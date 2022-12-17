#include "graphic.h"

void graphic_fill(uint32_t* pixels, size_t width, size_t height, uint32_t color) {
	for (size_t i = 0; i < width * height; i++) {
		pixels[i] = color;
	}
	/*for (size_t y = 0; y < height; y++) {
		for (size_t x = 0; x < width; x++) {
			pixels[y*width + x] =
		}
	}*/
}

void graphic_fill_rect(uint32_t* pixels, size_t pixels_width, size_t pixels_height, 
	int x0, int y0, size_t w, size_t h, uint32_t color) 
{
	for (size_t dy = 0; dy < h; dy++) {
		size_t y = y0 + dy;
		if (0 <= y && y < pixels_height) {
			for (size_t dx = 0; dx < w; dx++) {
				size_t x = x0 + dx;
				if (0 <= x && x < pixels_width) {
					pixels[y * pixels_width + x] = color;
				}
			}
		}
		
	}
}

void graphic_fill_circle(uint32_t* pixels, size_t pixels_width, size_t pixels_height,
	int x0, int y0, size_t r, uint32_t color) 
{
	// Trick: take a rectangle and iterate in each pixel to check if it is in the circle.
	int x1 = x0 - (int)r;
	int y1 = y0 - (int)r;
	int x2 = x0 + (int)r;
	int y2 = y0 + (int)r;

	for (int x = x1; x <= x2; x++) {
		for (int y = y1; y <= y2; y++) {

		}
	}

}

Errno graphic_save_to_ppm_file(uint32_t* pixels, size_t width, size_t height, const char* file_path) {
	int result = 0;
	FILE* f = NULL;

	{
		f = fopen(file_path, "wb");
		if (f == NULL) return_defer(errno);

		fprintf(f, "P6\n%zu %zu 255\n", width, height);
		if (ferror(f)) return_defer(errno);
		for (size_t i = 0; i < width * height; i++) {
			uint32_t pixel = pixels[i];
			uint8_t bytes[3] = {
				(pixel >> 8 * 0) & 0xFF,
				(pixel >> 8 * 1) & 0xFF,
				(pixel >> 8 * 2) & 0xFF
			};
			fwrite(bytes, sizeof(bytes), 1, f);
			if (ferror(f)) return_defer(errno);
		}
	}

defer:
	if (f) fclose(f);
	return result;
}
