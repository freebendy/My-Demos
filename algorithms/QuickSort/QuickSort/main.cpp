#include <iostream>
#include "../../utils.h"

/* 
** ��������
** ʱ�临�Ӷȣ�O(Nlogn)
** �ռ临�Ӷȣ�1
** ���ȶ�
*/

/*
** ��ƽ��Ч����˵������ n ����ĿҪ��(n log n)�αȽϡ�
** Ȼ���������Ч���£�����Ҫ��(n2) �αȽϡ�
** һ����˵����������ʵ�������Եر�������(n log n) �㷨���죬
** ��Ϊ�����ڲ���Ȧ��inner loop�������ڴ󲿷ֵļܹ��Ϻ���Ч�ʵر�ʵ��������
** ���ڴ󲿷���ʵ��������ϣ����Ծ�����Ƶ�ѡ�񣬼�������ʱ��Ķ��η���֮�����ԡ�
*/

const int ARRAY_LEN = 10;

//�����һ��Ԫ��Ϊ��׼
int partition(int *array,const int& start,const int& end)
{
	int x= array[end];
	int i = start - 1;
	for(int j = start; j < end; j++)
	{
		if(array[j] <= x)
		{
			i++;
			swap(&array[i],&array[j]);
		}
	}
	swap(&array[i + 1],&array[end]);
	return i + 1;
}

void quick_sort(int *array,const int& start,const int& end)
{
	if(start < end)
	{
		int q = partition(array,0,end);
		quick_sort(array,0,q - 1);
		quick_sort(array,q + 1,end);
	}
}

//�Ե�һ��Ԫ��Ϊ��׼
void quick_sort1(int arr[],int beg,int end)
{
	if (end  >= beg + 1) 
	{
		int piv = arr[beg], k = beg + 1, r = end;

		while (k < r) 
		{
			if (arr[k] < piv) 
				k++;
			else 
				swap(&arr[k], &arr[r--]);
		}

		if (arr[k] < piv)
		{
			swap(&arr[k],&arr[beg]);
			quick_sort1(arr, beg, k);
			quick_sort1(arr, r, end);			
		}
		else 
		{
			if (end - beg == 1)
				return;

			swap(&arr[--k],&arr[beg]);
			quick_sort1(arr, beg, k);
			quick_sort1(arr, r,   end);			
		}
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

	quick_sort(a,0,ARRAY_LEN - 1);

	std::cout<<"\n"<<"after sorted!"<<std::endl;
	for(int i = 0; i < ARRAY_LEN; i++)
	{
		std::cout<<"a["<<i<<"] = "<<a[i]<<std::endl;
	}

	std::cout<<"\n\n\n"<<std::endl;
	int a1[ARRAY_LEN] = {};
	getRandomArray(a1,ARRAY_LEN,min,max);

	std::cout<<"before sorted!"<<std::endl;
	for(int i = 0; i < ARRAY_LEN; i++)
	{
		std::cout<<"a1["<<i<<"] = "<<a1[i]<<std::endl;
	}

	quick_sort1(a1,0,ARRAY_LEN - 1);

	std::cout<<"\n"<<"after sorted!"<<std::endl;
	for(int i = 0; i < ARRAY_LEN; i++)
	{
		std::cout<<"a1["<<i<<"] = "<<a1[i]<<std::endl;
	}

	return 0;
}