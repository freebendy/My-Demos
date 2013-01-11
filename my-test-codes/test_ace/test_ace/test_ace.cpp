#define ACE_NTRACE 0
#include "ace/Log_Msg.h"

void foo(void) ;


int ACE_TMAIN(int,ACE_TCHAR *[])
{
	ACE_TRACE(ACE_TEXT("main"));

	ACE_LOG_MSG->priority_mask(LM_DEBUG | LM_NOTICE,ACE_Log_Msg::PROCESS) ;
	ACE_DEBUG((LM_INFO,ACE_TEXT("%IHi Mom\n"))) ;
	foo();
	ACE_DEBUG((LM_INFO,ACE_TEXT("%IGoodnight\n")));

	return 0;
}

void foo(void)
{
	ACE_TRACE(ACE_TEXT("foo")) ;
	ACE_DEBUG((LM_INFO,ACE_TEXT("%IHowdy Pardner\n")));
}
