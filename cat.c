//I pledge my honor that I have abided by the Stevens Honor System -Bsoong
#include <stdio.h>
#include <stdlib.h>

//Cat function that does the actual printing of the file
void cat(FILE *x) {
  char *c = malloc(10);
  if(!c) {
    perror("Malloc Error");
    exit(1);
  }
  while(fgets(c, 10, x))
  {
    printf("%s",c);
  }
}

//Main function that does a majority of the error checking/makes the final call to cat
int main(int argc, char** argv) {
  if(argc != 2) {
    perror("Error: Only one file argument");
    exit(1);
  }
  FILE *x;
  char file[50];
  char *c;
  x = fopen(argv[1], "r");
  if(x == NULL) {
    perror("Error: File cannot be opened");
    exit(1);
  }
  cat(x);
  fclose(x);
  free(c);
  return 0;
}
