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
  * 排序算法
  * http://zh.wikipedia.org/wiki/%E6%8E%92%E5%BA%8F%E7%AE%97%E6%B3%95#.E7.A9.A9.E5.AE.9A.E6.80.A7
  */

/**
  * 比较排序有很多性能上的根本限制。任何一种比较排序至少需要O(nlogn)比较操作。
  * 归并排序，堆排序在他们必须比较的次数上是渐进最优的。
  *
  * 非比较排序算法(基数排序，计数排序，桶排序)通过非比较操作能在O(n)完成，这使他们能够回避
  * O(nlogn)这个下界（假设元素是定值）。
  *
  * 比较排序在控制比较函数方面有显著优势，因此比较排序能对各种数据类型进行排序，并且可以很好
  * 地控制一个序列如何被排序。比较排序可以更好地适应复杂顺序（例如浮点数）。并且，一旦比较函
  * 数完成，任何比较算法都可以不经修改地使用；而非比较排序对数据类型的要求更严格。这种灵活性
  * 和上述比较排序在现代计算机的执行效率一起导致了比较排序被更多地应用在了大多数实际工作中。
  */

/**
  稳定:
    冒泡排序（bubble sort） — O(n2)
    鸡尾酒排序 (Cocktail sort,双向的冒泡排序) — O(n2)
    插入排序 （insertion sort）— O(n2)
    桶排序 （bucket sort）— O(n); 需要 O(k) 額外空間
    计数排序 (counting sort) — O(n+k); 需要 O(n+k) 額外空間
    归并排序 （merge sort）— O(n log n); 需要 O(n) 額外空間
    原地合併排序 — O(n2)
    二叉排序树排序 （Binary tree sort） — O(n log n)期望时间; O(n2)最坏时间; 需要 O(n)額外空間
    鸽巢排序 (Pigeonhole sort) — O(n+k); 需要 O(k) 額外空間
    基數排序 （radix sort）— O(n*k); 需要 O(n) 額外空間
    Gnome 排序 — O(n2)
    图书馆排序 — O(n log n) with high probability, 需要 (1+ε)n 額外空間

  不稳定：
    選擇排序 （selection sort）— O(n2)
    希爾排序 （shell sort）— O(n log n) 如果使用最佳的現在版本
    组合排序 — O(n log n)
    堆排序 （heapsort）— O(n log n)
    平滑排序 — O(n log n)
    快速排序 （quicksort）— O(n log n) 期望時間, O(n2) 最壞情況; 對於大的、亂數串列一般相信是最快的已知排序
    Introsort — O(n log n)
    Patience sorting — O(n log n + k) 最坏情況時間，需要 額外的 O(n + k) 空間，也需要找到最長的遞增子序列（longest increasing subsequence）
  */

/**
    交換排序法
        冒泡排序 | 鸡尾酒排序 | 奇偶排序 | 梳排序 | Gnome sort | 快速排序
    選擇排序法
        选择排序 | 堆排序
    插入排序法
        插入排序 | 希尔排序 | Tree sort | Library sort | Patience sorting
    归并排序法
        归并排序 | Strand sort
    非比較排序法
        基数排序 | 桶排序 | 计数排序 | 鸽巢排序 | Burstsort | Bead sort
    其他
        拓扑排序 | 排序網絡 | Bitonic sorter | Batcher odd-even mergesort | Pancake sorting
    低效排序法
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
    heapSort_Recursive( array, Array_Length );

//    heapSort_Loop( array, Array_Length );

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
    heapTest();
//    insertTest();
//    shellTest();
//    mergeTest();
//    countingTest();
//    radixTest();
    system("pause");
    return 0;
}
