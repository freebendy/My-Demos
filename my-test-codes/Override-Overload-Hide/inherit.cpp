#include   <iostream>  
using   namespace   std;  
   
class   A  
{  
private:  
	int   ma;  
protected:  
	int   mb;  
public:  
	int   mc;  
	void   out()  
	{  
		cout   <<   ma   <<   "   "   <<   mb   <<   "   "   <<   mc   <<   endl;  
	}  
};  
   
class   B   :   protected   A //试着换成private看看  
{  
public:  
	void   f()  
	{  
		//ma   =   1; //cannot   access   private   member   declared   in   class   'A'  
		mb   =   2;  
		mc   =   3;  
		out();  
	 }  
};  
   
class   C   :   public   B  
{  
public:  
	void   f2()  
	{  
		//ma   =   11; //cannot   access   private   member   declared   in   class   'A'  
		mb   =   12;  
		mc   =   13;  
		out();  
	}  
};  
   
   
int   main(int   argc,   char*   argv[])  
{
	B b;
	b.f();

	C   c;  
	c.f2();  
	//c.out(); //cannot   access   public   member   declared   in   class   'A'  
	return   0;  
}   
