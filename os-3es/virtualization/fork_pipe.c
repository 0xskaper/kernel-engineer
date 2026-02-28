#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {
  int pipefd[2];
  if (pipe(pipefd) == -1) {
    perror("pipe");
    exit(EXIT_FAILURE);
  }

  pid_t pid1 = fork();
  if (pid1 == 1) {
    perror("fork");
    exit(EXIT_FAILURE);
  }
  if (pid1 == 0) {
    close(pipefd[0]);
    dup2(pipefd[1], STDOUT_FILENO);
    close(pipefd[0]);

    execlp("echo", "echo", "hello from Child One", NULL);
    perror("execlp");
    exit(EXIT_FAILURE);
  }

  pid_t pid2 = fork();
  if (pid2 == -1) {
    perror("fork");
    exit(EXIT_FAILURE);
  }
  if (pid2 == 0) {
    close(pipefd[1]);
    dup2(pipefd[0], STDIN_FILENO);
    close(pipefd[0]);

    execlp("wc", "wc", "-w", NULL);
    perror("execlp");
    exit(EXIT_FAILURE);
  }

  close(pipefd[0]);
  close(pipefd[1]);

  waitpid(pid1, NULL, 0);
  waitpid(pid2, NULL, 0);

  printf("Both Children finished.\n");
  return 0;
}
