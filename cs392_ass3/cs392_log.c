//I pledge my honor that I have abided by the Stevens Honor System. -Bsoong
#include "cs392_log.h"


void appendToFile(char *ch) {
  FILE *file;
  file = fopen("cs392_shell.log", "a");
  if(file == NULL) {
    printf("Unable to open the file");
  }
  fprintf(file, "%s\n",ch);
  fclose(file);

}
