#include "resistor_color.h"
#include <stdio.h>

static resistor_band_t color_codes[] = {BLACK, BROWN, RED, ORANGE, YELLOW, GREEN, BLUE, VIOLET, GREY, WHITE};

uint16_t color_code(resistor_band_t color) {
  return color_codes[color];
}

resistor_band_t * colors() {
  return color_codes;
}
