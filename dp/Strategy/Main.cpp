//main.cpp
#include "Context.h"
#include "Strategy.h"
#include <iostream>
using namespace std;
int main(int argc,char* argv[])
{
	Strategy* ps;
	ps = new ConcreteStrategyA();
	Context* pc = new Context(ps);
	pc->DoAction();
	if (NULL != pc)
	{
		delete pc;
	}
	if (NULL != ps)
	{
		delete ps;
	}

	Strategy* ps1;
	ps1 = new ConcreteStrategyB();
	Context* pc1 = new Context(ps1);
	pc1->DoAction();
	if (NULL != pc1)
		delete pc1;
	if (NULL != ps1)
	{
		delete ps1;
	}
	return 0;
}