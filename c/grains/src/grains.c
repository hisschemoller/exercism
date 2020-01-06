#include "grains.h"
#include <math.h>

#define NUM_SQUARES 64

static int isFirstRun = 1;
static uint64_t total_grains = 0;
static uint64_t squares[NUM_SQUARES];

void calculate() {
  if (isFirstRun) {
    isFirstRun = 0;
    for (int i = 0; i < NUM_SQUARES; i++) {
      squares[i] = pow(2, i);
      total_grains += squares[i];
    }
  }
}

uint64_t square(uint8_t index) {
  if (index < 1 || index > NUM_SQUARES) {
    return 0;
  }

  calculate();
  return squares[index - 1];
}

uint64_t total(void) {
  calculate();
  return total_grains;
}
