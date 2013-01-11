#include <stdio.h>
#include <omp.h>

int main() 
{
#pragma omp parallel num_threads(4)
  {
    int i = omp_get_thread_num();
    printf_s("Hello from thread %d\n", i);
  }
}


//int main()
//{
//    #pragma omp parallel for
//    for(int i=0;i<10;i++)
//    {
//        printf("i=%d\n",i) ;
//    }
//    return 0 ;
//}

