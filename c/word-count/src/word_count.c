#include "word_count.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int word_count(const char *input_text, word_count_word_t * words) {

  // clear previous solution
  for (unsigned int i = 0; i < MAX_WORDS; i++) {
    words[i].count = 0;
    memset(words[i].text, 0, MAX_WORD_LENGTH + 1);
  }

  size_t textSize = strlen(input_text);
  char *buffer = malloc((MAX_WORD_LENGTH + 1) * sizeof(char*));
  unsigned int bufferIndex = 0;
  unsigned int wordIndex = 0;
  for (unsigned int i = 0; i < textSize; i++) {
    if (isalnum(input_text[i]) || (input_text[i] == '\'' && isalpha(input_text[i - 1]) && isalpha(input_text[i + 1]))) {
      
      // add character to word
      buffer[bufferIndex] = tolower(input_text[i]);
      bufferIndex++;
    }

    // if there is a string and the new char is alphanum
    if (bufferIndex > 0 && (!(isalnum(input_text[i]) || (input_text[i] == '\'' && isalpha(input_text[i - 1]) && isalpha(input_text[i + 1]))) || i == textSize - 1)) {

      // update count if the word already exists
      int isFound = 0;
      for (unsigned int j = 0; j < wordIndex; j++) {
        if (strcmp(words[j].text, buffer) == 0) {
          isFound = 1;
          words[j].count++;
        }
      }

      // add new word to solution
      if (!isFound) {

        if (bufferIndex > MAX_WORD_LENGTH) {
          return EXCESSIVE_LENGTH_WORD;
        }

        if (wordIndex >= MAX_WORDS) {
          return EXCESSIVE_NUMBER_OF_WORDS;
        }

        words[wordIndex].count++;
        buffer[bufferIndex] = '\0';
        strcpy(words[wordIndex].text, buffer);
        memset(buffer, 0, MAX_WORD_LENGTH * (sizeof(char*)));
        wordIndex++;
      }

      bufferIndex = 0;
    }
  }

  return wordIndex;
}
