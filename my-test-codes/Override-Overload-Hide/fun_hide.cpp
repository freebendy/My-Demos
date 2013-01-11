#include <iostream>
#include <string>
using namespace std;

class classA
{
	public:
		int func(int i)
		{
			cout<<"int = "<<i<<'\n';
			return i;
		}
};

class classB : public classA
{
	public:
		string func(string str)
		{
			cout<<"string = "<<str<<'\n';
			return str;
		}
};

int main(int argc, char *argv[])
{

	classA cla;
	cla.func(111);

	classB clb;
	clb.func("sasas");

	classA* pcla = new classA ;
	pcla->func(222);

	classB* pclb = new classB;
	pclb->func("saasdas");
	
	return 0;
}

//вўВи
