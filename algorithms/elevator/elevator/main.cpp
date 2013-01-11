/*
*  �ڸ߷�ʱ�䣬ʵϰ��С�ɳ����ᱻ����ÿ��¥��ͣŪ�úܲ��ͷ������������������һ���취��
*  ����¥�㲢���ߣ���ô�ڷ�æ��ʱ�䣬ÿ�ε��ݴ�һ��������ʱ������ֻ�������ͣ�����е�ĳһ�㡣
*  ���г˿Ͷ���һ¥�ϵ��ݣ�����ĳ��¥�󣬵��������������г˿��ٴ�������¥�ݵ��Լ���Ŀ�Ĳ㡣
*  ��һ¥ʱ��ÿ���˿�ѡ���Լ���Ŀ�Ĳ㣬�������Զ������Ӧͣ��¥�㡣
*  �ʣ�����ͣ����һ��¥���ܹ���֤��γ������ݵ����г˿���¥�ݵĲ���֮�����٣�
*/

#include<vector>  
#include<iostream>  
using namespace std;  

//��ѧ�뷨��¥��Ӧ��ͣ��sum(Mi)/Mr,�������Ϊ��������Ϊ������������������������������������ֱ���ͣ�Ȼ��Ƚ�����

//�ⷨһ������ö�ٵķ��� O(N^2)
int solution1()  
{  
    int n,person,temp,ans,layer;  
    vector<int> num;  
    cout<<"����¥������";
    if(cin>>n)  //��ʾn����  
    {  
      for(int i=1;i<=n;i++)  
      {  
        cout<<"�����"<<i<<"���µ��ݵ�������";
        cin>>person;    //��ʾ�ڼ����µ��ݵ�����
        cout<<endl;
        num.push_back(person);  
      }  
      ans=-1;  
      for(int i=1;i<=n;i++)  
      {  
          temp=0;  
          for(int j=1;j<=n;j++)  
          {  
          if(i>=j)  
          temp+=num[j-1]*(i-j);  
          else  
          temp+=num[j-1]*(j-i);    
          }  
          if(ans==-1||temp<ans)  
          {  
              ans=temp;  
              layer=i;  
          }  
      }  
      cout<<"���ٵĲ����� "<<ans<<endl;  
      cout<<"�ڵ� "<<layer<<" ����"<<endl;  
    }  
    return 0;  
}

/*
�����㷨 O(n)
1������ͨ��һ��ɨ������һ�������г˿������ݵĲ����ܺ�
2��Ȼ��ͨ��ÿһ�㶯̬�仯������Ľ��
���������ڵ�i�����г˿������ݵĲ����ܺ�Ϊtemp
�ڵ�i���µ���num1  �ڵ�i�����num2  �ڵ�i���ϵ���num3
������ڵ�i-1����   temp+num3-num1-num2
����ڵ�i+1����   temp+num1+num2-num3 
*/
int solution2()  
{  
    int num1,num2,num3,n,ans,person,layer;  
    vector<int> num;
    cout<<"����¥������";
    if(cin>>n)  
    {  
        ans=0;  
        num.push_back(0);  
        num3=0;  
        for(int i=1;i<=n;i++)  
        {
          cout<<"�����"<<i<<"���µ��ݵ�������";
          cin>>person;    //��ʾ�ڼ����µ��ݵ�����
          cout<<endl;
          num.push_back(person);  
          ans+=num[i]*(i-1);  //�ڵ�һ�������г˿������ݵĲ����ܺ�
          num3+=num[i];       //�������������
        }  
        //��ʼ��--�ڵ�һ���µ�������
        num2=num[1];  
        num3-=num2;  
        num1=0;
        layer=1;  
  
        for(int i=2;i<=n;i++)  
        {  
            if(num1+num2<num3)  
            {  
                ans=ans+num1+num2-num3;  
                layer=i;  

                num1+=num2;
                num2=num[i];  
                num3-=num[i];  
                //��̬�仯����̼���  
            }  
            else   
                break;  
            //��������һ�����ʣ����ŵĲ���һ�����м䣬�������������Ķ�����Ҫ��  
        }  
        cout<<"���ٵĲ����� "<<ans<<endl;  
        cout<<"�ڵ� "<<layer<<" ����"<<endl;  
    }  
    return 0;
}

int main(int argc,char ** argv)
{
  solution1();
  solution2();
  return 0;
}