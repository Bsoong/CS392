//I pledge my honor that I have abided by the Stevens Honor System. -Bsoong

#include "cs392_midterm.h"

int cs392_strcmp(char *s1, char *s2) {
  int count = 0;
  //While loop that runs through s1 and s2 and counts how many elements there are.
  //Each if statement checks the different case ex. if s1 ends early it returns -1
  //If s2 ends early itll return 1. So on and so forth. If it runs through completely it returns 0
  //Which proves
  while(s1[count] != '\0' || s2[count] != '\0') {
    if(s1[count] == '\0') {
      return -1;
    }
    if(s2[count] == '\0') {
      return 1;
    }
    if(s1[count] > s2[count]) {
      return 1;
    }
    if(s1[count] < s2[count]) {
      return -1;
    }
    count++;
  }
  return 0;
}
