//I pldege my Honor that I have abided by the Stevens Honor System. -Bsoong

#include "cs392_midterm.h"

char *cs392_strncat(char *dest, char*src, unsigned n) {
  int count = 0;
  int count2 = 0;

  //Gets the size of dest so that the count can then be extended for concatenation with src
  while(dest[count] != '\0') {
    count++;
  }
  
  //While loop runs through src until it hits the end of string symbol or count2 hits max nums of bytes.
  //in the loop constantly adds src to dest.
  while(src[count2] != '\0' && count2 < n) {
    dest[count] = src[count2];
    count++;
    count2++;
  }

  dest[count] = '\0';
  return dest;
}
