#include <stdio.h> 
#include <stdlib.h> 
#define N 41 
#define M 3 

//ģ���㷨
//int main(void) { 
//    int man[N] = {0}; 
//    int count = 1; 
//    int i = 0, pos = -1; 
//    int alive = 0; 
//
//    while(count <= N) { 
//        do { 
//            pos = (pos+1) % N;  // �h��̎�� 
//            if(man[pos] == 0) 
//                i++; 
//
//            if(i == M) {  // �󔵞�3�� 
//                i = 0; 
//                break; 
//            } 
//        } while(1); 
//
//        man[pos] = count; 
//        count++; 
//    } 
//
//    printf("\n�s�ٷ����У�"); 
//    for(i = 0; i < N; i++) 
//        printf("%d ", man[i]); 
//
//    while(1)
//    {
//        printf("\n\n����Ҫ�ȶ����ˣ�(����'0'�˳���)"); 
//        scanf("%d", &alive); 
//
//        if(alive == 0)
//            break ;
//        printf("\nL��ʾ�@%d��Ҫ�ŵ�λ�ã�\n", alive); 
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


//��ѧ����
//���ƹ�ʽ
//f[1]=0;
//f[i]=(f[i-1]+m) mod i;       (i>1)

int main()
{
       int n, m, i, s=0;
       int stay ;

       printf ("�����������N = "); 
       scanf("%d", &n);

       printf ("���뱨��ѭ��M = "); 
       scanf("%d", &m);

       //printf ("������������ STAY = "); 
       //scanf("%d", &stay);

       for (i=2; i<=n; i++) 
           s=(s+m)%i;

       printf ("The winner is %d\n", s+1);
       return 0;
}