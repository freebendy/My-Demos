#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include "common.h"

/**
  * 首先在未排序序列中找到最小元素，存放到排序序列的起始位置，然后，再从剩余未排序元素中继续
  * 寻找最小元素，然后放到排序序列末尾。以此类推，直到所有元素均排序完毕。
  * 交换次数介于0～n-1之间，比较操作为n(n-1)/2，赋值操作介于0~3(n-1)之间。
  * 交换次数O(n),最好情况是，已经有序，交换0次；最坏情况是，逆序，交换n-1次。 交换次数比冒
  * 泡排序少多了，由于交换所需CPU时间比比较所需的CPU时间多，n值较小时，选择排序比冒泡排序快。
  *
  */

void selectionSort( int array[], int length )
{
    for ( int i = 0; i < length - 1; i++ )
    {
        int min = i;
        for ( int j = i + 1; j < length; j++ )
        {
            if ( array[min] > array[j] )
            {
                min = j;
            }
        }
        swap( array[i], array[min] );
    }
}

#endif // SELECTIONSORT_H
