#include <boost/lexical_cast.hpp>
#include <iostream>
#include <string>

int main()
{
	//字符串→数值
	using boost::lexical_cast ;
	int a = lexical_cast<int>("123");
	double b = lexical_cast<double>("123.12");
	std::cout<<a<<std::endl;
	std::cout<<b<<std::endl;

	//数值→字符串
	using std::string ;
	const double d = 123.12 ;
	string s =  lexical_cast<string>(d) ;
	std::cout<<s<<std::endl;

	//异常
	int i ;
	try
	{
		i = boost::lexical_cast<int>("abcd") ;
	}
	catch(boost::bad_lexical_cast& e)
	{
		std::cout<<e.what()<<std::endl;
		return 1;
	}
	std::cout<<i<<std::endl;
	return 0;

}