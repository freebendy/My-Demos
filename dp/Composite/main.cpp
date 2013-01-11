//main.cpp
#include "Component.h"
#include "Composite.h"
#include "Leaf.h"
#include <iostream>
using namespace std;
int main(int argc,char* argv[])
{
	Leaf* l1 = new Leaf(1);
	l1->Operation();
	Composite* com1 = new Composite(1);
	com1->Add(l1);
	com1->Operation();
	Component* ll1 = com1->GetChild(0);
	ll1->Operation();
	cout<<"\n"<<"\n";

	Leaf* l2 = new Leaf(2);
	l2->Operation();
	com1->Add(l2);
	com1->Operation(); //有多少个叶子打印多少次
	Component* ll2 = com1->GetChild(1);
	ll2->Operation();
	cout<<"\n"<<"\n";

	Leaf* l3 = new Leaf(3);
	l3->Operation();
	com1->Add(l3);
	com1->Operation(); //有多少个叶子打印多少次
	Component* ll3 = com1->GetChild(2);
	ll3->Operation();
	cout<<"\n"<<"\n";

	Leaf* l4 = new Leaf(4);
	l4->Operation();
	Composite* com2 = new Composite(2);
	com2->Add(l4);
	com2->Operation();
	Component* ll4 = com2->GetChild(0);
	ll4->Operation();
	cout<<"\n"<<"\n";

	com1->Add(com2);
	com1->Operation(); //有多少个叶子打印多少次


	return 0;
}