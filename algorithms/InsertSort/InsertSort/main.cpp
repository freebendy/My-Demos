#include <iostream>
#include <cstdlib>
#include <ctime>
/* 
** 插入排序
** 时间复杂度：O(n*n)
** 空间复杂度：1
** 稳定
*/

/*
** 如果目標是把n個元素的序列升序排列，那麼採用插入排序存在最好情況和最壞情況。
** 最好情況就是，序列已經是升序排列了，在這種情況下，需要進行的比較操作需(n-1)次即可。
** 最壞情況就是，序列是降序排列，那麼此時需要進行的比較共有n(n-1)/2次。
** 插入排序的賦值操作是比較操作的次數減去(n-1)次。平均來說插入排序演算法複雜度為O(n2)。
** 因而，插入排序不適合對於數據量比較大的排序應用。
** 但是，如果需要排序的數據量很小，例如，量級小於千，那麼插入排序還是一個不錯的選擇。
*/
const int ARRAY_LEN = 10;

void insert_sort(int *array,const int& length)
{
	if(length < 2)
		return ;

	for(int i = 1; i < length; i ++)
	{
		int tmp = array[i];
		int j = i - 1;
		
		while( j >= 0 && array[j] > tmp)
		{
			array[j + 1] = array[j];
			j --;
		}
		array[j + 1] = tmp;
	}
}

void insert_sort1(int *array,const int& length)
{
  if(length < 2)
    return ;

  int temp;
  for(int i=1;i<length;i++)
  {
    temp = array[i];//store the original sorted array in temp
    int j = i;
    for(; j>0 && temp < array[j-1] ; j--)//compare the new array with temp(maybe -1?)
    {
      array[j]=array[j-1];//all larger elements are moved one pot to the right
    }
    array[j]=temp;
  }
}

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

int main(int argc,char ** argv)
{
	//int a[10] = {3,3445,8,1,4534,876,32,3479,12,-1};
	int a[ARRAY_LEN] = {};
	int min = 1;
	int max = 500;
	getRandomArray(a,ARRAY_LEN,min,max);

	std::cout<<"before sorted!"<<std::endl;
	for(int i = 0; i < ARRAY_LEN; i++)
	{
		std::cout<<"a["<<i<<"] = "<<a[i]<<std::endl;
	}

	insert_sort1(a,ARRAY_LEN);

	std::cout<<"\n\n\n"<<"after sorted!"<<std::endl;
	for(int i = 0; i < ARRAY_LEN; i++)
	{
		std::cout<<"a["<<i<<"] = "<<a[i]<<std::endl;
	}

	/*for(int i = 0; i < argc; i ++)
	{
		std::cout<<"argv["<<i<<"] = "<<argv[i]<<std::endl;
	}*/

	//system("pause");
	return 0;
}