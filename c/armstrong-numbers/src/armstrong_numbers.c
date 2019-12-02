#include <stdio.h>
#include <math.h>
#include "armstrong_numbers.h"

int is_armstrong_number(int candidate) {
  int test = candidate;
  int numDigits = log10(candidate) + 1;
  int digit = 0;
  int total = 0;

  // iterate the number of digits
  while (candidate != 0) {
    digit = (candidate % 10);
    total += pow(digit, numDigits);
    candidate /= 10;
  }

  return total == test;
}
