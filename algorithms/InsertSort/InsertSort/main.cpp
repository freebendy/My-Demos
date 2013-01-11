#include <iostream>
#include <cstdlib>
#include <ctime>
/* 
** ��������
** ʱ�临�Ӷȣ�O(n*n)
** �ռ临�Ӷȣ�1
** �ȶ�
*/

/*
** ���Ŀ���ǰ�n��Ԫ�ص������������У����N���ò���������������r�������r��
** �����r���ǣ������ѽ������������ˣ����@�N��r�£���Ҫ�M�еı��^������(n-1)�μ��ɡ�
** �����r���ǣ������ǽ������У����N�˕r��Ҫ�M�еı��^����n(n-1)/2�Ρ�
** ����������xֵ�����Ǳ��^�����ĴΔ��pȥ(n-1)�Ρ�ƽ�����f�����������㷨�}�s�Ȟ�O(n2)��
** ��������������m�ό�추��������^��������á�
** ���ǣ������Ҫ����Ĕ�������С�����磬����С�ǧ�����N��������߀��һ�����e���x��
*/
const int ARRAY_LEN = 10;

void insert_sort(int *array,const int& length)
{
	if(length < 2)
		return ;

	for(int i = 1; i < length; i ++)
	{
		int tmp = array[i];
		int j = i - 1;
		
		while( j >= 0 && array[j] > tmp)
		{
			array[j + 1] = array[j];
			j --;
		}
		array[j + 1] = tmp;
	}
}

void insert_sort1(int *array,const int& length)
{
  if(length < 2)
    return ;

  int temp;
  for(int i=1;i<length;i++)
  {
    temp = array[i];//store the original sorted array in temp
    int j = i;
    for(; j>0 && temp < array[j-1] ; j--)//compare the new array with temp(maybe -1?)
    {
      array[j]=array[j-1];//all larger elements are moved one pot to the right
    }
    array[j]=temp;
  }
}

void getRandomArray(int *array,const int& length,const int& min,const int& max)
{
	if(length < 1)
		return ;
	srand(time(NULL));
	for(int i = 0 ; i < length; i++)
	{
		array[i] = min + rand() % (max - min + 1);
	}
}

int main(int argc,char ** argv)
{
	//int a[10] = {3,3445,8,1,4534,876,32,3479,12,-1};
	int a[ARRAY_LEN] = {};
	int min = 1;
	int max = 500;
	getRandomArray(a,ARRAY_LEN,min,max);

	std::cout<<"before sorted!"<<std::endl;
	for(int i = 0; i < ARRAY_LEN; i++)
	{
		std::cout<<"a["<<i<<"] = "<<a[i]<<std::endl;
	}

	insert_sort1(a,ARRAY_LEN);

	std::cout<<"\n\n\n"<<"after sorted!"<<std::endl;
	for(int i = 0; i < ARRAY_LEN; i++)
	{
		std::cout<<"a["<<i<<"] = "<<a[i]<<std::endl;
	}

	/*for(int i = 0; i < argc; i ++)
	{
		std::cout<<"argv["<<i<<"] = "<<argv[i]<<std::endl;
	}*/

	//system("pause");
	return 0;
}