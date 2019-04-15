#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int counter  = 0;

void* run_thread(void * noarg) {
  int i = 0;

  for(i = 0; i<1000; i++) {
    counter++;
  }
    pthread_exit(NULL);
    return NULL;
}

int main(int argc, char** argv) {
  pthread_t thread1, thread2;
  int temp1, temp2;
  temp1 = pthread_create(&thread1, NULL, run_thread, NULL);
  temp2 = pthread_create(&thread2, NULL, run_thread, NULL);
  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);
  printf("The value in counnter is %d\n", counter);
  exit(EXIT_SUCCESS);

}
