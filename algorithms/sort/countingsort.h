#ifndef COUNTINGSORT_H
#define COUNTINGSORT_H

#include "memory.h"

/**
  * 计数排序是一种稳定的排序算法。计数排序使用一个额外的数组C，其中第i个元素是待排序数组A中值
  * 等于i的元素的个数。然后根据数组C来将A中的元素排到正确的位置。
  *
  * 当输入的元素是 n 个 0 到 k 之间的整数时，它的运行时间是 Θ(n + k)。
  * 计数排序不是比较排序，排序的速度快于任何比较排序算法。
  *
  * 由于用来计数的数组C的长度取决于待排序数组中数据的范围（等于待排序数组的最大值与最小值的差
  * 加上1），这使得计数排序对于数据范围很大的数组，需要大量时间和内存。例如：计数排序是用来排
  * 序0到100之间的数字的最好的算法，但是它不适合按字母顺序排序人名。但是，计数排序可以用在基
  * 数排序中的算法来排序数据范围很大的数组。
  *
  * 算法的步骤如下：
  *     1.找出待排序的数组中最大和最小的元素
  *     2.统计数组中每个值为i的元素出现的次数，存入数组C的第i项
  *     3.对所有的计数累加（从C中的第一个元素开始，每一项和前一项相加）
  *     4.反向填充目标数组：将每个元素i放在新数组的第C(i)项，每放一个元素就将C(i)减去1
  *
  */

void countingSort( int array[], int length )
{
    int min = array[0];
    int max = array[1];

    for ( int i = 0; i < length; ++i )
    {
        if ( array[i] < min )
        {
            min = array[i];
        }
        else if ( array[i] > max )
        {
            max = array[i];
        }
    }

    int range = max - min + 1;
    int* tmp = ( int* ) malloc( range * sizeof( int ) );
    memset( tmp, 0, range );

    for ( int i = 0; i < length; ++i )
    {
        tmp[array[i] - min]++;
    }

    int n = 0;
    for ( int i = 0; i < range; ++i )
    {
        for ( int j = 0; i < tmp[i]; ++j )
        {
            array[n++] = i + min;
        }
    }
    free( tmp );
}

#endif // COUNTINGSORT_H
