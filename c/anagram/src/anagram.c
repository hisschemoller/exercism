#include "anagram.h"
#include <stdint.h>
#include <stdio.h>
#include <ctype.h>

void str_tolower(char* str) {
  for(int i = 0; str[i]; i++) {
    str[i] = tolower(str[i]);
  }
}

void anagrams_for(const char *word, struct candidates *candidates) {
  for (uint8_t i = 0; i < (uint8_t)candidates->count; i++) {
    struct candidate* candidate_p = &candidates->candidate[i];
    char candidate_str[strlen(candidate_p->candidate)];
    strcpy(candidate_str, candidate_p->candidate);
    str_tolower(candidate_str);
    uint8_t candidate_length = strlen(candidate_str);
    uint8_t index = 0;
    
    // make a copy of word
    char word_copy[MAX_STR_LEN];
    strcpy(word_copy, word);
    str_tolower(word_copy);

    // same word is no anagram
    if (strcmp(candidate_str, word_copy) == 0) {
      candidate_p->is_anagram = NOT_ANAGRAM;
      continue;
    }

    // iterate characters in candidate
    for (uint8_t j = 0; j < candidate_length; j++) {

      // find the character in candidate
      char character = candidate_str[j];

      // find that character in word_copy, searching from index
      for (uint8_t k = index; k < strlen(word_copy); k++) {

        // if found
        if (word_copy[k] == character) {

          // swap the characters 
          char swap_char = word_copy[index];
          word_copy[index] = character;
          word_copy[k] = swap_char;
          index++;
          break;
        }
      }
    }

    // check if the anagram was created
    if (strcmp(word_copy, candidate_str) == 0) {
      candidate_p->is_anagram = IS_ANAGRAM;
    } else {
      candidate_p->is_anagram = NOT_ANAGRAM;
    }
  }
}
