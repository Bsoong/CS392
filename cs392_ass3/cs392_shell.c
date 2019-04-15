//I pledge my honor that I have abided by the Stevens Honor System. -Bsoong
#include "cs392_signal.h"
#include "cs392_log.h"
#include "cs392_exec.h"

int main(int argc, char **argv) {
  char ch[1024];
  sigRegister();
  while(1) {
    memset(ch, '\0',sizeof(ch));
    printf("cs392_shell $: ");
    fgets(ch, sizeof(ch), stdin);

    size_t length = strlen(ch);
    if(ch[length-1] == '\n') {
      ch[length-1] = '\0';
    }
    appendToFile(ch);
    if(strcmp(ch, "exit") == 0)  {
      exit(EXIT_FAILURE);
    }
    char *ch2 = strtok(ch, " ");
    int count = 0;

    //add Null pointers in the array
    while(ch2 != NULL) {
      argv[count] = ch2;
      ch2 = strtok(NULL, " ");
      count++;
    }
    argv[count] = NULL;
    commandRun(argv);
  }
  return 0;
}
