#ifndef RADIXSORT_H
#define RADIXSORT_H

#include "common.h"
#include "memory.h"

/**
  * 将所有待比较数值(正整数)统一为同样的数位长度,数位较短的数前面补零. 然后, 从最低位开始,
  * 依次进行一次排序.这样从最低位排序一直到最高位排序完成以后, 数列就变成一个有序序列.
  *
  * 适用于数组和链表
  *
  * 基数排序的方式可以采用LSD（Least significant digital）或MSD（Most significant digital），
  * LSD的排序方式由键值的最右边开始，而MSD则相反，由键值的最左边开始。
  */

struct item
{
    int value;
    item* next;
};

void deleteItem( item* i )
{
    if ( i )
    {
        if ( i->next )
        {
            deleteItem( i->next );
        }
        else
        {
            free( i );
        }
    }
}

void release( item* array[], int length )
{
    for ( int i = 0; i < length; ++i )
    {
        deleteItem( array[i] );
    }
}

void baseSort( int array[], int length, int base )
{
    // 指针数组
    item* tmp[10];
    memset( tmp, NULL, 10 );

    for ( int i = 0; i < length; ++i )
    {
        int dividend = floor( array[i] / pow( 10, base ) );
        int remainder = dividend % 10;
        item* newItem = ( item* ) malloc( sizeof( item ) );
        newItem->value = array[i];
        newItem->next = NULL;
        if ( tmp[remainder] == NULL )
        {
            tmp[remainder] = newItem;
        }
        else
        {
            item* nextItem = tmp[remainder];
            while( nextItem->next )
            {
                nextItem = nextItem->next;
            }
            nextItem->next = newItem;
        }
    }

    int n = 0;
    for ( int i = 0; i < 10; ++i )
    {
        item* tmpItem = tmp[i];
        while ( tmpItem != NULL )
        {
            array[n++] = tmpItem->value;
            tmpItem = tmpItem->next;
        }
    }

    release( tmp, 10 );
}

// 不考虑负数
void radixSort( int array[], int length )
{
    int max = array[0];
    for ( int i = 0; i < length; ++i )
    {
        if ( array[i] > max )
        {
            max = array[i];
        }
    }

    if ( max > 0 )
    {
        int n = 0;

        do
        {
            ++n;
            max = max / 10;
        }
        while ( max > 0 );

        for ( int i = 0; i <= n; ++i )
        {
            baseSort( array, length, i );
        }
    }
}

#endif // RADIXSORT_H
