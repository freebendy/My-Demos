#include <iostream>
#include "../../utils.h"

/* 
** 堆排序
** 时间复杂度：O(Nlogn) ～ O(n*n)
** 空间复杂度：O(logn)
** 不稳定
*/

/*
** 最大堆積調整（Max_Heapify）：將堆積樹的末端子結點作調整,使得子結點永遠小於父結點
** 建立最大堆積（Build_Max_Heap）：將堆積樹所有數據重新排序
** 堆積排序（HeapSort）：移除位在第一個數據的根結點,並做最大堆積調整的遞迴運算
*/

const int ARRAY_LEN = 10;

//获取左节点
int left(const int& i)
{
	return 2*i;
}
//获取右节点
int right(const int& i)
{
	return 2*i + 1;
}

//保持每个子堆为最大堆
void Max_Heapify(int *array,const int& i,const int& length)
{
	int l = left(i);
	int r = right(i);
	int largest;

	if(l < length && array[l] > array[i])
	{
		largest = l;
	}
	else
	{
		largest = i;
	}

	if(r < length && array[r] > array[largest])
	{
		largest = r;
	}

	if (largest != i)
	{
		swap(&array[i],&array[largest]);
		Max_Heapify(array,largest,length);
	}
}

//创建最大堆
void Build_Max_Heap(int *array,const int& length)
{
	for(int i = length/2; i >=0; --i)
	{
		Max_Heapify(array,i,length);
	}
}

void heap_sort(int *array,int length)
{
	if(length < 2)
		return ;

	Build_Max_Heap(array,length);
	for(int i = length - 1; i >=1; --i)
	{
		swap(&array[0],&array[i]);
		--length;
		Max_Heapify(array,0,length);
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
	for(int i = 0; i < ARRAY_LEN; ++i)
	{
		std::cout<<"a["<<i<<"] = "<<a[i]<<std::endl;
	}

	heap_sort(a,ARRAY_LEN);

	std::cout<<"\n"<<"after sorted!"<<std::endl;
	for(int i = 0; i < ARRAY_LEN; ++i)
	{
		std::cout<<"a["<<i<<"] = "<<a[i]<<std::endl;
	}

	return 0;
}