#include <iostream>
#include "../../utils.h"

/* 
** ������
** ʱ�临�Ӷȣ�O(Nlogn) �� O(n*n)
** �ռ临�Ӷȣ�O(logn)
** ���ȶ�
*/

/*
** ���ѷe�{����Max_Heapify�������ѷe���ĩ���ӽY�c���{��,ʹ���ӽY�c���hС춸��Y�c
** �������ѷe��Build_Max_Heap�������ѷe�����Д�����������
** �ѷe����HeapSort�����Ƴ�λ�ڵ�һ�������ĸ��Y�c,�K�����ѷe�{�����fޒ�\��
*/

const int ARRAY_LEN = 10;

//��ȡ��ڵ�
int left(const int& i)
{
	return 2*i;
}
//��ȡ�ҽڵ�
int right(const int& i)
{
	return 2*i + 1;
}

//����ÿ���Ӷ�Ϊ����
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

//��������
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