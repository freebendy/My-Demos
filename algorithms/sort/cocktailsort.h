#ifndef COCKTAILSORT_H
#define COCKTAILSORT_H

#include "common.h"

/**
  * �uβ������Ҳ���Ƕ���ð������, �uβ�Ɣ�������, �������� (Ҳ����ҕ���x�������һ�N׃��),
  * �i������, ������� or �옷С�r����, ��ð�������һ�N׃�Ρ������㷨�cð������Ĳ�ͬ̎���
  * ����r�����p�����������M������Ч�ʱ�ð��������΢��һ�㣬
  * ���Ӷȣ� �uβ�������������ƽ�������M�ĴΔ�����O(n2)�������������һ�_ʼ�ѽ��󲿷������^
  * ��Ԓ�����ӽ�O(n)��
  */

void cocktailSort( int arr[], int length )
{
    int begin = 0;
    int end = length - 1;
    bool swapped = true;

    while( swapped )
    {
        swapped = false;
        for ( int i = begin; i < end - 1; i++ )
        {
            if ( arr[i] > arr[i + 1] )
            {
                swap( arr[i], arr[i + 1] );
                swapped = true;
            }
        }
        end--;

        for ( int j = end; j > begin; j-- )
        {
            if ( arr[j] < arr[j - 1] )
            {
                swap( arr[j], arr[j - 1] );
                swapped = true;
            }
        }
        begin++;
    }
}

#endif // COCKTAILSORT_H
