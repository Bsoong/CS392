//I pledge my honor that I have abided by the Stevens Honor System- Bsoong
#include "cs392_string.h"
unsigned cs392_strlen(char *str) {
  int count = 0;
  while(str[count] != '\0') {
    count++;
  }
  return count;
}
