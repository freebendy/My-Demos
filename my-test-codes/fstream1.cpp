#include <iostream> 
#include <fstream> 
#include <string> 
using namespace std; 
int main()  
{ 
        ifstream myfile; 
        myfile.open("c:\\1.txt",ios::in); 
        if(!myfile) 
        { 
                cout<<"文件读错误"; 
                system("pause"); 
                exit(1); 
        } 
        char ch; 
        string content; 
        while(myfile.get(ch)) 
        { 
                content+=ch; 
                //cout.put(ch);//cout<<ch;这么写也是可以的 
				cout<<ch;
        } 
        myfile.close(); 
        //cout<<content; 
        //system("pause"); 
}
