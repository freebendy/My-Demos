//main.cpp
#include "adapter_class.h"
#include "adapter_object.h"
#include <iostream>

using namespace std;

int main(int argc,char* argv[])
{
	//��ģʽ �� ʹ�ö�̳�
	Target_Class* adt_class = new Adapter_Class;
	adt_class->Request();
	delete adt_class;

	//����ģʽ �� ʹ�����
	Adaptee_Object* ade_object = new Adaptee_Object;
	Target_Object* adt_object = new Adapter_Object(ade_object);
	adt_object->Request();
	delete adt_object;

	return 0;
}