/********************************************************************
	created:	2006/08/04
	filename: 	main.cpp
	author:		�
                http://www.cppblog.com/converse/

	purpose:	Commandģʽ�Ĳ��Դ���
*********************************************************************/

#include "Command.h"
#include <stdlib.h>

int main()
{
	Receiver* pReceiver = new Receiver();
	Command*  pCommand  = new ConcreateComand(pReceiver);
	Invoker*  pInvoker  = new Invoker(pCommand);

	pInvoker->Invoke();

	delete pInvoker;

	//system("pause");

	return 0;
}
