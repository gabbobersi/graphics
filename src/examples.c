#include "graphics.h"

bool checker_example(void) {
	graphic_fill(pixels, WIDTH, HEIGHT, BACKGROUND_COLOR);
	for (int y = 0; y < ROWS; y++) {
		for (int x = 0; x < COLS; x++) {
			uint32_t color = BACKGROUND_COLOR;
			if ((x + y) % 2 == 0) {
				color = RED;
			}
			graphic_fill_rect(pixels, WIDTH, HEIGHT, x * CELL_WIDTH, y * CELL_HEIGHT, CELL_WIDTH, CELL_HEIGHT, color);
		}
	}

	const char* file_path = "checker.ppm";
	Errno err = graphic_save_to_ppm_file(pixels, WIDTH, HEIGHT, file_path);
	if (err) {
		fprintf(stderr, "ERROR: could not save file %s: %s\n", file_path, strerror(errno));
		return false;
	}
	return true;
}

bool circle_example(void) {
	graphic_fill(pixels, WIDTH, HEIGHT, BACKGROUND_COLOR);
	
	const char* file_path = "circle.ppm";
	Errno err = graphic_save_to_ppm_file(pixels, WIDTH, HEIGHT, file_path);
	if (err) {
		fprintf(stderr, "ERROR: could not save file %s: %s\n", file_path, strerror(errno));
		return false;
	}
	return true;
}

int main(void) {
	if (!checker_example()) return -1;
	if (!circle_example()) return -1;
	return 0;
}