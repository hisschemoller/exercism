#include "meetup.h"
#include <string.h>
#include <time.h>
#include <stdio.h>

int bufferSize = 16;
int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int getDaysInMonth(unsigned int year, unsigned int month) {
  int numDays = monthDays[month - 1];
  if (month == 2 && year % 4 == 0) {
    numDays = 29;
  }
  return numDays;
}

int meetup_day_of_month(unsigned int year, unsigned int month, const char *week, const char *day_of_week) {
  char buffer[bufferSize];
  struct tm testTm = {
    .tm_year = year - 1900,
    .tm_mon = month - 1,
  };
  struct tm* testTmPtr = &testTm;

  // day range
  int first = 1, last = 31;
  if (strcmp(week, "teenth") == 0) {
    first = 13;
    last = 19;
  } else if (strcmp(week, "first") == 0) {
    first = 1;
    last = 7;
  } else if (strcmp(week, "second") == 0) {
    first = 8;
    last = 14;
  } else if (strcmp(week, "third") == 0) {
    first = 15;
    last = 21;
  } else if (strcmp(week, "fourth") == 0) {
    first = 22;
    last = 28;
  } else if (strcmp(week, "fifth") == 0) {
    int numDays = getDaysInMonth(year, month);
    first = 29;
    last = numDays;
  } else if (strcmp(week, "last") == 0) {
    int numDays = getDaysInMonth(year, month);
    first = numDays - 6;
    last = numDays;
  }

  // iterate the range of days to find the day_of_week
  for (int i = first; i <= last; i++) {
    testTm.tm_mday = i;
    time_t testTime = mktime(testTmPtr);
    struct tm* timeinfo = localtime (&testTime);
    strftime(buffer, bufferSize, "%A", timeinfo);
    if (strcmp(buffer, day_of_week) == 0) {
      return i;
    }
  }

  return 0;
}
