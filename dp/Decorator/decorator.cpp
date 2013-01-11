//decorator.cpp
#include "decorator.h"
#include <iostream>
Component::Component()
{
}
Component::~Component()
{ 
}
void Component::Operation()
{
	//std::cout<<"Component operation..."<<std::endl;
}
ConcreteComponent::ConcreteComponent()
{ 
}
ConcreteComponent::~ConcreteComponent()
{ 
}
void ConcreteComponent::Operation()
{
	std::cout<<"ConcreteComponent operation..."<<std::endl;
}
Decorator::Decorator(Component* com)
{
	this->_com = com;
}
Decorator::~Decorator()
{
	delete _com;
}
void Decorator::Operation()
{
	//std::cout<<"Decorator operation..."<<std::endl;
}
ConcreteDecorator::ConcreteDecorator(Component* com):Decorator(com)
{ 
}
ConcreteDecorator::~ConcreteDecorator()
{ 
}
void ConcreteDecorator::AddedBehavior()
{
	std::cout<<"ConcreteDecorator::AddedBehacior...."<<std::endl;
}
void ConcreteDecorator::Operation()
{
	_com->Operation(); //使用聚合是为了保存积累的方法？通过继承的方法被隐藏了！
	this->AddedBehavior();
}