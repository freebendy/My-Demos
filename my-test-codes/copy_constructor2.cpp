#include <iostream>
using namespace std;
class Person
{
 public:
  Person(char *pN)
  {
   cout <<"Constructing "<<pN<<endl;
   pName=new  char (strlen(pN)+1);
   if (pName!=0)
   {
    strcpy(pName,pN);
   }
  }
  
  Person(const Person& p)
  {
   cout <<"copying "<<p.pName<<"into its own block\n";
   pName=new char [sizeof(p.pName)];
   if (pName!=0)
    strcpy(pName,p.pName);
 
  }
  ~Person()
  {
   cout<<"Destructing "<<pName<<endl;
   pName[0]='\0';
   delete   pName;
  
  }
 
 protected:
  char *pName;
} ;

Person fun()
{
	return Person("ben");
}

int main()
{
 Person   p1("Randy");
 Person   p2=p1;               //即Person  p2 (p1);
 p2 = fun();
} 

//把拷贝构造函数的const去掉使用g++无法编译通过！
