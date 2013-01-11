#include <iostream>
#include <cstdlib>
using namespace std;

static void atexit_handler1()
{
	cout<<"atexit_handler1!"<<endl ;
}
static void atexit_handler2()
{
	cout<<"atexit_handler2!"<<endl ;
}

int main(int argc, char *argv[])
{
	atexit(atexit_handler1);
	atexit(atexit_handler2);
	exit(EXIT_SUCCESS) ;
	cout<<"Hello, world"<<'\n';
	
	return 0;
}
