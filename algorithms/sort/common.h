#ifndef COMMON_H
#define COMMON_H
#include <time.h>
#include <stdio.h>

void swap( int& a, int& b )
{
    int tmp = a;
    a = b;
    b = tmp;
}

void initArray( int arr[], int length )
{
    srand( time(NULL) );
    for ( int i = 0; i < length; i++ )
    {
        arr[i] = rand();
    }
}

void initArray( int arr[], int length, int min, int max )
{
    srand( time(NULL) );
    for ( int i = 0; i < length; i++ )
    {
        arr[i] = min + rand() % ( max - min + 1 );
    }
}

void printArray( int arr[], int length )
{
    for ( int i = 0; i < length; i++ )
    {
        printf( "array[%d] = %d\n", i, arr[i] );
    }
}

void printArray( int arr[], int left, int right )
{
    for ( int i = left; i < right; i++ )
    {
        printf( "array[%d] = %d\n", i, arr[i] );
    }
}

#endif // COMMON_H
