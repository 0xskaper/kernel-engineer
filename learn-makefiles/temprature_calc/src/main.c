#include "fa.h"
#include "kel.h"
#include <stdio.h>

int main(void) {
  int celcius;
  printf("Celcius -> ");
  scanf("%d", &celcius);

  printf("Fahrenheit -> %f\n", fa(celcius));
  printf("Kelvin -> %f\n", kel(celcius));
  return 0;
}
