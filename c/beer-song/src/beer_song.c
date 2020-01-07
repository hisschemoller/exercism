#include "beer_song.h"
#include <string.h>
#include <stdio.h>

#define BUFFER_SIZE 1024

void verse(char *buffer, unsigned int verse_number) {
  sing(buffer, verse_number, verse_number);
}

void sing(char *buffer, unsigned int starting_verse_number, unsigned int ending_verse_number) {
  buffer[0] = '\0';
  for (int i = (int)starting_verse_number; i >= (int)ending_verse_number; i--) {
    char verse[BUFFER_SIZE];
    switch (i) {
      case 0:
        sprintf(verse, "No more bottles of beer on the wall, no more bottles of beer.\nGo to the store and buy some more, 99 bottles of beer on the wall.\n");
        break;
      case 1:
        sprintf(verse, "%d bottle of beer on the wall, %d bottle of beer.\nTake it down and pass it around, no more bottles of beer on the wall.\n", i, i);
        break;
      case 2:
        sprintf(verse, "%d bottles of beer on the wall, %d bottles of beer.\nTake one down and pass it around, %d bottle of beer on the wall.\n", i, i, i - 1);
        break;
      default:
        sprintf(verse, "%d bottles of beer on the wall, %d bottles of beer.\nTake one down and pass it around, %d bottles of beer on the wall.\n", i, i, i - 1);
    }
    
    strcat(buffer, verse);

    if (i > (int)ending_verse_number) {
      strcat(buffer, "\n");
    }
  }
}
