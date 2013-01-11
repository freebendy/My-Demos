//将一组十六进制转换为十进制，然后找出正余弦的最大和最小值是多少，
//及在哪个位置，最好还能输出周期值，用C写。
#include <iostream>
#include <cctype>
#include <cstring>
#include <cmath>

double HexToDec(const char* hex)
{
    double dec = 0;
    double len = double(strlen(hex));
    for(int i = 0; i < len ; ++i)
    {
        switch (tolower(hex[i]))
        {
            case '0':
                break;
            case '1':
                dec += pow(16,len - i -1);
                break;
            case '2':
                dec += 2*pow(16,len - i -1);
                break;
            case '3':
                dec += 3*pow(16,len - i -1);
                break;
            case '4':
                dec += 4*pow(16,len - i -1);
                break;
            case '5':
                dec += 5*pow(16,len - i -1);
                break;
            case '6':
                dec += 6*pow(16,len - i -1);
                break;
            case '7':
                dec += 7*pow(16,len - i -1);
                break;
            case '8':
                dec += 8*pow(16,len - i -1);
                break;
            case '9':
                dec += 9*pow(16,len - i -1);
                break;
            case 'a':
                dec += 10*pow(16,len - i -1);
                break;
            case 'b':
                dec += 11*pow(16,len - i -1);
                break;
            case 'c':
                dec += 12*pow(16,len - i -1);
                break;
            case 'd':
                dec += 13*pow(16,len - i -1);
                break;
            case 'e':
                dec += 14*pow(16,len - i -1);
                break;
            case 'f':
                dec += 15*pow(16,len - i -1);
                break;
            default :
                std::cout<<"It's not a hex number!"<<std::endl ;
                break;
        }
    }
    return dec;
}



void exchange(char ** inArr, const int len, double * ourArr)
{
    for(int i = 0; i < len; ++i)
    {
        ourArr[i] = HexToDec(inArr[i]);
    }
}

int main()
{
    char** str = new char* [4] ;
    str[0] = "10";
    str[1] = "1a";
    str[2] = "13";
    str[3] = "1b";

    double* num = new double[4];

    exchange(str,4,num);

    for(int i = 0; i < 4 ; ++i)
    {
        std::cout<<num[i]<<std::endl;
    }

    delete [] num;
    return 0;
}