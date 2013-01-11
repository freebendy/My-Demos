#include<iostream>
using namespace std;

class point
{
public:
	point(int xx,int yy){x=xx,y=yy;}
	point(point &p);
	point& operator = (const point &p);
	~point(){cout<<"Îö¹¹"<<endl;}
private:
	int x;
	int y;
};
point::point(point &p)
{
	x=p.x;
	y=p.y;
}
point& point::operator = (const point &p)
{
	x = p.x;
	y = p.y;

	return *this ;
}
point fun2()
{
	point A(1,2);
	return A;
}
int main()
{
	point B(4,5);
	point C = fun2();
	return 0;
}
