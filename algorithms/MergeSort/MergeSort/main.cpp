#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
/* 
** ��������
** ʱ�临�Ӷȣ�O(n*n)
** �ռ临�Ӷȣ�1
** �ȶ�
*/

/*
** ���Ŀ���ǰ�n��Ԫ�ص������������У����N���ò���������������r�������r��
** �����r���ǣ������ѽ������������ˣ����@�N��r�£���Ҫ�M�еı��^������(n-1)�μ��ɡ�
** �����r���ǣ������ǽ������У����N�˕r��Ҫ�M�еı��^����n(n-1)/2�Ρ�
** ����������xֵ�����Ǳ��^�����ĴΔ��pȥ(n-1)�Ρ�ƽ�����f�����������㷨�}�s�Ȟ�O(n2)��
** ��������������m�ό�추��������^��������á�
** ���ǣ������Ҫ����Ĕ�������С�����磬����С�ǧ�����N��������߀��һ�����e���x��
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

/*
** �鲢�����Ĺ���ԭ�����£�
** ����ռ䣬ʹ���СΪ�����Ѿ���������֮�ͣ��ÿռ�������źϲ��������
** �趨����ָ�룬���λ�÷ֱ�Ϊ�����Ѿ��������е���ʼλ��
** �Ƚ�����ָ����ָ���Ԫ�أ�ѡ�����С��Ԫ�ط��뵽�ϲ��ռ䣬���ƶ�ָ�뵽��һλ��
** �ظ�����3ֱ��ĳһָ��ﵽ����β
** ����һ����ʣ�µ�����Ԫ��ֱ�Ӹ��Ƶ��ϲ�����β
*/

/* 
** �ϲ�����
** ʱ�临�Ӷȣ�O(nlogn)
** �ռ临�Ӷȣ�O(n)
** �ȶ�
*/
void merge_sort(int *array1,const int& length1,int *array2,const int& length2,int *array3)
{
  int i = 0,j = 0,n = 0;
  while(i < length1 && j < length2)
  {
    if(array1[i] > array2[j])
      array3[n++] = array2[j++];
    else
      array3[n++] = array1[i++];
  }
  while(i < length1)
    array3[n++] = array1[i++];
  while(j < length2)
    array3[n++] = array2[j++];
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
  int a1[ARRAY_LEN] = {};
  int min = 1;
  int max = 500;
  getRandomArray(a1,ARRAY_LEN,min,max);

  std::cout<<"\n\n\nbefore sorted!"<<std::endl;
  for(int i = 0; i < ARRAY_LEN; i++)
  {
    std::cout<<"a1["<<i<<"] = "<<a1[i]<<std::endl;
  }

  insert_sort1(a1,ARRAY_LEN);

  std::cout<<"\n\n\n"<<"after sorted!"<<std::endl;
  for(int i = 0; i < ARRAY_LEN; i++)
  {
    std::cout<<"a1["<<i<<"] = "<<a1[i]<<std::endl;
  }

  Sleep(1000);

  int a2[ARRAY_LEN] = {};
  getRandomArray(a2,ARRAY_LEN,min,max);

  std::cout<<"\n\n\nbefore sorted!"<<std::endl;
  for(int i = 0; i < ARRAY_LEN; i++)
  {
    std::cout<<"a2["<<i<<"] = "<<a2[i]<<std::endl;
  }

  insert_sort(a2,ARRAY_LEN);

  std::cout<<"\n\n\n"<<"after sorted!"<<std::endl;
  for(int i = 0; i < ARRAY_LEN; i++)
  {
    std::cout<<"a2["<<i<<"] = "<<a2[i]<<std::endl;
  }

  int a3[2*ARRAY_LEN] = {};

  merge_sort(a1,ARRAY_LEN,a2,ARRAY_LEN,a3);
  std::cout<<"\n\n\n"<<"after sorted!"<<std::endl;
  for(int i = 0; i < 2*ARRAY_LEN; i++)
  {
    std::cout<<"a3["<<i<<"] = "<<a3[i]<<std::endl;
  }

  /*for(int i = 0; i < argc; i ++)
  {
  std::cout<<"argv["<<i<<"] = "<<argv[i]<<std::endl;
  }*/

  //system("pause");
  return 0;
}