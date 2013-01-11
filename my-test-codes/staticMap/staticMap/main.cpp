#include <iostream>
#include "fieldsmap.h"

int main(int argc, char *argv[])
{
    pctor::FieldsMap::initialize() ;

    std::cout<<pctor::FieldsMap::accountMap["SENDFILEAUTHORITY"]<<std::endl ;

	return 0;
}
