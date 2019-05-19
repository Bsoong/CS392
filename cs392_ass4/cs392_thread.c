//I pledge My honor that I have abided by the Stevens Honor System -Bsoong
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>
#include <string.h>

pthread_mutex_t mutevar;
int item1_counter = 0;
int item2_counter = 0;
int item3_counter = 0;

void* cs392_thread_run(void* path) {
  pthread_mutex_lock(&mutevar);
  char compare[7];
  FILE *file = fopen((char *)path, "r");
  if(file == NULL) {
     printf("Unable to open the file");
   }
   while(fgets(compare, sizeof compare, file) != NULL) {
     if(strcmp(compare, "+item1") == 0) {
       item1_counter++;
     }
     if(strcmp(compare, "-item1") == 0) {
       item1_counter--;
     }
     if(strcmp(compare, "+item2") == 0) {
       item2_counter++;
     }
     if(strcmp(compare, "-item2") == 0) {
       item2_counter--;
     }
     if(strcmp(compare, "+item3") == 0) {
       item3_counter++;
     }
     if(strcmp(compare, "-item3") == 0) {
       item3_counter--;
     }
   }
   fclose(file);
   pthread_mutex_unlock(&mutevar);
}

int main(int argc, char** argv) {
  int i = 0;
  int error = 0;
if(argc!=4) {
  printf("Error: Not enough arguments");
  exit(1);
}
if(pthread_mutex_init(&mutevar, NULL) != 0) {
  printf("\n mutex has failed!");
  exit(1);
}
pthread_t id[3];
while(i < 3) {
  error = pthread_create(&(id[i]), NULL, cs392_thread_run, (void *)argv[i+1]);
  if(error !=0) {
    printf("\n Thread cannot be created");
    exit(1);
}
i++;
}
  pthread_join(id[0], NULL);
  pthread_join(id[1], NULL);
  pthread_join(id[2], NULL);
  pthread_mutex_destroy(&mutevar);

  printf("The final value of item1_counter, item2_counter, and item3_counter are %d, %d, and %d", item1_counter, item2_counter, item3_counter);

}
