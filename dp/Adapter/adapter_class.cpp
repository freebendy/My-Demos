//adapter_class.cpp
#include "adapter_class.h"
#include <iostream>
Target_Class::Target_Class()
{
}
Target_Class::~Target_Class()
{
}
void Target_Class::Request()
{
	std::cout<<"Target_Class::Request"<<std::endl;
}
Adaptee_Class::Adaptee_Class()
{
}
Adaptee_Class::~Adaptee_Class()
{
}
void Adaptee_Class::SpecificRequest()
{
	std::cout<<"Adaptee_Class::SpecificRequest"<<std::endl;
}
Adapter_Class::Adapter_Class()
{
}
Adapter_Class::~Adapter_Class()
{
}
void Adapter_Class::Request()
{
	this->SpecificRequest();
}