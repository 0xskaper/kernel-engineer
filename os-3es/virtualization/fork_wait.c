#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
  int pid = fork();
  if (pid == 0) {
    printf("Child Process -> %d\n", getpid());
    wait(NULL);
  } else {
    printf("---RUNNING PARENT---\n");
  }

  return 0;
}
