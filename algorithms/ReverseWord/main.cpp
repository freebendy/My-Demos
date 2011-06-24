#include <iostream>
#include <cstdlib>

/*
 * 反转一个以空格分隔单词数组。
*/
char array[] = "I am a student";

void swap( char &c1, char &c2 )
{
    char temp = c1;
    c1 = c2;
    c2 = temp;
}

void reverse( char* arr, int length)
{
    std::cout << "In : " << arr << "*" << std::endl;
    int mid = length / 2;
    for ( int i = 0; i < mid; i++ )
    {
        swap( *( arr + i ), *(arr + length - 1 - i) );
    }
    std::cout << "Out: " << arr << "*" << std::endl;
}

void reverseWords( char* arr, int length )
{
    int spaces = 0;
    for ( int i = 0; i < length; i++ )
    {
        if ( *( arr + i ) == ' ' )
        {
            spaces ++;
        }
    }
    int reverseLength = length;

    while ( spaces > 0 )
    {
        for ( int i = 0; i < reverseLength; i++ )
        {
            if( arr[i] == ' ' )
            {
                reverse( arr, i );
                reverse(arr + i + 1, reverseLength - i - 1 );
                reverse(arr, reverseLength );
                reverseLength -= i + 1;
                std::cout << "\n\n";
                break;
            }
        }
        spaces--;
    }
}

int main(int argc, char *argv[])
{
    reverseWords( array, 14 );
    system("pause");
    return 0;
}
