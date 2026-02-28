#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {
  int pid = fork();
  if (pid == 0) {
    close(STDOUT_FILENO);
    printf("In Child: %d\n", pid);
  } else {
    printf("In Parent: %d\n", getpid());
    wait(NULL);
  }
}
