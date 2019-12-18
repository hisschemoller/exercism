#include "hamming.h"
#include <string.h>
#include <stdlib.h>

int compute(const char *lhs, const char *rhs) {
  int distance = 0;

  if (lhs == NULL || rhs == NULL || strlen(lhs) != strlen(rhs)) {
    return -1;
  }

  for (int i = 0, n = strlen(lhs); i < n; i++) {
    if (lhs[i] != rhs[i]) {
      distance++;
    }
  }

  return distance;
}
