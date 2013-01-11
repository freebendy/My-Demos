#include <iostream>
#include <vector>
//#include <algorithm>
#include <sstream>

using namespace std ;

stringstream output ;

void DecToN( int inValue ,int N)
{
	if(N == 2 || N == 8 || N == 16)
	{
		int rest = inValue % N ;
		int quotient = inValue / N ;
		if(quotient != 0)
 			DecToN(quotient,N) ;
		if(rest > 9) //����16����
		{
			char crest = static_cast<char>(rest+55) ;
			cout << crest ;
			output<<crest ;
		}
		else
		{
    		cout << rest ;
			output<<rest ;
		}
	}
	else 
		cout << "Wrong N!!" << endl ;
}

int main()
{
    int InNo ;
    int n ;
  	cout << "������Ҫת������ֵ: " ;
	cin >> InNo ;
	cout << endl ;  
	cout << "������N��" << endl ; 
	cin >> n ;
	cout << endl ;
	DecToN(InNo,n) ;
	cout<<endl;
	
	cout<<output.str()<<endl ;
	return 0 ;
}

		
	
