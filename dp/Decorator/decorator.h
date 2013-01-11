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

//Decorator�̳���Component��Ϊ����Decorator������ӿ���ConcreteComponent�Ľӿ�һ��
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