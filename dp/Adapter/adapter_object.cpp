//adapter_object.cpp
#include "adapter_object.h"
#include <iostream>
Target_Object::Target_Object()
{
}
Target_Object::~Target_Object()
{
}
void Target_Object::Request()
{
	std::cout<<"Target_Object::Request"<<std::endl;
}
Adaptee_Object::Adaptee_Object()
{
}
Adaptee_Object::~Adaptee_Object()
{
}
void Adaptee_Object::SpecificRequest()
{
	std::cout<<"Adaptee_Object::SpecificRequest"<<std::endl;
}
Adapter_Object::Adapter_Object(Adaptee_Object* ade)
{
	this->_ade = ade;
}
Adapter_Object::~Adapter_Object()
{
}
void Adapter_Object::Request()
{
	_ade->SpecificRequest();
}