#include <iostream>
#include <cstdlib>
#include <ctime>

/* 
** 冒泡排序
** 时间复杂度：O(n*n)
** 空间复杂度：1
** 稳定
*/

/*
** 它重複地走訪過要排序的數列，一次比較兩個元素，如果他們的順序錯誤就把他們交換過來。
** 走訪數列的工作是重複地進行直到沒有再需要交換，也就是說該數列已經排序完成。
** 這個算法的名字由來是因為越小的元素會經由交換慢慢「浮」到數列的頂端。
*/

/*
** 冒泡排序對n個項目需要O(n2)的比較次數，且可以原地排序。
** 儘管這個演算法是最簡單瞭解和實作的排序算法之一，但它對於少數元素之外的數列排序是很沒有效率的。
*/

/*
** 冒泡排序是與插入排序擁有相等的執行時間，但是兩種法在需要的交換次數卻很大地不同。
** 在最壞的情況，冒泡排序需要O(n2)次交換，而插入排序只要最多O(n)交換。
** 天真的冒泡排序實作（類似下面）通常會對已經排序好的數列拙劣地執行（O(n2)），而插入排序在這個例子只需要O(n)個運算。
** 因此很多現代的演算法教科書避免使用冒泡排序，而用插入排序取代之。
** 冒泡排序如果能在內部迴圈第一次執行時，使用一個旗標來表示有無需要交換的可能，也有可能把最好的複雜度降低到O(n)。
** 在這個情況，在已經排序號的數列就無交換的需要。若在每次走訪數列時，把走訪順序和比較大小反過來，也可以些微地改進效率。
** 有時候稱為往返排序（en:shuttle sort），因為演算法會從數列的一端到另一端之間穿梭往返。
*/

const int ARRAY_LEN = 10;

void bubble_sort(int *array,const int& length)
{
  if(length < 2)
    return ;

  for(int i = length; i > 0; i --)
  {
    for(int j =0;j < i - 1; j ++)
    {
      if(array[j] > array[j + 1])
      {
        int tmp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = tmp;
      }
    }
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

  bubble_sort(a,ARRAY_LEN);

  std::cout<<"\n\n\n"<<"after sorted!"<<std::endl;
  for(int i = 0; i < ARRAY_LEN; i++)
  {
    std::cout<<"a["<<i<<"] = "<<a[i]<<std::endl;
  }

  return 0;
}