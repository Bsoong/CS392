//I Pledge my honor that I have abided by the Stevens Honor System -Bsoong
#include "cs392_string.h"

void *cs392_memcpy(void * dst, void * src, unsigned num) {
  char *msrc = (char *)src;
   char *mdst = (char *)dst;
  for(int i = 0; i < num; i++) {
      mdst[i] = msrc[i];
  }
  return mdst;
}
