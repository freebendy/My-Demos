#include <iostream> 
#include <strstream> 
using namespace std;

int main()  
{ 
	try
	{
        char *name = "www.cndev-lab.com"; 
        int arraysize = strlen(name)+1; 
        istrstream is(name,arraysize); 
        char temp; 
        is>>temp; 
        cout<<temp<<endl; 
        //system("pause"); 
	}
	catch (const exception& error)
	{
		cerr<<error.what()<<endl;
	}
}
