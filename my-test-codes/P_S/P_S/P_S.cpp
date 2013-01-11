#include <iostream>
#include <string>
#include "stdio.h"

using namespace std ;

//typedef void (*func)();
class Person
{
public:
	string name ;
	int age ;
	//static func funcptr=NULL;


	Person()
	{
		name = "Ben" ;
		age = 18 ;
	}
virtual 
	void GetInfo()
	{
		cout<<"name: "<<name<<" "<<"age: "<<age<<endl ;
	}
	void display()
	{
		this->GetInfo() ;
		//cout<<"0x"<<hex<<this<<endl;	
	}
};

class Student : public Person
{
public:
	string school;

	Student():Person()
	{
		school = "No.1" ;
	}

//virtual    
	void GetInfo()
	{
		cout<<"name: "<<name<<" "<<"age: "<<age<<" "<<"school: "<<school<<endl ;
	}
};

int main()
{
	Person P ;
	P.display() ;
	P.GetInfo();


	Student S ;
	S.display() ;
	S.GetInfo() ;

	cout<<endl ;

	Person *p = new Student ;
	p->display() ;
	//p->GetInfo() ;
	Student *s = new Student ;
	s->display() ;
	//s->GetInfo() ;

	delete p;
	delete s;

	system("pause") ;
	return 0 ;

}