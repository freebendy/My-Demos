#include <iostream>
#include <map>
using namespace std;

	enum TEST
	{	AAA=0,
		BBB,
		CCC
	};

	void fun(TEST &tt)
	{
		tt=BBB;
		cout<<tt<<endl;
	}

int main(int argc, char *argv[])
{
	cout<<"Hello, world"<<'\n';
	map<int,int> mapint ;
	for(int i=0;i<10;i++)
	{
		mapint[i]=i;
	}
	map<int,int>::iterator pos=mapint.begin() ;
	int i=0;
	while(i<9)
	{
		cout<<pos->second<<endl;
		++i;
		++pos;
	}


	TEST test=AAA ;
	cout<<test<<endl;
	fun(test);

	return 0;
}
