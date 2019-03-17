//I pledge My honor that I have abided by the Stevens Honor System -Bsoong

#include "cs392_midterm.h"

char *cs392_strcpy(char *dest, char *src) {
  int count = 0;
  //While loop runs through src until it hits end of line symbol, constantly adding it to dest.
  while(src[count] != '\0') {
    dest[count] = src[count];
    count++;
  }
  //Adds end of line symbol into dest.
  dest[count] = '\0';
  return dest;
}
