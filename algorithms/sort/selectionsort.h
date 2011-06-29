#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include "common.h"

/**
  * ������δ�����������ҵ���СԪ�أ���ŵ��������е���ʼλ�ã�Ȼ���ٴ�ʣ��δ����Ԫ���м���
  * Ѱ����СԪ�أ�Ȼ��ŵ���������ĩβ���Դ����ƣ�ֱ������Ԫ�ؾ�������ϡ�
  * ������������0��n-1֮�䣬�Ƚϲ���Ϊn(n-1)/2����ֵ��������0~3(n-1)֮�䡣
  * ��������O(n),�������ǣ��Ѿ����򣬽���0�Σ������ǣ����򣬽���n-1�Ρ� ����������ð
  * �������ٶ��ˣ����ڽ�������CPUʱ��ȱȽ������CPUʱ��࣬nֵ��Сʱ��ѡ�������ð������졣
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
