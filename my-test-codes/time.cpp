#include <iostream>
#include <ctime>
#include <Windows.h>
using namespace std;

int main(int argc, char *argv[])
{
	cout<<"Hello, world"<<'\n';
	time_t t1 = time(NULL);
	struct tm *tm1 = gmtime(&t1) ;
	int today = (tm1->tm_year+1900)*10000+(tm1->tm_mon+1)*100+tm1->tm_mday ;

	cout<<"today:   "<<today<<endl ;
	
	//char *t2 = ctime(&t1) ;
	time_t t3 = time(NULL) ;
	cout<<"diff: "<<difftime(t1,t3)<<endl;
	
	return 0;
}
