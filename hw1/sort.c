//I pledge my Honor that I have abided by the Stevens Honor System -Bsoong
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
    printf("Malloc Error  %d\n", errno);
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
  //Initialization of the array
  int *arr = malloc(lines * sizeof(int));
  int count = 0;
  //Sets the file back to the beginning
  rewind(x);
  while(fgets(c, 11, x)) {
    int temp = atoi(c);
    arr[count] = temp;
    count++;
  }

  qsort(arr, lines, sizeof(int), compare);
  for(int i = 0; i < lines; i++) {
    fwrite(&arr[i], 4, 1, y);
    fputc('\n', y);
  }
  free(c);
}

//Main function that does a majority of the error checking/makes the final call to cat
int main(int argc, char** argv) {
  if(argc != 3) {
    printf("Error: Need only two file arguments %d\n", errno);
    exit(1);
  }
  FILE *x, *y;
  x = fopen(argv[1], "r");
  y = fopen(argv[2], "wb");
  if(x == NULL) {
    printf("Error: File cannot be opened  %d\n", errno);
    exit(1);
  }
  if(y == NULL) {
    printf("Error: File cannot be opened %d\n", errno);
    exit(1);
  }
  readToBin(x,y);
  fclose(x);
  return 0;
}
