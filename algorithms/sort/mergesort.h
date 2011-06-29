#ifndef MERGESORT_H
#define MERGESORT_H

#include "common.h"
#include "memory.h"

/** ���η���Divide and Conquer��
  *
  * �鲢�����Ĺ������£�
  *     1.����ռ䣬ʹ���СΪ�����Ѿ���������֮�ͣ��ÿռ�������źϲ��������
  *     2.�趨����ָ�룬���λ�÷ֱ�Ϊ�����Ѿ��������е���ʼλ��
  *     3.�Ƚ�����ָ����ָ���Ԫ�أ�ѡ�����С��Ԫ�ط��뵽�ϲ��ռ䣬���ƶ�ָ�뵽��һλ��
  *     4.�ظ�����3ֱ��ĳһָ��ﵽ����β
  *     5.����һ����ʣ�µ�����Ԫ��ֱ�Ӹ��Ƶ��ϲ�����β
  *
  * �Ƚϲ����Ĵ�������(n*logn) / 2��n*logn ? n + 1�� ��ֵ�����Ĵ�����(2n*logn)��
  * ���ʱ�临�Ӷȣ� O(n*logn) ���ʱ�临�Ӷȣ� O(n)
  * ���ռ临�Ӷȣ� O(n)
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
