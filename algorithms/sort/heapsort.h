#ifndef HEAPSORT_H
#define HEAPSORT_H

#include "common.h"
#include "math.h"

/**
  * 堆排序利用堆这种数据结构设计的一种排序算法。堆是一个近似完全二叉树的结果，同时满足堆的特
  * 性：子节点的键值总是小于(或者大于)父节点的键值。
  *
  * 最差和最优时间复杂度都是 O(n*logn)
  * 最差空间复杂度: O(n) total, O(1) auxiliary.
  * 不稳定，用于数组。
  */

/**
    通常堆(heap)是通過一维数组來实现的。在开始index为 0 的情形中：
        1.堆的根節點（即堆的最大值）存放在陣列位置 1 的地方;
            注意：不使用位置 0，否則左子树永远为0
        2.父节点i的左子节点在位置 (2*i);
        3.父节点i的右子节点在位置 (2*i+1);
        4.子节点i的父节点在位置 floor(i/2);
  */

/**
    堆中定义以下几种操作：
        1.最大堆调整（Max_Heapify）：將堆的末端子节点作调整,使得子节点永远小於父节点
        2.建立最大堆（Build_Max_Heap）：將堆所有数据重新排序
        3.堆排序（HeapSort）：移除位在第一個数据的根节点,並做最大堆调整的递归运算

    过程：
        1.建立一个堆H[0..n-1]
        2.把堆首（最大值）和堆尾互换
        3.把堆的尺寸缩小1，并调用Max_Heapify(0),目的是把新的数组顶端数据调整到相应位置
        4.重复步骤2，直到堆的尺寸为1

    最大堆 -> 递减数组
    最小堆 -> 递增数组
  */

// index 从0开始，加1修正

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

// 递归版本
void Max_Heapify_Recursive( int array[], int length, int i )
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
        Max_Heapify_Recursive( array, length, largest );
    }
}

// 循环版本
void Max_Heapify_Loop( int array[], int i )
{
    int index = i;
    while (index > 0)
    {
        int p = parent(index);
        if (array[p] >= array[index])
            break;

        swap( array[index], array[p] );
        index = p;
    }
}

// 构建最大堆
void Build_Max_Heap_Recursive( int array[],int length )
{
    for ( int i = length - 1; i >= 0; --i )
    {
        Max_Heapify_Recursive( array, length, i );
    }
}

// 构建最大堆
void Build_Max_Heap_Loop( int array[],int length )
{
    for ( int i = 0; i < length; ++i )
    {
        Max_Heapify_Loop( array, i );
    }
}

void heapSort_Recursive( int array[], int length )
{
    Build_Max_Heap_Recursive( array, length );
    for ( int i = length - 1; i > 0; i-- )
    {
        swap( array[0], array[i] );
        Max_Heapify_Recursive( array, i, 0 );
    }
}

void heapSort_Loop( int array[], int length )
{
    Build_Max_Heap_Loop( array, length );
    for ( int i = length - 1; i > 0; --i )
    {
        swap( array[0], array[i] );
        Build_Max_Heap_Loop( array, i);
    }
}

#endif // HEAPSORT_H
