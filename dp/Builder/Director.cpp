//Director.cpp

#include "director.h"
#include "Builder.h"
#include <iostream>
using namespace std ;

Director::Director(Builder* bld)
{
	_bld = bld;
	cout<<"Director..."<<endl;
}
Director::~Director()
{
}
void Director::Construct()
{
	_bld->BuildPartA("user-defined");
	_bld->BuildPartB("user-defined");
	_bld->BuildPartC("user-defined");
}