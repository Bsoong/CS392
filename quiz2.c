#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

static void hd1 (int Signal, siginfo_t *siginfo, void *context) {
  printf("received\n");
}

int main(int argc, char *argv[]) {
  struct sigaction act;
  memset(&act, '\0', sizeof(act));
  act.sa_sigaction = &hd1;
  act.sa_flags = SA_SIGINFO | SA_RESETHAND;

  if(sigaction(SIGINT, &act, NULL) < 0) {
    printf("Sigaction");
    return 1;
  }

  while(1) {
    sleep(1);
    printf("Hellow\n");
  }
  return 0;
}
