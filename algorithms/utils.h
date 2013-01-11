#include <ctime>

void getRandomArray(int *array,const int& length,const int& min,const int& max)
{
	if(length < 1)
		return ;
	srand(time(NULL));
	for(int i = 0 ; i < length; i++)
	{
		array[i] = min + rand() % (max - min + 1);
	}
}

void swap(int *a,int *b)
{
	int t=*a; *a=*b; *b=t; 
}