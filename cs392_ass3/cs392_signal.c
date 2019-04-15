//I pledge my honor that I have abided by the Stevens Honor System. -Bsoong
#include "cs392_signal.h"
#include <string.h>

static void hdl (int Signal, siginfo_t *siginfo, void *context) {
  printf("  Signal Received %d\n", Signal);
}
void sigRegister() {
  struct sigaction act;
  memset(&act, '\0', sizeof(act));

  act.sa_sigaction = &hdl;
  act.sa_flags = SA_SIGINFO;

  if(sigaction(SIGINT, &act, NULL) < 0) {
    printf("Error1!");
    return;
  }
  if(sigaction(SIGTSTP, &act, NULL) < 0) {
    printf("Error2!");
    return;
  }

}
