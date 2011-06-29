#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "common.h"

/**
  * 分治法（Divide and Conquer）
  *
  * 以平均效能來說，排序 n 個項目要Θ(n*logn)次比較。然而，在最壞的效能下，它需要Θ(n*n)次比
  * 較。一般來說，快速排序實際上明顯地比其他Θ(n*logn) 演算法更快，因為它的內部循环（inner loop）
  * 可以在大部分的架構上很有效率地被實作出來，且在大部分真實世界的資料，可以決定設計的選擇，
  * 減少所需時間的二次方項之可能性。
  *
  * 步驟為：
  * 1.從數列中挑出一個元素，稱為 "基準"（pivot），
  * 2.重新排序數列，所有元素比基準值小的擺放在基準前面，所有元素比基準值大的擺在基準的後面
  * （相同的數可以到任一邊）。在這個分割結束之後，該基準就處於數列的中間位置。這個稱為分割（partition）操作。
  * 3.递归地（recursive）把小於基准值元素的子數列和大於基准值元素的子數列排序。
  *
  */

/**
  * 快速排序是二叉查找树的一个空间优化版本。不用循环把项插入到一个明确的树中，而是由快速排序
  * 组织这些项到一个由递归调用所包含的树中。两种算法产生相同的比较次数，但是顺序不同。
  *
  * 堆排序通常比快速排序微慢，但是最坏的执行情况总是O(n*logn)。快速排序通常比较快，除了
  * introsort变化版本外仍然会有最坏情况的机会。如果事先知道堆排序將會是需要使用的，那么直接
  * 地使用堆排序比等待 introsort 再切换到它还要快。堆排序也拥有重要的特点，仅使用固定额外的
  * 空间（堆排序是原地排序），而即使是最佳的快速排序变化版本也需要Θ(log n)的空間。然而，堆排
  * 序需要有效率的随机存取才能变成可行。
  *
  * 归并排序（Mergesort）是另外一種递归排序算法，但有坏情況O(n log n)执行时间的优势。不像
  * 快速排序或堆排序，归并排序是一個稳定排序，且可以轻易地被采用在链表（linked list）和储存
  * 在慢速存取媒介上如磁碟储存或网络链接储存的非常巨大数列。尽管快速排序可以被重新改写使用在
  * 链表上，但是它通常會因為无法随机存取而倒置差的基准选择。归并排序的主要缺点，是在最佳情況
  * 下需要Ω(n)额外的空间。
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
        int pivotIndex = ( right + left ) / 2;
        int partitionIndex = partition( array, left, right, pivotIndex );
        quickSort( array, left, partitionIndex - 1 );
        quickSort( array, partitionIndex + 1, right );
    }
}

#endif // QUICKSORT_H
