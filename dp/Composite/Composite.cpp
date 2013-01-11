//Composite.cpp
#include "Composite.h"
#include "Component.h"
#include <iostream>
using namespace std;

#define NULL 0 //define NULL POINTOR
Composite::Composite()
{
	//vector<Component*>::iterator itend = comVec.begin();
}
Composite::Composite(int i)
{
	mdata = i ;
}
Composite::~Composite()
{
}
void Composite::Operation()
{
	cout<<"Composite operation....."<<mdata<<endl;
	vector<Component*>::iterator comIter = comVec.begin();
	//打印所有叶子
	for (;comIter != comVec.end();comIter++)
	{
		(*comIter)->Operation();
	}
}
void Composite::Add(Component* com)
{
	comVec.push_back(com);
}
void Composite::Remove(Component* com)
{
	comVec.erase(&com);
}
Component* Composite::GetChild(int index)
{
	return comVec[index];
}