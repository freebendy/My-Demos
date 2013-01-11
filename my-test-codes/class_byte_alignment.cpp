 #include <stdio.h>
 int   main()   
  {     char   c1;   
      int   i;   
      short   s;   
      int   j;   
  struct   A{   
      char   c1;   
      int   i;   
      short   s;   
      int   j;   
  }a;   
  struct   B{   
      int   i;   
      int   j;       
      short   s;   
      char   c1;   
  }b;   
  printf("%d,",sizeof(c1));   
  printf("%d,",sizeof(i));   
  printf("%d,",sizeof(s));   
  printf("%d,",sizeof(j));   
  printf("%d,",sizeof(a));   
  printf("%d",sizeof(b));   
  return 0;
  }
  
  /*
  字节对齐的细节和编译器实现相关：   
  1)   结构体变量的首地址能够被其最宽基本类型成员的大小所整除；   
  2)   结构体每个成员相对于结构体首地址的偏移量（offset）都是成员大小的整数倍;   
  3)   结构体的总大小为结构体最宽基本类型成员大小的整数倍   
  */