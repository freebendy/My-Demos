#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include "common.h"

/** 冒泡排序
  * 重复遍历数列，一次比较相连的2个元素，如果顺序错误就交换位置，最大或者最小的元素经过比较交换。
  * 慢慢“浮”到数组的数列。
  * 比较次数： O(n*n)
  * 交换次数： 最坏：O(n*n)
  * 原地排序，对于元素少的数列之外的排序非常没有效率，对已经排序好的数列也比较O(n*n)
  */

void bubbleSort( int arr[], int length )
{
    for ( int j = length - 1; j > 0; j-- )
    {
        for ( int i = 0; i < j - 1; i++ )
        {
            if ( arr[i] > arr[i + 1] )
            {
                swap( arr[i], arr[i + 1] );
            }
        }
    }
}

#endif // BUBBLESORT_H
