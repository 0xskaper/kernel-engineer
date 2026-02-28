#include <_stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

// int main(void) {
//   int pid = fork();
//   if (pid == 0) {
//     printf("Child Process -> %d\n", getpid());
//     wait(NULL);
//   } else {
//     printf("---RUNNING PARENT---\n");
//   }
//
//   return 0;
// }

int main(void) {
  int chid_1 = fork();
  int chid_2 = fork();
  if (chid_1 == 0) {
    printf("In Child 1 -> %d\n", getpid());
    sleep(10);
  } else if (chid_2 == 0) {
    printf("In Child 2 -> %d\n", getpid());
  } else {
    printf("In Parent -> %d\n", getpid());
    int status;
    waitpid(chid_1, &status, 0);
    printf("Waiting for Child 1 -> %d\n", WEXITSTATUS(status));
  }
}
