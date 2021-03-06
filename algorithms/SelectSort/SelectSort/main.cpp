#include <iostream>
#include <cstdlib>
#include <ctime>

/* 
** 选择排序
** 时间复杂度：O(n*n)
** 空间复杂度：1
** 不稳定
*/
/*
** 选择排序的交换操作介于0和(n  − 1)次之间。
** 选择排序的比较操作为n(n  − 1) / 2次之间。
** 选择排序的赋值操作介于0和3(n − 1)次之间。
*/
/*
** 比较次数O(n^2),比较次数与关键字的初始状态无关，总的比较次数N=(n-1)+(n-2)+...+1=n*(n-1)/2。 
** 交换次数O(n),最好情况是，已经有序，交换0次；最坏情况是，逆序，交换n-1次。 
** 交换次数比冒泡排序少多了，由于交换所需CPU时间比比较所需的CPU时间多，n值较小时，选择排序比冒泡排序快。
*/
const int ARRAY_LEN = 10;

void select_sort(int *array,const int& length)
{
  if(length < 2)
    return ;

  for(int i = 0; i < length - 1; i++)
  {
    int min = i;

    for(int j = i +1; j < length; j++)
    {
      if(array[j] < array[min])
      {
        min = j;
      }
    }
    int tmp = array[i];
    array[i] = array[min];
    array[min] = tmp;
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
  int a[ARRAY_LEN] = {};
  int min = 1;
  int max = 500;
  getRandomArray(a,ARRAY_LEN,min,max);

  std::cout<<"before sorted!"<<std::endl;
  for(int i = 0; i < ARRAY_LEN; i++)
  {
    std::cout<<"a["<<i<<"] = "<<a[i]<<std::endl;
  }

  select_sort(a,ARRAY_LEN);

  std::cout<<"\n\n\n"<<"after sorted!"<<std::endl;
  for(int i = 0; i < ARRAY_LEN; i++)
  {
    std::cout<<"a["<<i<<"] = "<<a[i]<<std::endl;
  }

  return 0;
}