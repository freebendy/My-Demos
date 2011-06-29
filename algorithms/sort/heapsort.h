#ifndef HEAPSORT_H
#define HEAPSORT_H

#include "common.h"
#include "math.h"

/**
  * ���������ö��������ݽṹ��Ƶ�һ�������㷨������һ��������ȫ�������Ľ����ͬʱ����ѵ���
  * �ԣ��ӽڵ�ļ�ֵ����С��(���ߴ���)���ڵ�ļ�ֵ��
  *
  * ��������ʱ�临�Ӷȶ��� O(n*logn)
  * ���ռ临�Ӷ�: O(n) total, O(1) auxiliary.
  * ���ȶ����������顣
  */

/**
    ͨ����(heap)��ͨ�^һά�����ʵ�ֵġ��ڿ�ʼindexΪ 0 �������У�
        1.�ѵĸ����c�����ѵ����ֵ����������λ�� 1 �ĵط�;
            ע�⣺��ʹ��λ�� 0����t��������ԶΪ0
        2.���ڵ�i�����ӽڵ���λ�� (2*i);
        3.���ڵ�i�����ӽڵ���λ�� (2*i+1);
        4.�ӽڵ�i�ĸ��ڵ���λ�� floor(i/2);
  */

/**
    ���ж������¼��ֲ�����
        1.���ѵ�����Max_Heapify�������ѵ�ĩ���ӽڵ�������,ʹ���ӽڵ���ԶС춸��ڵ�
        2.�������ѣ�Build_Max_Heap������������������������
        3.������HeapSort�����Ƴ�λ�ڵ�һ�����ݵĸ��ڵ�,�K�����ѵ����ĵݹ�����

    ���̣�
        1.����һ����H[0..n-1]
        2.�Ѷ��ף����ֵ���Ͷ�β����
        3.�Ѷѵĳߴ���С1��������Max_Heapify(0),Ŀ���ǰ��µ����鶥�����ݵ�������Ӧλ��
        4.�ظ�����2��ֱ���ѵĳߴ�Ϊ1
  */

// index ��0��ʼ����1����

// Get parent index
int parent( int i )
{
    return floor( ( i - 1 ) / 2 );
}

// Gte left child index
int left( int i )
{
    return 2*i + 1;
}

// Gte right child index
int right( int i )
{
    return 2*i + 2;
}

void Max_Heapify( int array[], int length, int i )
{
    int l = left( i );
    int r = right( i );
    int largest = i;
    if ( l < length && array[l] > array[largest] )
    {
        largest = l;
    }

    if ( r < length && array[r] > array[largest] )
    {
        largest = r;
    }

    if ( largest != i )
    {
        swap( array[i], array[largest] );
        Max_Heapify( array, length, largest );
    }
}

void Build_Max_Heap( int array[],int length )
{
    for ( int i = length - 1; i >= 0; i-- )
    {
        Max_Heapify( array, length, i );
    }
}

void heapSort( int array[], int length )
{
    Build_Max_Heap( array, length );
    int size = length;
    for ( int i = length -1; i >=1; i-- )
    {
        swap( array[0], array[i] );
        size--;
        Max_Heapify( array, size, 0 );
    }
}

#endif // HEAPSORT_H
