
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

static int nthread;
pthread_t* tid;

void* f(void* arg){
  int i = *((int*)arg);
  int left_child = i * 2 + 1;
  int right_child = i * 2 + 2;
  if(left_child < nthread){
    pthread_create(&tid[left_child], NULL, f, &left_child);
    pthread_join(tid[left_child], NULL);
  }
  if(right_child < nthread){
    pthread_create(&tid[right_child], NULL, f, &right_child);
    pthread_join(tid[right_child], NULL);
  }
  printf("Thread %d done\n", i);
  return NULL;
}

int main(int argc, char** argv){
  int i = 0;
  if(argc != 2){
    printf("Wrong Number of args\n");
    exit(1);
  }
  nthread = atoi(argv[1]);
  if(nthread <= 0){
    printf("invalid args, should be positive\n");
    exit(1);
  }
  if(nthread == 1){
    printf("Thread 0 done\n");
    exit(1);
  }
  nthread = (2 << nthread - 1) - 2;
  tid = (pthread_t*) malloc(nthread * sizeof(pthread_t));
  if(tid == NULL){
    printf("allocaton failed\n");
  }
  void* ret;
  pthread_create(&tid[0], NULL, f, (void*)&i);
  pthread_join(tid[0], ret);
  free(tid);
}
