#include "Element.h"
#include "Visitor.h"
#include <iostream>
using namespace std;
int main(int argc,char* argv[])
{
	Visitor* vis = new ConcreteVisitorA();
	Element* elmA = new ConcreteElementA();
	Element* elmB = new ConcreteElementB();
	elmA->Accept(vis);
	elmB->Accept(vis);

	return 0;
}