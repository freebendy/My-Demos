#include <iostream>
#include <cstdio>

using namespace std ;

const int Size = 128 ;
const int Min = 60 ;
const int Max = 16384 ;

void GetArray()
{
	FILE *out ;
	out = fopen("output.txt","w") ;

	int array[Size][Size] ; 

	for (int y=0;y<Size;y++)
		for(int x=0;x<Size;x++)
		{
			if((x-Min)*(x-Min)+(y-Min)*(y-Min) <= 1600)
				array[x][y] = 1 ;
			else
				array[x][y] = 0 ;
		}

		if (out != NULL)
		{
			for (int y=0;y<Size;y++)
			{
				for(int x=0;x<Size;x++)
				{
					fprintf(out,"%d",array[x][y]) ;
				}
			}
		}
		fclose(out) ;
}

int main()
{
	GetArray() ;

	/*FILE *in ;
	in = fopen("output.txt","r") ;

	char ia[Max+1] ;

	fscanf(in,"%s",ia) ;
	for(int i =0;i<2500;i++)
	{
		cout<<ia[i] ;
		if((i+1)%50 == 0)
			cout<<'\n' ;
	}

	int x, y ;
	cout<<"Input X: " ;
	cin>>x ;
	cout<<endl ;
	cout<<"Input Y: " ;
	cin>>y ;
	cout<<endl ;
	int num = x+(y-1)*50 ;
	cout<<"The Value You Want Is: "<<ia[num]<<endl ;

	fclose(in) ;*/
	return 0 ;

}