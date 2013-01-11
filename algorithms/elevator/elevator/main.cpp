/*
*  在高峰时间，实习生小飞常常会被电梯每层楼都停弄得很不耐烦，于是他想出了这样一个办法：
*  由于楼层并不高，那么在繁忙的时间，每次电梯从一层往上走时，我们只允许电梯停在其中的某一层。
*  所有乘客都从一楼上电梯，到达某层楼后，电梯听下来，所有乘客再从这里爬楼梯到自己的目的层。
*  在一楼时，每个乘客选择自己的目的层，电梯则自动计算出应停的楼层。
*  问：电梯停在哪一层楼，能够保证这次乘坐电梯的所有乘客爬楼梯的层数之和最少？
*/

#include<vector>  
#include<iostream>  
using namespace std;  

//数学想法：楼层应该停在sum(Mi)/Mr,如果此数为整数，则即为所求，若此数非整数，则可以上下相邻整数分别求和，然后比较优劣

//解法一：采用枚举的方法 O(N^2)
int solution1()  
{  
    int n,person,temp,ans,layer;  
    vector<int> num;  
    cout<<"输入楼层数：";
    if(cin>>n)  //表示n层数  
    {  
      for(int i=1;i<=n;i++)  
      {  
        cout<<"输入第"<<i<<"层下电梯的人数：";
        cin>>person;    //表示第几层下电梯的人数
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
      cout<<"最少的层数： "<<ans<<endl;  
      cout<<"在第 "<<layer<<" 层下"<<endl;  
    }  
    return 0;  
}

/*
线性算法 O(n)
1：首先通过一次扫描计算第一层下所有乘客爬电梯的层数总和
2：然后通过每一层动态变化求得最后的结果
比如现在在第i层所有乘客爬电梯的层数总和为temp
在第i层下的有num1  在第i层的有num2  在第i层上的有num3
则如果在第i-1层下   temp+num3-num1-num2
如果在第i+1层下   temp+num1+num2-num3 
*/
int solution2()  
{  
    int num1,num2,num3,n,ans,person,layer;  
    vector<int> num;
    cout<<"输入楼层数：";
    if(cin>>n)  
    {  
        ans=0;  
        num.push_back(0);  
        num3=0;  
        for(int i=1;i<=n;i++)  
        {
          cout<<"输入第"<<i<<"层下电梯的人数：";
          cin>>person;    //表示第几层下电梯的人数
          cout<<endl;
          num.push_back(person);  
          ans+=num[i]*(i-1);  //在第一层下所有乘客爬电梯的层数总和
          num3+=num[i];       //电梯里面的人数
        }  
        //初始化--在第一层下的条件下
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
                //动态变化，编程技巧  
            }  
            else   
                break;  
            //这里利用一个性质，最优的层数一定在中间，在他下面和上面的都比他要多  
        }  
        cout<<"最少的层数： "<<ans<<endl;  
        cout<<"在第 "<<layer<<" 层下"<<endl;  
    }  
    return 0;
}

int main(int argc,char ** argv)
{
  solution1();
  solution2();
  return 0;
}