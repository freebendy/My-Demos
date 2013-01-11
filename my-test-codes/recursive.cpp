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

//递归算法思想：第n次的结果=n-1 +1，找出退出递归的出口条件！
/*
利用递归算法解题，首先要对问题的以下三个方面进行分析： 

一、决定问题规模的参数。需要用递归算法解决的问题，其规模通常都是比较大的，在问题中决定规模大小（或问题复杂程度）的量有哪些？把它们找出来。 

二、问题的边界条件及边界值。在什么情况下可以直接得出问题的解？这就是问题的边界条件及边界值。 

三、解决问题的通式。把规模大的、较难解决的问题变成规模较小、易解决的同一问题，需要通过哪些步骤或等式来实现？这是解决递归问题的难点。

*/

