#include <iostream> 
#include <fstream> 
using namespace std; 
int main()  
{ 
        ofstream myfile; 
        myfile.open("c:\\1.txt",ios::out|ios::app); 
        if(!myfile)//����д��myfile.fail() 
        { 
                cout<<"�ļ�����ʧ��,���̲���д�����ļ�Ϊֻ��!"; 
                system("pause"); 
                exit(1); 
        } 
        myfile<<"�й��������ʵ����"<<endl<<"��ַ��"<<"www.cndev-lab.com"<<endl; 
        myfile.close(); 
}
