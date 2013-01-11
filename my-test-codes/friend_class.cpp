#include <iostream>
using namespace std;

class C ;
class D ;

class IA
{
	protected:
		virtual void get()=0 ;
};

class A : public IA
{
	protected:
		friend class C ;
		friend class D ;
		void show(){ cout <<"A--show()" <<endl; }
		virtual void get() { cout<<"A--get()"<<endl ;}
};

class B : public A
{
	public:
		void sh() { show() ;}
};

class C
{
	protected:
		A a ;
		A *ac ;
	public:
		C() { ac = new B() ;}
		void cShow(){ a.show() ; ac->show(); a.get();}
};

class D : public C
{
	public:
		void dShow() {a.show();}
};

int main(int argc, char *argv[])
{
	B b ;
	b.sh() ;
	C c ;
	c.cShow() ;
	D d;
	d.dShow();

	return 0;
}
//类A把类B定义为友元，A的子类中父类的部分B可以访问，B的子类不能访问A及A的子类
