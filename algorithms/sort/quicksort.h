#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "common.h"

/**
  * ��ƽ��Ч�܁��f������ n ���ĿҪ��(n*logn)�α��^��Ȼ��������ĵ�Ч���£�����Ҫ��(n*n)�α�
  * �^��һ����f�����������H�����@�ر�������(n*logn) ���㷨���죬������ăȲ�ѭ����inner loop��
  * �����ڴ󲿷ֵļܘ��Ϻ���Ч�ʵر������������ڴ󲿷��挍������Y�ϣ����ԛQ���OӋ���x��
  * �p������r�g�Ķ��η��֮�����ԡ�
  *
  * ���E�飺
  * 1.�Ĕ���������һ��Ԫ�أ��Q�� "����"��pivot����
  * 2.���������У�����Ԫ�رȻ���ֵС�Ĕ[���ڻ���ǰ�棬����Ԫ�رȻ���ֵ��Ĕ[�ڻ��ʵ�����
  * ����ͬ�Ĕ����Ե���һ߅�������@���ָ�Y��֮�ᣬԓ���ʾ�̎추��е����gλ�á��@���Q��ָpartition��������
  * 3.�ݹ�أ�recursive����С춻�׼ֵԪ�ص��Ӕ��кʹ�춻�׼ֵԪ�ص��Ӕ�������
  *
  *
  *
  */

int partition( int array[], int left, int right, int pivotIndex )
{
    int pivotValue = array[pivotIndex];
    swap( array[pivotIndex], array[right] );

    int storeIndex = left;

    for ( int i = left; i < right; i++ )
    {
        if ( array[i] < pivotValue )
        {
            swap( array[storeIndex], array[i] );
            storeIndex++;
        }
    }
    swap( array[storeIndex], array[right] );
    printArray( array, left, right );
    return storeIndex;
}

void quickSort( int array[], int left, int right )
{
    if ( right > left )
    {
        int pivotIndex = ( right - left ) / 2 + left;
        int partitionIndex = partition( array, left, right, pivotIndex );
        quickSort( array, left, partitionIndex - 1 );
        quickSort( array, partitionIndex + 1, right );
    }
}

#endif // QUICKSORT_H
