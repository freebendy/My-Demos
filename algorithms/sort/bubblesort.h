#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include "common.h"

/** ð������
  * �ظ��������У�һ�αȽ�������2��Ԫ�أ����˳�����ͽ���λ�ã���������С��Ԫ�ؾ����ȽϽ�����
  * ��������������������С�
  * �Ƚϴ����� O(n*n)
  * ���������� ���O(n*n)
  * ԭ�����򣬶���Ԫ���ٵ�����֮�������ǳ�û��Ч�ʣ����Ѿ�����õ�����Ҳ�Ƚ�O(n*n)
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
