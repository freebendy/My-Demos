#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

void* thread_function(void *arg){
  int i;
  for(i=0; i<20; i++){
    printf("Thread says hi!\n");
    sleep(1);
  }
  return NULL;
}

int main()
{
  pthread_t mythread;
  
  if(pthread_create(&mythread,NULL,thread_function,NULL)){
    printf("error create thread.");
    abort();
  }
  printf("just a test1!\n");
  sleep(2);
  printf("just a test2!\n");
  if(pthread_join(mythread,NULL)){
    printf("error joining thread.");
    abort();
  }

  printf("just a test3!\n");

  exit(0);
}
//多线程：在linux下运行
//编译：gcc thread1.c -o thread1 -lpthread

