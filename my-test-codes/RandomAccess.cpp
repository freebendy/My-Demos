#include <iostream>
#include <vector>

using namespace std ;

int main()
{
	vector<int> coll ;
	
	for (int i = -3 ; i <= 9 ; ++ i)
	{
		coll.push_back(i) ;
	}
	
	cout << "numbers/distance: " << coll.end() - coll .begin() << endl ;
	
	vector<int>::iterator pos ;
	
	for (pos = coll.begin() ; pos <= coll.end() ; ++ pos)
	{
		cout << *pos << ' ' ;
	}
	cout << endl ;
	
	for (int i = 0 ; i <= coll.size() ; ++ i)
	{
		cout << coll.begin()[i] << ' ' ;
	}
	cout << endl ;
	
	//使用cool.end()-1确保了coll至少有一个元素，而且防止了coll元素个数
	//为偶数的时候出现的未定义情况,end()指向coll最后一个元素的后一位！ 
	for (pos = coll.begin() ; pos <= coll.end() - 1 ; pos += 2)  
	{
		cout << *pos << ' ' ;
	}
	cout << endl ;
}

