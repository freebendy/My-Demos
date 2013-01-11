//Visitor.cpp
#include "Visitor.h"
#include "Element.h"
#include <iostream>
using namespace std;
Visitor::Visitor()
{
}
Visitor::~Visitor()
{
}
ConcreteVisitorA::ConcreteVisitorA()
{
}
ConcreteVisitorA::~ConcreteVisitorA()
{
}
void ConcreteVisitorA::VisitConcreteElementA(Element* elm)
{
	cout<<"i will visit ConcreteElementA..."<<" through ConcreteVisitorA"<<endl;
}
void ConcreteVisitorA::VisitConcreteElementB(Element* elm)
{
	cout<<"i will visit ConcreteElementB..."<<" through ConcreteVisitorA"<<endl;
}
ConcreteVisitorB::ConcreteVisitorB()
{
}
ConcreteVisitorB::~ConcreteVisitorB()
{
}
void ConcreteVisitorB::VisitConcreteElementA(Element* elm)
{
	cout<<"i will visit ConcreteElementA..."<<" through ConcreteVisitorB"<<endl;
}
void ConcreteVisitorB::VisitConcreteElementB(Element* elm)
{
	cout<<"i will visit	ConcreteElementB..."<<" through ConcreteVisitorB"<<endl;
}