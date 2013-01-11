#include <iostream> 
#include <fstream> 
using namespace std; 
int main()  
{ 
        ofstream myfile; 
        myfile.open("c:\\1.txt",ios::out|ios::app); 
        if(!myfile)//或者写成myfile.fail() 
        { 
                cout<<"文件创建失败,磁盘不可写或者文件为只读!"; 
                system("pause"); 
                exit(1); 
        } 
        myfile<<"中国软件开发实验室"<<endl<<"网址："<<"www.cndev-lab.com"<<endl; 
        myfile.close(); 
}
