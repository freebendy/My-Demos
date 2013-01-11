#include <iostream>
#include <stdexcept>
using namespace std;

void exception1()
{
	throw domain_error("111") ;
}

void exception2()
{
	exception1() ;
}

int main(int argc, char *argv[])
{
	try
	{
		exception2();
	}
	catch (domain_error &e)
	{
		cout<<e.what()<<endl ;
	}
	
	return 0;
}
