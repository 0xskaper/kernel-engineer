#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(void) {
  int fd = open("mem.c", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
  if (fork() == 0) {
    printf("\n Child Process: FD -> %d", fd);
  } else {
    printf("\nParent Process: FD -> %d", fd);
  }

  return 0;
}
