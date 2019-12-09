#include "pangram.h"
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

// ASCII a = 97, z = 122
const int ASCII_FIRST = 97;
const int ASCII_LAST = 122;
const int ASCII_LENGTH = ASCII_LAST - ASCII_FIRST + 1;

bool is_pangram(const char *sentence) {
  if (sentence == NULL || strncmp(sentence, "", 1) == 0) {
    return false;
  }

  size_t len = strlen(sentence);
  int allChars[ASCII_LENGTH];
  int numFoundChars = 0;
  memset(allChars, 0, ASCII_LENGTH * sizeof(int));

  for (unsigned int i = 0; i < len; i++) {
    int index = (int) tolower(sentence[i]) - ASCII_FIRST;
    if (index >= 0 && index <= ASCII_LENGTH && allChars[index] == 0) {
      allChars[index]++;
      numFoundChars++;
    }
  }

  return numFoundChars == ASCII_LENGTH;
}
