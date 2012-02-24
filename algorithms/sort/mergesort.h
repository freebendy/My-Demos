#ifndef MERGESORT_H
#define MERGESORT_H

#include "common.h"
#include "memory.h"

/** 分治法（Divide and Conquer）
  *
  * 归并操作的过程如下：
  *     1.申请空间，使其大小为两个已经排序序列之和，该空间用来存放合并后的序列
  *     2.设定两个指针，最初位置分别为两个已经排序序列的起始位置
  *     3.比较两个指针所指向的元素，选择相对小的元素放入到合并空间，并移动指针到下一位置
  *     4.重复步骤3直到某一指针达到序列尾
  *     5.将另一序列剩下的所有元素直接复制到合并序列尾
  *
  * 比较操作的次数介于(n*logn) / 2和n*logn ? n + 1。 赋值操作的次数是(2n*logn)。
  * 最差时间复杂度： O(n*logn) 最好时间复杂度： O(n)
  * 最差空间复杂度： O(n)
  *
  */

void merge( int array[], int first, int mid, int last )
{
    int beg1 = first;
    int end1 = mid;
    int beg2 = mid + 1;
    int end2 = last;
    int* temp = ( int* ) malloc( ( last - first + 1 ) * sizeof( int ) );

    int i = 0;
    for ( ; beg1 <= end1 && beg2 <= end2; i++ )
    {
        if ( array[beg1] < array[beg2] )
        {
            temp[i] = array[beg1++];
        }
        else
        {
            temp[i] = array[beg2++];
        }
    }

    if ( beg1 <= end1 )
    {
        memcpy( temp + i, array + beg1, ( end1 - beg1 + 1 ) * sizeof( int ) );
    }

    if ( beg2 <= end2 )
    {
        memcpy( temp + i, array + beg2, ( end2 - beg2 + 1 ) * sizeof( int ) );
    }

    memcpy( array + first, temp, ( last - first + 1 ) * sizeof( int ) );
    free(temp);
}

void mergeSort( int array[], int first, int last )
{
    if ( last > first )
    {
        int mid = ( last + first ) / 2;

        mergeSort( array, first, mid );
        mergeSort( array, mid + 1, last );
        merge( array, first, mid, last );
    }

}

#endif // MERGESORT_H
