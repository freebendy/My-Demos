/* Note:Your choice is C IDE */
#include "stdio.h"
#include <stdlib.h>
#include "math.h"
void main()
{

    	FILE 
    		*putnum,    //指向结果文件(fresults.out)的指针
    		*fp,        //指向随机数文件(random.out)的指针 用来读随机数
    		*temp;      //指向随机数文件(random.out)的指针 用来删除第一行数据 
    	float 
    		x,   //保存随机数
    		y,   //保存随机数
    		f;	 //保存计算结果
    		
		char buffer[100];  //读文件中的每一行
		int i; //读一行加1

        fp = fopen("D:\\random.out","r");
	    	if(fgetc(fp) != EOF) //如果第一个字符不是文件结尾执行
	    	{		   
                putnum = fopen("D:\\fresults.out","a+");		
				fscanf(fp,"%f,%f",&x,&y);//读第一行数据。   
				 	  	
	    		f = x+y;
				
	    		fprintf(putnum,"%f\n",f); //将结果写到文件中
	    		fclose(putnum);
	    	}			
	    	
	    	i=0;
	    	temp = freopen("D:\\random.out","w+",fp);
	    	while(fgets(buffer,100,fp))//一行一行的读文件
	    	{
	    		if(i!=0)//删除第一行
	    			fputs(buffer,temp);//将其它行写回到文件
	    		i++;
	    	}    	
	    	
	    	fclose(fp); //关闭 
	    	fclose(temp);   	
		
}