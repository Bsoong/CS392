//I pledge My Honor that I have abided by the Stevens Honor Systems -Bsoong

#ifndef CS392_MIDTERM_H
#define CS392_MIDTERM_H
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int test_cs392_strcpy();
int test_cs392_strcmp();
int test_cs392_strncat();

char *cs392_strcpy(char *dest, char *src);
char *cs392_strncat(char *dest, char *src, unsigned n);
int cs392_strcmp(char *s1, char *s2);

#endif
