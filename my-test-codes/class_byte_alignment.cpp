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
  �ֽڶ����ϸ�ںͱ�����ʵ����أ�   
  1)   �ṹ��������׵�ַ�ܹ��������������ͳ�Ա�Ĵ�С��������   
  2)   �ṹ��ÿ����Ա����ڽṹ���׵�ַ��ƫ������offset�����ǳ�Ա��С��������;   
  3)   �ṹ����ܴ�СΪ�ṹ�����������ͳ�Ա��С��������   
  */