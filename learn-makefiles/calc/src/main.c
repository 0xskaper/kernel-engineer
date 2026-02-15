#include "add.h"
#include "multi.h"
#include "subtract.h"
#include <stdio.h>

int main(void) {
  printf("3 + 7 -> %d!\n", add(3, 7));
  printf("3 * 3 -> %d!\n", multi(3, 8));
  printf("8 - 2 -> %d\n", subtract(8, 2));
  return 0;
}
