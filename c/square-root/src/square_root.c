#include "square_root.h"
#include <math.h>

#define MINDIFF 2.25e-308

/**
 * Algorithm found here:
 * @see https://stackoverflow.com/a/29019938
 */
unsigned int squareRoot(unsigned int number) {
  if (number <= 0) {
    return 0;
  } else if (number == 1) {
    return 1;
  }

  double root = number / 3, last, diff = 1;
  do {
    last = root;
    root = (root + number / root) / 2;
    diff = root - last;
  } while (diff > MINDIFF || diff < -MINDIFF);
  return root;
}
