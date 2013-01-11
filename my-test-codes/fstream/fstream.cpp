#include <iostream>
#include <fstream>
#include <string>

using namespace std ;

int main()
{
	string temp ;
	ifstream fin("d:\\filein.txt");
	ofstream fout("d:\\fileout.txt",ios::app) ;
	while(fin >> temp)
	{
		fout <<  temp << endl ;
	}
	fin.close() ;
	fout.close() ;
	return 0 ;
}