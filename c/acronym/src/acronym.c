#include "acronym.h"
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

char *abbreviate(const char *phrase) {
  if (phrase == NULL || strncmp(phrase, "", 1) == 0) {
    return 0;
  }

  size_t len = strlen(phrase);
  char *buffer = malloc(len * sizeof(char*));
  unsigned int bufferIndex = 0;

  for (unsigned int i = 0; i < len; i++) {
    if (i == 0) {
      buffer[bufferIndex] = toupper(phrase[i]);
      bufferIndex++;
    } else if (isblank(phrase[i]) || phrase[i] == '-') {
      buffer[bufferIndex] = toupper(phrase[(i + 1)]);
      bufferIndex++;
    }
  }
  buffer[bufferIndex] = '\0';
  return buffer;
}
