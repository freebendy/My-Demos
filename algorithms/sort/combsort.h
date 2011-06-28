#ifndef COMBSORT_H
#define COMBSORT_H

#include "common.h"

/**
  * 梳排序是改良自泡沫排序和快速排序，其要旨在於消除烏龜，亦即在陣列尾部的小數值，這些數值是
  * 造成泡沫排序緩慢的主因。相對地，兔子，亦即在陣列前端的大數值，不影響泡沫排序的效能。
  *
  * 在泡沫排序中，只比較陣列中相鄰的二項，即比較的二項的間距(Gap)是1，梳排序提出此間距其實可
  * 大於1，改自插入排序的希爾排序同樣提出相同觀點。梳排序中，開始時的間距設定為陣列長度，並在
  * 迴圈中以固定比率遞減，通常遞減率設定為1.3。在一次迴圈中，梳排序如同泡沫排序一樣把陣列從首
  * 到尾掃描一次，比較及交換兩項，不同的是兩項的間距不固定於1。如果間距遞減至1，梳排序假定輸
  * 入陣列大致排序好，並以泡沫排序作最後檢查及修正。
  *
  * 最有效遞減率為1.3(1.247330950103979)的。如果此比率太小，則導致一迴圈中有過多的比較，
  * 如果比率太大，則未能有效消除陣列中的烏龜。
  *
  * 設定遞減率為1.3時，最後只會有三種不同的間距組合：(9, 6, 4, 3, 2, 1)、
  * (10, 7, 5, 3, 2, 1)、或 (11, 8, 6, 4, 3, 2, 1)。實驗證明，如果間距變成9或10時一律
  * 改作11，則對效率有明顯改善，原因是如果間距曾經是9或10，則到間距變成1時，數值通常不是遞增
  * 序列，故此要進行幾次泡沫排序迴圈修正。
  *
  * 如同快速排序和合併排序，梳排序的效率在開始時最佳，接近結束時，即進入泡沫排序時最差。如果
  * 間距變得太小時（例如小於10），改用諸如插入排序或雞尾酒排序等算法，則可提昇整體效能。
  *
  */

const float Shrink = 1.247330950103979;

void combSort( int array[], int length )
{
    int gap = length;
    bool swapped = true;

    while ( gap > 1 || swapped )
    {
        if ( gap > 1 )
        {
            gap = gap / 1;
        }

        swapped = false;

        for ( int i = 0; gap + i < length; i++ )
        {
            if ( array[i] > array[gap + i] )
            {
                swap( array[i], array[gap + i] );
                swapped = true;
            }
        }
    }

}

#endif // COMBSORT_H
