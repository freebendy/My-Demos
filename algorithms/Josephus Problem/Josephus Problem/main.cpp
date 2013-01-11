#include <stdio.h> 
#include <stdlib.h> 
#define N 41 
#define M 3 

//模拟算法
//int main(void) { 
//    int man[N] = {0}; 
//    int count = 1; 
//    int i = 0, pos = -1; 
//    int alive = 0; 
//
//    while(count <= N) { 
//        do { 
//            pos = (pos+1) % N;  // 環狀處理 
//            if(man[pos] == 0) 
//                i++; 
//
//            if(i == M) {  // 報數為3了 
//                i = 0; 
//                break; 
//            } 
//        } while(1); 
//
//        man[pos] = count; 
//        count++; 
//    } 
//
//    printf("\n約琴夫排列："); 
//    for(i = 0; i < N; i++) 
//        printf("%d ", man[i]); 
//
//    while(1)
//    {
//        printf("\n\n您想要救多少人？(输入'0'退出！)"); 
//        scanf("%d", &alive); 
//
//        if(alive == 0)
//            break ;
//        printf("\nL表示這%d人要放的位置：\n", alive); 
//        for(i = 0; i < N; i++) { 
//            if(man[i] < 41 - alive + 1) 
//                printf("D"); 
//            else 
//                printf("L"); 
//
//            if((i+1) % 5 == 0) 
//                printf("  "); 
//        } 
//        printf("\n"); 
//    }
//
//    return 0; 
//}


//数学方法
//递推公式
//f[1]=0;
//f[i]=(f[i-1]+m) mod i;       (i>1)

int main()
{
       int n, m, i, s=0;
       int stay ;

       printf ("输入参与人数N = "); 
       scanf("%d", &n);

       printf ("输入报数循环M = "); 
       scanf("%d", &m);

       //printf ("输入留下人数 STAY = "); 
       //scanf("%d", &stay);

       for (i=2; i<=n; i++) 
           s=(s+m)%i;

       printf ("The winner is %d\n", s+1);
       return 0;
}