//adapter_class.h
#ifndef _ADAPTER_CLASS_H_
#define _ADAPTER_CLASS_H_
class Target_Class
{
public:
	Target_Class();
	virtual ~Target_Class();
	virtual void Request();

protected:

private:

};

class Adaptee_Class
{
public:
	Adaptee_Class();
	~Adaptee_Class();
	void SpecificRequest();
protected:
private:
};

//Adaptee_Class是通过private继承来的
class Adapter_Class:public Target_Class,private Adaptee_Class
{
public:
	Adapter_Class();
	~Adapter_Class();
	void Request();
protected:
private:
};
#endif //~_ADAPTER_CLASS_H_