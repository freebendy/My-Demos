#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;

int FileSize(const char* sFileName)
{
  std::ifstream f;
  f.open(sFileName, std::ios_base::binary | std::ios_base::in);
  if (!f.good() || f.eof() || !f.is_open()) { return 0; }
  f.seekg(0, std::ios_base::beg);
  std::ifstream::pos_type begin_pos = f.tellg();
  f.seekg(0, std::ios_base::end);
  return static_cast<int>(f.tellg() - begin_pos);
}

int main(int argc, char *argv[])
{
	FILE *file = fopen("D:\\output.txt","r") ;
	fseek(file,0L,SEEK_END);
	long endPos = ftell(file) ;
	fclose(file) ;
	cout<<"File Size is " << endPos<<"Bytes"<<endl ;
	
	cout<<"File Size is " << FileSize("D:\\output.txt") <<"Bytes"<<endl ;

	return 0;
}

//boost¿âÓÐ£º
//#include <boost/filesystem/operations.hpp>
//boost::intmax_t file_size( const path & ph );