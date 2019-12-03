#include "isogram.h"
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

bool is_isogram(const char phrase[]) {
  if (phrase == NULL) {
    return false;
  }
  unsigned int len = strlen(phrase);
  unsigned int i, j;
  bool isIsogram = true;
  for (i = 0; i < len; i++) {
    for (j = 0; j < len; j++) {
      if (i != j && phrase[i] != '-' &&  phrase[i] != ' ' && tolower(phrase[i]) == tolower(phrase[j])) {
        isIsogram = false;
      }
    }
  }
  return isIsogram;
}
