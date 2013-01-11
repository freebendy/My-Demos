#include <stdio.h>
class Base
{
public:
    void NoVirtualFun()
    {
        printf("Base::NoVirtualFun()!\n");
    }
    virtual void VirtualFun()
    {
        printf("Base::VirtualFun()!\n");
    }
};

class ClassA
{
private:
    Base* m_pBase;
public:
    ClassA() : m_pBase(NULL) {}
    void AddBase(Base* pBase)
    {
        m_pBase = pBase;
    }
    void Print()
    {
        //�˴�ʹ�õķ���Ȩ����Base::VirtualFun()�ķ���Ȩ��(public)
        //�����ClassA�п���ʹ�ø��麯����������������Child�иú�����Ȩ�����á�
        m_pBase->VirtualFun();
    }
};

//ע��˽�м̳�
class Child: private Base
{
private:
    ClassA* m_pClassA;
private:    //˽��
    virtual void VirtualFun()
    {
        printf("Child::VirtualFun()!\n");
    }
public:
    Child(ClassA* pClassA)
    {
        m_pClassA = pClassA;
        m_pClassA->AddBase(this);
    }
};

//1.ʹ��Private�̳к��޷�������������ֱ��ʹ�ö�̬,
//  ������ָ���޷��Զ�ת��Ϊ����ָ��.
//2.�ӻ���private�̳��麯���������������н����麯�����أ�
//  �����÷���Ȩ��Ϊpublic�����麯����Ϊpublic��Ա����.

int main(int argc, char* argv[])
{
    ClassA* classA = new ClassA();
    Child* chd = new Child(classA);
   
//  classA->AddBase((Base*)chd);    ����ǿ��ת��Ϊ����ָ��
//  classA->AddBase(chd);   �����޷��Զ�ת��Ϊ����ָ��
    classA->Print();

//����Child�н�VirtualFun()ָ��ΪPublic���ú�������Ϊpublic�ĳ�Ա����,
//������private�̳к��private��Ա����
//  chd->VirtualFun();  Error ��ʱΪ˽�г�Ա������Chlid::VirtualFun()�ķ���Ȩ����Ϊpublic����ȷ
    delete chd;
    delete classA;
    return 0;
}

/*
����:
1. ˽�м̳е��麯��, �����Ȩ�޿���������ָ��.
2. ˽�м̳к�, �޷�������������������ж�̬, ������ָ���޷��Զ�ת��Ϊ����ָ��(����ǿ������ת��).
3. �������ཫ������publicȨ�޵��麯�����ز�����Ϊprivate��protectedʱ, ��̬ʱֱ��ʹ�û���ָ�뽫����������Ը��麯������Ȩ�޵ĸ��ģ��Ի��ຯ���ķ���Ȩ��Ϊ���ݵ��ø��麯��.
*/
