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
                cout<<"�ļ�������"; 
                system("pause"); 
                exit(1); 
        } 
        char ch; 
        string content; 
        while(myfile.get(ch)) 
        { 
                content+=ch; 
                //cout.put(ch);//cout<<ch;��ôдҲ�ǿ��Ե� 
				cout<<ch;
        } 
        myfile.close(); 
        //cout<<content; 
        //system("pause"); 
}
