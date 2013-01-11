/********************************************************************
	created:	2006/08/09
	filename: 	Visitor.cpp
	author:		�
                http://www.cppblog.com/converse/

	purpose:	Visitorģʽ����ʾ����
*********************************************************************/

#include "Visitor.h"
#include <iostream>s

void ConcreateElementA::Accept(Visitor &rVisitor)
{
	rVisitor.VisitConcreateElementA(this);
}

void ConcreateElementB::Accept(Visitor &rVisitor)
{
	rVisitor.VisitConcreateElementB(this);
}

void ConcreateVisitorA::VisitConcreateElementA(ConcreateElementA *pConcreateElementA)
{
	std::cout << "VisitConcreateElementA By ConcreateVisitorA\n";
}

void ConcreateVisitorA::VisitConcreateElementB(ConcreateElementB *pConcreateElementA)
{
	std::cout << "VisitConcreateElementB By ConcreateVisitorA\n";
}

void ConcreateVisitorB::VisitConcreateElementA(ConcreateElementA *pConcreateElementA)
{
	std::cout << "VisitConcreateElementA By ConcreateVisitorB\n";
}

void ConcreateVisitorB::VisitConcreateElementB(ConcreateElementB *pConcreateElementA)
{
	std::cout << "VisitConcreateElementB By ConcreateVisitorB\n";
}
