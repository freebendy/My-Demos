#include <stdio.h>
#include "..\\TestStaticLib\lib.h"

#pragma comment(lib,"..\\debug\\TestStaticLib")

int main()
{
	printf("2 + 3 = %d\n",add(2,3)) ;
}