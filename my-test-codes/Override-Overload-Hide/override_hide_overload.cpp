#include <stdio.h>

int main(int argc, char *argv[])
{
	printf("Hello, world\n");
	
	return 0;
}


/*************************************
  成员函数被重载的特征：       
  （1）相同的范围（在同一个类中）；       
  （2）函数名字相同；       
  （3）参数不同；       
  （4）virtual关键字可有可无。       
  覆盖是指派生类函数覆盖基类函数，特征是：       
  （1）不同的范围（分别位于派生类与基类）；       
  （2）函数名字相同；       
  （3）参数相同；       
  （4）基类函数必须有virtual关键字。       
  “隐藏”是指派生类的函数屏蔽了与其同名的基类函数，规则如下：       
  （1）如果派生类的函数与基类的函数同名，但是参数不同。此时，不论有无virtual关键字，基类的函数将被隐藏（注意别与重载混淆）。       
  （2）如果派生类的函数与基类的函数同名，并且参数也相同，但是基类函数没有virtual关键字。此时，基类的函数被隐藏（注意别与覆盖混淆）。
***************************************/

//重载   
class   A   
{   
  public:               
            A();   
            virtual   ~A();   
            virtual   void   B(int,int);   
            virtual   void   B(int,int,char   *);//此为总裁函数   
            virtual   void   B(int);//此为总裁函数   
};   
//覆盖、隐藏   
class   C   :   public   A   
{   
  public:   
              C();   
            ~C();   
              void   B(int,int);//覆盖了基类A中的void   B(int,int)   
                                              //同时以下基类函数被饮场   
                                              //virtual   void   B(int,int,char   *);   
                                              //virtual   void   B(int);   
};
