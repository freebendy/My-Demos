//Product.cpp
#include "Product.h"
#include <iostream>
using namespace std ;

Product::Product()
{
	cout<<"Product..."<<endl;
}
Product::~Product()
{
}
void Product::ProducePart()
{
	cout<<"ProducePart function"<<endl ;
}
ProductPart::ProductPart()
{
	cout<<"ProductPart..."<<endl;
}
ProductPart::~ProductPart()
{
}
ProductPart* ProductPart::BuildPart()
{
	cout<<"BuildPart function"<<endl;
	return 0;
}
