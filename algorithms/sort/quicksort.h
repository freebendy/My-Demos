#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "common.h"

/**
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
