#include <iostream> 
using namespace std; 
 
class Base 
{ 
    public://公有的 
        int a1; 
        virtual void test() = 0; 
    protected://受保护的 
        int a2; 
    private://私有的 
        int a3; 
}; 
//------------------------------------------------------------------------------ 
class ProtectedClass:protected Base//保护继承 
{ 
    public: 
        void test() 
        { 
            a1 = 1;//a1在这里被转变为protected 
            a2 = 2;//a2在这里被转变为protected 
            //a3=3;//错误，派生类不能访问基类的私有成员 
        } 
}; 
class ControlProtectedClass:public ProtectedClass//以public方式继承ProtectedClass类 
{ 
    public: 
        void test() 
        { 
            a1 = 1;//a1在这里仍然保持为a1在这里被转变为protected 
            a2 = 2;//a2在这里仍然保持为a1在这里被转变为protected 
            //a3=3;//错误,由于Base类成员为私有的，即使是上级父类是保护继承，也不能改变Base类成员的控制类型 
        } 
}; 
//------------------------------------------------------------------------------ 
class PrivateClass:private Base//私有继承 
{ 
    public: 
        void test() 
        { 
            a1 = 1;//a1在这里被转变为private 
            a2 = 2;//a2在这里被转变为private 
            //a3=3;//错误，基类私有成员对文件区域与派生类区域都是不可访问的 
        } 
}; 
class ControlPrivateClass:public PrivateClass//以public方式继承PrivateClass类 
{ 
    public: 
        void test() 
        { 
            //a1=1;//错误，由于基类PrivateClass为私有继承,a1已经转变为private 
            //a2=2;//错误，由于基类PrivateClass为私有继承,a1已经转变为private 
            //a3=3;//错误,由于Base类成员为私有的，PrivateClass类也为私有继承 
        } 
}; 
//------------------------------------------------------------------------------ 
class PublicClass:public Base//共有继承有区别与其它方式的继承，继承后的各成员不会其改变控制方式 
{ 
    public: 
        void test() 
        { 
            a1 = 1;//a1仍然保持public 
            a2 = 2;//a2仍然保持protected 
            //a3=3;//错误，派生类不能操作基类的私有成员 
        } 
}; 
class ControlPublicClass:public PublicClass//以public方式继承PublicClass类 
{ 
    public: 
        void test() 
        { 
            a1 = 1;//a1仍然保持public 
            a2 = 2;//a2仍然保持protected 
            //a3=3;//错误，由于Base类成员为私有成员，即使是上级父类是公有继承，也不能改变Base类成员的控制类型 
        } 
}; 
//------------------------------------------------------------------------------ 
int main() 
{ 
    system("pause");  
}

/*
在继承关系中，基类的private成员不但对应用程序隐藏，即使是派生类也是隐藏不可访问的，而基类的保护成员只对应用程序隐藏，对于派生类来说是不隐藏的,保护继承与私有继承在实际编程工作中使用是极其少见的，
他们只在技术理论上有意义。
*/
