//main.cpp
#include "Subject.h"
#include "Observer.h"
#include <iostream>
using namespace std;
int main(int argc,char* argv[])
{
	ConcreteSubject* sub = new ConcreteSubject();
	Observer* o1 = new ConcreteObserverA(sub);
	Observer* o2 = new ConcreteObserverB(sub);
	sub->SetState("old");
	sub->Notify();
	sub->SetState("new"); //Ҳ������Observer����
	sub->Notify();
	return 0;
}