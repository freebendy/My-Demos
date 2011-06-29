#include <cstdlib>

#include "bubblesort.h"
#include "cocktailsort.h"
#include "combsort.h"
#include "quicksort.h"
#include "selectionsort.h"
#include "heapsort.h"
//#include "heap.h"
#include "insertsort.h"
#include "shellsort.h"
#include "mergesort.h"
#include "countingsort.h"
#include "radixsort.h"

/**
  * �����㷨
  * http://zh.wikipedia.org/wiki/%E6%8E%92%E5%BA%8F%E7%AE%97%E6%B3%95#.E7.A9.A9.E5.AE.9A.E6.80.A7
  */

/**
  * �Ƚ������кܶ������ϵĸ������ơ��κ�һ�ֱȽ�����������ҪO(nlogn)�Ƚϲ�����
  * �鲢���򣬶����������Ǳ���ȽϵĴ������ǽ������ŵġ�
  *
  * �ǱȽ������㷨(�������򣬼�������Ͱ����)ͨ���ǱȽϲ�������O(n)��ɣ���ʹ�����ܹ��ر�
  * O(nlogn)����½磨����Ԫ���Ƕ�ֵ����
  *
  * �Ƚ������ڿ��ƱȽϺ����������������ƣ���˱Ƚ������ܶԸ����������ͽ������򣬲��ҿ��Ժܺ�
  * �ؿ���һ��������α����򡣱Ƚ�������Ը��õ���Ӧ����˳�����縡�����������ң�һ���ȽϺ�
  * ����ɣ��καȽ��㷨�����Բ����޸ĵ�ʹ�ã����ǱȽ�������������͵�Ҫ����ϸ����������
  * �������Ƚ��������ִ��������ִ��Ч��һ�����˱Ƚ����򱻸����Ӧ�����˴����ʵ�ʹ����С�
  */

/**
  �ȶ�:
    ð������bubble sort�� �� O(n2)
    ��β������ (Cocktail sort,˫���ð������) �� O(n2)
    �������� ��insertion sort���� O(n2)
    Ͱ���� ��bucket sort���� O(n); ��Ҫ O(k) �~����g
    �������� (counting sort) �� O(n+k); ��Ҫ O(n+k) �~����g
    �鲢���� ��merge sort���� O(n log n); ��Ҫ O(n) �~����g
    ԭ�غρ����� �� O(n2)
    �������������� ��Binary tree sort�� �� O(n log n)����ʱ��; O(n2)�ʱ��; ��Ҫ O(n)�~����g
    �볲���� (Pigeonhole sort) �� O(n+k); ��Ҫ O(k) �~����g
    �������� ��radix sort���� O(n*k); ��Ҫ O(n) �~����g
    Gnome ���� �� O(n2)
    ͼ������� �� O(n log n) with high probability, ��Ҫ (1+��)n �~����g

  ���ȶ���
    �x������ ��selection sort���� O(n2)
    ϣ������ ��shell sort���� O(n log n) ���ʹ����ѵĬF�ڰ汾
    ������� �� O(n log n)
    ������ ��heapsort���� O(n log n)
    ƽ������ �� O(n log n)
    �������� ��quicksort���� O(n log n) �����r�g, O(n2) �����r; ��춴�ġ��y������һ��������������֪����
    Introsort �� O(n log n)
    Patience sorting �� O(n log n + k) ���r�r�g����Ҫ �~��� O(n + k) ���g��Ҳ��Ҫ�ҵ����L���f�������У�longest increasing subsequence��
  */

/**
    ���Q����
        ð������ | ��β������ | ��ż���� | ������ | Gnome sort | ��������
    �x������
        ѡ������ | ������
    ��������
        �������� | ϣ������ | Tree sort | Library sort | Patience sorting
    �鲢����
        �鲢���� | Strand sort
    �Ǳ��^����
        �������� | Ͱ���� | �������� | �볲���� | Burstsort | Bead sort
    ����
        �������� | ����W�j | Bitonic sorter | Batcher odd-even mergesort | Pancake sorting
    ��Ч����
        Bogosort | Stooge sort
  */

const int Array_Length = 20;

void bubbleTest()
{
    int array[Array_Length];
    initArray( array, Array_Length );
    printf( "Before bubble sort:\n" );
    printArray( array, Array_Length );
    bubbleSort( array,Array_Length );
    printf( "\nAfter bubble sort:\n" );
    printArray( array, Array_Length );
}

void cocktailTest()
{
    int array[Array_Length];
    initArray( array, Array_Length );
    printf( "Before cocktail sort:\n" );
    printArray( array, Array_Length );
    cocktailSort( array,Array_Length );
    printf( "\nAfter cocktail sort:\n" );
    printArray( array, Array_Length );
}

void combTest()
{
    int array[Array_Length];
    initArray( array, Array_Length );
    printf( "Before comb sort:\n" );
    printArray( array, Array_Length );
    combSort( array, Array_Length );
    printf( "\nAfter comb sort:\n" );
    printArray( array, Array_Length );
}

void quickTest()
{
    int array[Array_Length];
    initArray( array, Array_Length );
    printf( "Before quick sort:\n" );
    printArray( array, Array_Length );
    quickSort( array, 0, Array_Length - 1 );
    printf( "\nAfter quick sort:\n" );
    printArray( array, Array_Length );
}

void selectionTest()
{
    int array[Array_Length];
    initArray( array, Array_Length );
    printf( "Before selection sort:\n" );
    printArray( array, Array_Length );
    selectionSort( array, Array_Length );
    printf( "\nAfter selection sort:\n" );
    printArray( array, Array_Length );
}

void heapTest()
{
    int array[Array_Length];
    initArray( array, Array_Length );
    printf( "Before heap sort:\n" );
    printArray( array, Array_Length );
    heapSort( array, Array_Length );
    printf( "\nAfter heap sort:\n" );
    printArray( array, Array_Length );
}

void insertTest()
{
    int array[Array_Length];
    initArray( array, Array_Length );
    printf( "Before insert sort:\n" );
    printArray( array, Array_Length );
    insertSort( array, Array_Length );
    printf( "\nAfter insert sort:\n" );
    printArray( array, Array_Length );
}

void shellTest()
{
    int array[Array_Length];
    initArray( array, Array_Length );
    printf( "Before shell sort:\n" );
    printArray( array, Array_Length );
    shellSort( array, Array_Length );
    printf( "\nAfter shell sort:\n" );
    printArray( array, Array_Length );
}

void mergeTest()
{
    int array[Array_Length];
    initArray( array, Array_Length );
    printf( "Before merge sort:\n" );
    printArray( array, Array_Length );
    mergeSort( array, 0, Array_Length - 1 );
    printf( "\nAfter merge sort:\n" );
    printArray( array, Array_Length );
}

void countingTest()
{
    int array[Array_Length];
    initArray( array, Array_Length, 1, 500 );
    printf( "Before counting sort:\n" );
    printArray( array, Array_Length );
    mergeSort( array, 0, Array_Length - 1 );
    printf( "\nAfter counting sort:\n" );
    printArray( array, Array_Length );
}

void radixTest()
{
    int array[Array_Length];
    initArray( array, Array_Length, 1, 500 );
    printf( "Before radix sort:\n" );
    printArray( array, Array_Length );
    mergeSort( array, 0, Array_Length - 1 );
    printf( "\nAfter radix sort:\n" );
    printArray( array, Array_Length );
}

int main(int argc, char *argv[])
{
//    bubbleTest();
//    cocktailTest();
//    combTest();
//    quickTest();
//    selectionTest();
//    heapTest();
//    insertTest();
//    shellTest();
//    mergeTest();
//    countingTest();
    radixTest();
    system("pause");
    return 0;
}
