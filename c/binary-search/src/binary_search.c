#include "binary_search.h"
#include <stdio.h>

int* search_recursive(const int *arr, int low, int high, int index, int value) {
  if (arr[index] > value) {
    high = index;
  } else if (arr[index] < value) {
    low = index;
  } else if (arr[index] == value) {
    return (int *)&arr[index];
  }

  int nextIndex = low + ((high - low) / 2);
  if (index != nextIndex) {
    return search_recursive(arr, low, high, nextIndex, value);
  }

  return NULL;
}

/**
 * @returns pointer to location in the referenced array
 */
int *binary_search(int value, const int *arr, size_t length) {
  int index = (int)length / 2;
  int* pointer = search_recursive(arr, 0, length, index, value);
  return pointer;
}
