//I pledge my honor that I have abided by the Stevens Honor System. -Bsoong
#include "cs392_exec.h"


void commandRun(char **ch) {
  pid_t p;
  p = fork();
  if(p == -1) {
    printf("Error while attempting to fork.\n");
    return;
  }
  else if(p == 0)  {
    if(execvp(ch[0], ch) < 0) {
      printf("Error: could not execute this command.\n");
    } else {
      exit(EXIT_FAILURE);
        }
  }
  else {
      wait(NULL);
      return;
  }
}
