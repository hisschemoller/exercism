#include "resistor_color_trio.h"
#include <math.h>

resistor_value_t color_code(resistor_band_t * colors) {
  unsigned int value = (colors[0] * 10 + colors[1]) * pow(10, colors[2]);
  resistor_value_t result;
  result.unit = colors[2] > 1 ? KILOOHMS : OHMS;
  result.value = colors[2] > 1 ? value / 1000 : value;
  return result;
}
