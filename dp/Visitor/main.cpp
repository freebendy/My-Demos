/********************************************************************
	created:	2006/08/09
	filename: 	Main.cpp
	author:		�
                http://www.cppblog.com/converse/

	purpose:	Visitorģʽ�Ĳ��Դ���
*********************************************************************/

#include "Visitor.h"

int main()
{
	Visitor *pVisitorA = new ConcreateVisitorA();
	Element *pElementA  = new ConcreateElementA();
	Element *pElementB  = new ConcreateElementB();

	pElementA->Accept(*pVisitorA);
	pElementB->Accept(*pVisitorA);

	delete pElementA;
	delete pElementB;
	delete pVisitorA;

	return 0;
}
