//Leaf.cpp
#include "Leaf.h"
#include <iostream>
using namespace std;

Leaf::Leaf()
{
}
Leaf::Leaf(int i)
{
	mdata = i;
}
Leaf::~Leaf()
{
}
void Leaf::Operation()
{
	cout<<"Leaf operation....."<<mdata<<endl;
}