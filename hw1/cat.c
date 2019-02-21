//I pledge my honor that I have abided by the Stevens Honor System -Bsoong
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

//Cat function that does the actual printing of the file
void cat(FILE *x) {
  char *c = malloc(10);
  if(!c) {
    printf("Malloc Error %d\n", errno);
    exit(1);
  }
  while(fgets(c, 10, x))
  {
    printf("%s",c);
  }
  free(c);
}

//Main function that does a majority of the error checking/makes the final call to cat
int main(int argc, char** argv) {
  if(argc != 2) {
    printf("Error: Only one file argument %d\n", errno);
    exit(1);
  }
  FILE *x;
  x = fopen(argv[1], "r");
  if(x == NULL) {
    printf("Error: File cannot be opened %d\n", errno);
    exit(1);
  }
  cat(x);
  fclose(x);
  return 0;
}
