#include "gigasecond.h"

#define GIGA_SECOND 1000000000

time_t gigasecond_after(time_t time ) {
  return time + GIGA_SECOND;
}
