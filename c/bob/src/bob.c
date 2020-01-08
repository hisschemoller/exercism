#include "bob.h"
#include <string.h>
#include <ctype.h>
#include <stdio.h>

#define MAX_LENGTH 64

char *hey_bob(char *greeting) {
  static char reply[MAX_LENGTH];

  int isQuestion = 0;
  int isShouting = 1;
  int isArticulate = 0;
  int isAtLeastOneAlpha = 0;
  int isQuestionMark = 0;
  int isCharsAfterQuestionMark = 0;

  char* p = &greeting[0];
  while (*p) {
    isArticulate = isArticulate || isalnum(*p);
    isCharsAfterQuestionMark = isCharsAfterQuestionMark || (isQuestionMark && isalpha(*p));
    isQuestionMark = isQuestionMark || *p == '?';
    isAtLeastOneAlpha = isAtLeastOneAlpha || isalpha(*p);
    isShouting = isShouting && ((isalpha(*p) && isupper(*p)) || (!isalpha(*p)));
    p++;
  }

  isShouting = isShouting && isAtLeastOneAlpha;
  isQuestion = isQuestionMark && !isCharsAfterQuestionMark;

  if (isQuestion) {
    if (isShouting) {
      strcpy(reply, "Calm down, I know what I'm doing!");
    } else {
      strcpy(reply, "Sure.");
    }
  } else {
    if (isShouting) {
      strcpy(reply, "Whoa, chill out!");
    } else if (isArticulate) {
      strcpy(reply, "Whatever.");
    } else {
      strcpy(reply, "Fine. Be that way!");
    }
  }

  return reply;
}
