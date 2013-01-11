//adapter_object.h
#ifndef _ADAPTER_OBJECT_H_
#define _ADAPTER_OBJECT_H_
class Target_Object
{
public:
	Target_Object();
	virtual ~Target_Object();
	virtual void Request();
protected:
private:
};
class Adaptee_Object
{
public:
	Adaptee_Object();
	~Adaptee_Object();
	void SpecificRequest();
protected:
private:
};
class Adapter_Object:public Target_Object
{
public:
	Adapter_Object(Adaptee_Object* ade);
	~Adapter_Object();
	void Request();
protected:
private:
	Adaptee_Object* _ade;
};
#endif //~_ADAPTER_OBJECT_H_