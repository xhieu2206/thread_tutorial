#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>
#include <stdlib.h>

#define NUM_THREADS 4

void *hello(void *);

int main() {
  int j;

  pthread_t tid[NUM_THREADS];

  printf("My process ID %d\n", getpid());

  for (j = 0; j < NUM_THREADS; j++){
    int *arg = malloc(sizeof(*arg));

    if (arg == NULL) {
      fprintf(stderr, "Couldn't allocate memory for thread arg.\n");

      exit(EXIT_FAILURE);
    }

    *arg = j;

    pthread_create(&tid[j], NULL, hello, arg);
  }

  for (int i = 0; i < NUM_THREADS; i++){
    pthread_join(tid[i], NULL);
  }

  return 0;
}

void *hello(void *my_id) {
  int id = *(int *)my_id;

  printf("Hello World from branch thread %d\n", id);

  free(my_id); // Free the allocated memory
  
  return NULL;
}
