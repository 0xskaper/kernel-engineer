#include <stdio.h>
#include <unistd.h>

int main(void) {
  int pid_cvp = fork();
  char *args[] = {"ls", "-l", NULL};
  if (pid_cvp == 0) {
    printf("-----RUNNING FROM CHILD-----\n");
    execvp("ls", args);
  } else {
    printf("----PARENT PROCESS----");
  }

  return 0;
}
