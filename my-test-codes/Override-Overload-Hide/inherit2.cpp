#include <iostream> 
using namespace std; 
 
class Base 
{ 
    public://���е� 
        int a1; 
        virtual void test() = 0; 
    protected://�ܱ����� 
        int a2; 
    private://˽�е� 
        int a3; 
}; 
//------------------------------------------------------------------------------ 
class ProtectedClass:protected Base//�����̳� 
{ 
    public: 
        void test() 
        { 
            a1 = 1;//a1�����ﱻת��Ϊprotected 
            a2 = 2;//a2�����ﱻת��Ϊprotected 
            //a3=3;//���������಻�ܷ��ʻ����˽�г�Ա 
        } 
}; 
class ControlProtectedClass:public ProtectedClass//��public��ʽ�̳�ProtectedClass�� 
{ 
    public: 
        void test() 
        { 
            a1 = 1;//a1��������Ȼ����Ϊa1�����ﱻת��Ϊprotected 
            a2 = 2;//a2��������Ȼ����Ϊa1�����ﱻת��Ϊprotected 
            //a3=3;//����,����Base���ԱΪ˽�еģ���ʹ���ϼ������Ǳ����̳У�Ҳ���ܸı�Base���Ա�Ŀ������� 
        } 
}; 
//------------------------------------------------------------------------------ 
class PrivateClass:private Base//˽�м̳� 
{ 
    public: 
        void test() 
        { 
            a1 = 1;//a1�����ﱻת��Ϊprivate 
            a2 = 2;//a2�����ﱻת��Ϊprivate 
            //a3=3;//���󣬻���˽�г�Ա���ļ������������������ǲ��ɷ��ʵ� 
        } 
}; 
class ControlPrivateClass:public PrivateClass//��public��ʽ�̳�PrivateClass�� 
{ 
    public: 
        void test() 
        { 
            //a1=1;//�������ڻ���PrivateClassΪ˽�м̳�,a1�Ѿ�ת��Ϊprivate 
            //a2=2;//�������ڻ���PrivateClassΪ˽�м̳�,a1�Ѿ�ת��Ϊprivate 
            //a3=3;//����,����Base���ԱΪ˽�еģ�PrivateClass��ҲΪ˽�м̳� 
        } 
}; 
//------------------------------------------------------------------------------ 
class PublicClass:public Base//���м̳���������������ʽ�ļ̳У��̳к�ĸ���Ա������ı���Ʒ�ʽ 
{ 
    public: 
        void test() 
        { 
            a1 = 1;//a1��Ȼ����public 
            a2 = 2;//a2��Ȼ����protected 
            //a3=3;//���������಻�ܲ��������˽�г�Ա 
        } 
}; 
class ControlPublicClass:public PublicClass//��public��ʽ�̳�PublicClass�� 
{ 
    public: 
        void test() 
        { 
            a1 = 1;//a1��Ȼ����public 
            a2 = 2;//a2��Ȼ����protected 
            //a3=3;//��������Base���ԱΪ˽�г�Ա����ʹ���ϼ������ǹ��м̳У�Ҳ���ܸı�Base���Ա�Ŀ������� 
        } 
}; 
//------------------------------------------------------------------------------ 
int main() 
{ 
    system("pause");  
}

/*
�ڼ̳й�ϵ�У������private��Ա������Ӧ�ó������أ���ʹ��������Ҳ�����ز��ɷ��ʵģ�������ı�����Աֻ��Ӧ�ó������أ�������������˵�ǲ����ص�,�����̳���˽�м̳���ʵ�ʱ�̹�����ʹ���Ǽ����ټ��ģ�
����ֻ�ڼ��������������塣
*/
