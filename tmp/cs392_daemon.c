//I pledge my honor that I have abided by the Stevens Honor System -Bsoong
#include <stdio.h>
#include <time.h>
#include <pthread.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main(void) {
pid_t pid, sid;
pid = fork();
if(pid < 0) {
  exit(EXIT_FAILURE);
}
if(pid > 0) {
  exit(EXIT_SUCCESS);
}
umask(0);
FILE *file;
file = fopen("cs392_daemon.log", "a");
if(file == NULL) {
  printf("Unable to open the file");
}

sid = setsid();
if(sid < 0) {
  exit(EXIT_FAILURE);
}
if((chdir("/tmp"))  < 0) {
  exit(EXIT_FAILURE);
}
close(STDIN_FILENO);
close(STDOUT_FILENO);
close(STDERR_FILENO);
while(1) {
  time_t t = time(NULL);
  struct tm *tm = localtime(&t);
  fprintf(file, "%s\n", asctime(tm));
  fflush(file);
  sleep(2);
}
fclose(file);
exit(EXIT_SUCCESS);
}
