#include<iostream>
#include<conio.h>
#include<cstdio>
using namespace std;
char*     PArr[10]={0};     //������ΪA��
char*    _inPutArr(char Arr[],int len);
char **  inPutArr(char Arr[][30],int LLen=10,int RLen=30);
void     outPut(char **PP,int LLen);

int main()
{
    char Array[10][30]={0}; //char* Array[30]={0}
    int LLen=10,RLen=30;
    cout<<"������10�������ַ�����"<<endl<<"          ע���ݶ����ǳ��Ȳ�����30"<<endl;
    char**PP=NULL;
    PP=inPutArr(Array);
    outPut( PP, LLen );
	return 0;
}


char*  _inPutArr(char Arr[],int len)
{ //���û������һ���ַ�װ��װ��Arr����
    char CH;     
	CH=getchar();  
    char BLANK=' '; 
	char ENTER='\n';
    int count=0;
    while(CH!=BLANK&&CH!=ENTER)
    {
        Arr[count]=CH;         //put-Arr
        ++count;
        CH=getchar();              
		if(count==(len-1)) 
			break; //char����Ĭ����'\0'��β��
    }  
      return Arr;
}

char **  inPutArr(char Arr[][30],int LLen,int RLen)
{//���û������ʮ���ַ���װ��10������
                             //����һ�У�������ΪB��
     for( int i=0;i<LLen;++i)
    {  
        PArr[i]=_inPutArr(Arr[i],RLen);
    }
    return PArr;  
}

void outPut(char **PP,int LLen )
{
    for(int i=0;i<LLen;++i)
               cout<<i<<"   ��"<<PP[i]<<endl;
}

/*

1������ָ��ʱ��������ʱָ��Ϸ�����Ȼȫ����Ϸ���
2������ָ���ָ��ʱ������ȫ��ָ���ָ��Ϸ���
                     ������ʱָ���ָ��Ƿ���
*/
