//main.cpp
#include "adapter_class.h"
#include "adapter_object.h"
#include <iostream>

using namespace std;

int main(int argc,char* argv[])
{
	//类模式 ： 使用多继承
	Target_Class* adt_class = new Adapter_Class;
	adt_class->Request();
	delete adt_class;

	//对象模式 ： 使用组合
	Adaptee_Object* ade_object = new Adaptee_Object;
	Target_Object* adt_object = new Adapter_Object(ade_object);
	adt_object->Request();
	delete adt_object;

	return 0;
}