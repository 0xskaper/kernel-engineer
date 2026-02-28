#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {
  int x = 100;
  if (fork() == 0) {
    printf("\nChild Process: x -> %d\n", x);
  } else {
    wait(NULL);
    printf("Parent Process: x -> %d\n", x);
  }

  return 0;
}
