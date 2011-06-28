#ifndef COCKTAILSORT_H
#define COCKTAILSORT_H

#include "common.h"

/**
  * 雞尾酒排序，也就是定向冒泡排序, 雞尾酒攪拌排序, 攪拌排序 (也可以視作選擇排序的一種變形),
  * 漣漪排序, 來回排序 or 快樂小時排序, 是冒泡排序的一種變形。此演算法與冒泡排序的不同處在於
  * 排序時是以雙向在序列中進行排序。效率比冒泡排序稍微好一点，
  * 复杂度： 雞尾酒排序最糟或是平均所花費的次數都是O(n2)，但如果序列在一開始已經大部分排序過
  * 的話，會接近O(n)。
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
