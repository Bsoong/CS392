#include "sort.h"
//Compare function used for qsort
int compare (const void * a, const void * b)
{
  return (*(int*)a - *(int*)b );
}
//Main function that error checks/produces the correct output
void readToBin(FILE *x, FILE *y) {
  char *c = malloc(11);
  if(!c) {
    perror("Malloc Error");
    exit(1);
  }
  //while loop used to determine the size of the file.
  int lines = 0;
  while(!feof(x)) {
    char a = fgetc(x);
    if(a == '\n') {
      lines++;
    }
  }
  int arr[lines];
  int count = 0;
  rewind(x);
  while(fgets(c, 11, x)) {
    int temp = atoi(c);
    arr[count] = temp;
    count++;
  }
  qsort(arr, lines, sizeof(int), compare);
  for(int i = 0; i < lines; i++) {
    fprintf(y, "%d", arr[i]);
    fputs("\n", y);
  }
}

//Main function that does a majority of the error checking/makes the final call to cat
int main(int argc, char** argv) {
  if(argc != 3) {
    perror("Error: Need only two file arguments");
    exit(1);
  }
  FILE *x, *y;
  char *c;
  x = fopen(argv[1], "r");
  y = fopen(argv[2], "wb");
  if(x == NULL) {
    perror("Error: File cannot be opened");
    exit(1);
  }
  if(y == NULL) {
    perror("Error: File cannot be opened");
    exit(1);
  }
  readToBin(x,y);
  fclose(x);
  return 0;
}
