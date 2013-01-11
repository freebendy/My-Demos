//decorator.h
#ifndef _DECORATOR_H_
#define _DECORATOR_H_

class Component
{
public:
	virtual ~Component();
	virtual void Operation();
protected:
	Component();
private:
};

class ConcreteComponent:public Component
{
public:
	ConcreteComponent();
	~ConcreteComponent();
	void Operation();
protected:
private:
};

//Decorator继承自Component是为了让Decorator的子类接口与ConcreteComponent的接口一致
class Decorator:public Component
{
public:
	Decorator(Component* com);
	virtual ~Decorator();
	void Operation();
protected:
	Component* _com;
private:
};

class ConcreteDecorator:public Decorator
{
public:
	ConcreteDecorator(Component* com);
	~ConcreteDecorator();
	void Operation();
	void AddedBehavior();
protected:
private:
};

#endif //~_DECORATOR_H_