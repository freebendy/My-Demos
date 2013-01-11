#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
int myglobal = 0;
void *thread_function(void *arg) {
	int i,j;
	for ( i=0; i<20; i++) {
		//printf("11\n");
		j=myglobal;
		j=j+1;
		printf(".");
		fflush(stdout);
		sleep(1);
		myglobal=j;
	}
	return NULL;
}
int main(void) {
    pthread_t mythread;
	int i;
	if ( pthread_create( &mythread, NULL, thread_function, NULL) ) {
		printf("error creating thread.");
		abort();
	}
	for ( i=0; i<20; i++) {
		//printf("22\n");
		myglobal=myglobal+1;
		printf("o");
		fflush(stdout);
		sleep(1);
	}
	if ( pthread_join ( mythread, NULL ) ) {
		printf("error joining thread.");
		abort();
	}
	printf("\nmyglobal equals %d\n",myglobal);
	exit(0);
}
//本例中线程不安全，没有处理全局myglobal的冲突

