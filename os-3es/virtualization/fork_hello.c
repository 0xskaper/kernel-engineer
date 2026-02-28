#include <stdio.h>
#include <unistd.h>

int main(void) {
  int pid = fork();
  if (pid == 0) {
    printf("\nHello From Child: %d", getpid());
  } else {
    sleep(1);
    printf("\nGoodBye! Parent: %d", getpid());
  }
}
