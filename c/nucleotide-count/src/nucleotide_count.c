#include "nucleotide_count.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define ANSWER_SIZE 100

char *count(const char *dna_strand) {
  int counts[] = {0, 0, 0, 0};
  char* answer = malloc(ANSWER_SIZE);

  // count the nucleotide occurrances
  int len = strlen(dna_strand);
  for (int i = 0; i < len; i++) {
    switch(dna_strand[i]) {
      case 'A':
        counts[0]++;
        break;
      case 'C':
        counts[1]++;
        break;
      case 'G':
        counts[2]++;
        break;
      case 'T':
        counts[3]++;
        break;
      default:

        // error, exit
        strcpy(answer, "");
        return answer;
    }
  }

  snprintf(answer, ANSWER_SIZE, "A:%d C:%d G:%d T:%d", counts[0], counts[1], counts[2], counts[3]);
  return answer;
}
