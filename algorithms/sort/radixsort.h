#ifndef RADIXSORT_H
#define RADIXSORT_H

#include "common.h"
#include "memory.h"

/**
  * �����д��Ƚ���ֵ(������)ͳһΪͬ������λ����,��λ�϶̵���ǰ�油��. Ȼ��, �����λ��ʼ,
  * ���ν���һ������.���������λ����һֱ�����λ��������Ժ�, ���оͱ��һ����������.
  *
  * ���������������
  *
  * ��������ķ�ʽ���Բ���LSD��Least significant digital����MSD��Most significant digital����
  * LSD������ʽ�ɼ�ֵ�����ұ߿�ʼ����MSD���෴���ɼ�ֵ������߿�ʼ��
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
    // ָ������
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

// �����Ǹ���
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
