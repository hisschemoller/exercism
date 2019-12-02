#include "darts.h"
#include <stdio.h>
#include <math.h>

uint8_t score(coordinate_t coordinate) {
  double distance = sqrt(pow(coordinate.x, 2) + pow(coordinate.y, 2));
  uint8_t points = 0;

  if (distance <= 1) {
    points = 10;
  } else if (distance <= 5) {
    points = 5;
  } else if (distance <= 10) {
    points = 1;
  }
  
  printf("distance %f, points %d\n", distance, points);
  return points;
}
