 #include <iostream>
//˽�м̳�
 class Wilma 
{
 protected:
   void fredCallsWilma()
     {
       std::cout << "Wilma::fredCallsWilma()\n";
       wilmaCallsFred();
     }
   virtual void wilmaCallsFred() = 0;   // ���麯��
 };
 
 class Fred : private Wilma {
 public:
   void barney()
    {
       std::cout << "Fred::barney()\n";
       Wilma::fredCallsWilma();
    }
	void test()
	 {
		wilmaCallsFred();
	 }
 protected:
   virtual void wilmaCallsFred()
     {
       std::cout << "Fred::wilmaCallsFred()\n";
     }
 };

 int main()
 {
	 Fred fr;
	 fr.barney();
	 //fr.test();
	 return 0 ;
 }
