#include "space_age.h"

float earthYearInSeconds = 365.25 * 24 * 60 * 60;
float orbitalPeriods[] = {0.2408467, 0.61519726, 1.0, 1.8808158, 11.862615, 29.447498, 84.016846, 164.79132};

float convert_planet_age(planet_t planet, int64_t input) {
  return input / (earthYearInSeconds * orbitalPeriods[planet]);
}
