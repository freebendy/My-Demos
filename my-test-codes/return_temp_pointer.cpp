#include<iostream>
#include<conio.h>
#include<cstdio>
using namespace std;
char*     PArr[10]={0};     //这里标记为A行
char*    _inPutArr(char Arr[],int len);
char **  inPutArr(char Arr[][30],int LLen=10,int RLen=30);
void     outPut(char **PP,int LLen);

int main()
{
    char Array[10][30]={0}; //char* Array[30]={0}
    int LLen=10,RLen=30;
    cout<<"请输入10个任意字符串："<<endl<<"          注意暂定它们长度不超过30"<<endl;
    char**PP=NULL;
    PP=inPutArr(Array);
    outPut( PP, LLen );
	return 0;
}


char*  _inPutArr(char Arr[],int len)
{ //将用户输入的一个字符装串装入Arr数组
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
			break; //char数组默认有'\0'结尾！
    }  
      return Arr;
}

char **  inPutArr(char Arr[][30],int LLen,int RLen)
{//将用户输入的十个字符串装入10个数组
                             //空了一行，这里标记为B行
     for( int i=0;i<LLen;++i)
    {  
        PArr[i]=_inPutArr(Arr[i],RLen);
    }
    return PArr;  
}

void outPut(char **PP,int LLen )
{
    for(int i=0;i<LLen;++i)
               cout<<i<<"   行"<<PP[i]<<endl;
}

/*

1：返回指针时，返回临时指针合法！当然全局亦合法！
2：返回指针的指针时，返回全局指针的指针合法！
                     返回临时指针的指针非法！
*/
