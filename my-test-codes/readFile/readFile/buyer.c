/* Note:Your choice is C IDE */
#include "stdio.h"
#include <stdlib.h>
#include "math.h"
void main()
{

    	FILE 
    		*putnum,    //ָ�����ļ�(fresults.out)��ָ��
    		*fp,        //ָ��������ļ�(random.out)��ָ�� �����������
    		*temp;      //ָ��������ļ�(random.out)��ָ�� ����ɾ����һ������ 
    	float 
    		x,   //���������
    		y,   //���������
    		f;	 //���������
    		
		char buffer[100];  //���ļ��е�ÿһ��
		int i; //��һ�м�1

        fp = fopen("D:\\random.out","r");
	    	if(fgetc(fp) != EOF) //�����һ���ַ������ļ���βִ��
	    	{		   
                putnum = fopen("D:\\fresults.out","a+");		
				fscanf(fp,"%f,%f",&x,&y);//����һ�����ݡ�   
				 	  	
	    		f = x+y;
				
	    		fprintf(putnum,"%f\n",f); //�����д���ļ���
	    		fclose(putnum);
	    	}			
	    	
	    	i=0;
	    	temp = freopen("D:\\random.out","w+",fp);
	    	while(fgets(buffer,100,fp))//һ��һ�еĶ��ļ�
	    	{
	    		if(i!=0)//ɾ����һ��
	    			fputs(buffer,temp);//��������д�ص��ļ�
	    		i++;
	    	}    	
	    	
	    	fclose(fp); //�ر� 
	    	fclose(temp);   	
		
}