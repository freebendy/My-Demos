#include <iostream>
using namespace std;

int sum = 0 ;
int store[10] ;
void Output()
{
	for(int i = 9; i >= 0; --i)
	{
		cout<<store[i]<<"  " ;
	}
	cout<<endl ;
	++sum ;
}

void Cumput(int score,int num)
{
	if(score < 0 || score > (num+1)*10)
		return ;
	if(num==0)
	{
		store[num] =score ;
		Output();
		return ;
	}
	for(int i = 0 ; i <= 10 ; ++i)
	{
		store[num] = i ;
		Cumput(score - i, num - 1) ;
	}
}

int main(int argc, char *argv[])
{
	Cumput(90,9) ;
	cout<<"Total: "<<sum<<'\n';
	
	return 0;
}

//�ݹ��㷨˼�룺��n�εĽ��=n-1 +1���ҳ��˳��ݹ�ĳ���������
/*
���õݹ��㷨���⣬����Ҫ���������������������з����� 

һ�����������ģ�Ĳ�������Ҫ�õݹ��㷨��������⣬���ģͨ�����ǱȽϴ�ģ��������о�����ģ��С�������⸴�ӳ̶ȣ���������Щ���������ҳ����� 

��������ı߽��������߽�ֵ����ʲô����¿���ֱ�ӵó�����Ľ⣿���������ı߽��������߽�ֵ�� 

������������ͨʽ���ѹ�ģ��ġ����ѽ���������ɹ�ģ��С���׽����ͬһ���⣬��Ҫͨ����Щ������ʽ��ʵ�֣����ǽ���ݹ�������ѵ㡣

*/

