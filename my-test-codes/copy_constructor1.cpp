#include<iostream>
using namespace std;

class point
{
public:
	point(int xx,int yy){x=xx,y=yy;}
	point(const point &p);
	//point& operator = (const point &p);
	~point(){cout<<"����"<<endl;}
private:
	int x;
	int y;
};
point::point(const point &p)
{
	x = p.x;
	y = p.y;
}
//point& point::operator = (const point &p)
//{
//	x = p.x;
//	y = p.y;

//	return *this ;
//}
point fun2()
{
	return point(1,2);
}
int main()
{
	point B(4,5);
	B = fun2();
	return 0;
}

//�ѿ������캯����constȥ��ʹ��g++�޷�����ͨ����
