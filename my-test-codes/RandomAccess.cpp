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
	
	//ʹ��cool.end()-1ȷ����coll������һ��Ԫ�أ����ҷ�ֹ��collԪ�ظ���
	//Ϊż����ʱ����ֵ�δ�������,end()ָ��coll���һ��Ԫ�صĺ�һλ�� 
	for (pos = coll.begin() ; pos <= coll.end() - 1 ; pos += 2)  
	{
		cout << *pos << ' ' ;
	}
	cout << endl ;
}

