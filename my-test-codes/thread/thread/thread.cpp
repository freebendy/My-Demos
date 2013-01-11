#include "prinit.h"
#include "prstrms.h"
#include "prio.h"
#include <string.h>
#include <stdio.h>

#ifdef XP_UNIX

#include <sys/types.h>
#include <sys/stat.h>

#endif

const unsigned int MaxCnt = 1 ;

void threadwork ( void *mytag ) ;

typedef struct threaddarg {
	void *mytag ;
} threaddarg ;

void threadmain ( void *mytag )
{
	threaddarg arg ;
	
	arg.mytag = mytag ;

	threadwork( &arg ) ;

}

void threadwork( void *_arg )
{
	//access the passing parameters
	threaddarg *arg = (threaddarg *)_arg ;
	unsigned int i ;

	char fname1[256] ;
	char fname2[256] ;

	strcpy(fname1, (char *)arg->mytag) ;
	strcpy(fname2, (char *)arg->mytag) ;

}

#define STACKSIZE 1024*1024

int main()
{
	PR_Init(PR_SYSTEM_THREAD, PR_PRIORITY_NORMAL, 256) ;
	threadmain("TestFile") ;

	//creating the thread
	PRThread *thr1 = PR_CreateThread(PR_SYSTEM_THREAD, threadmain, (void *) "TestFile1", PR_GLOBAL_THREAD, PR_JOINABLE_THREAD, STACKSIZE) ;

	//joining the thread
	PR_JoinThread(thr1) ;

	return 0 ;
}



