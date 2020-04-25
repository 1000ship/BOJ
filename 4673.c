#include <stdio.h>

int funcD ( int x )
{
    //1, 3, 5, 7, 9, 20, 31, 42, 53, 64, 75, 86, 97
    int tmp = x;
    for( int i = 10; i <= x * 10; i *= 10 )
    {
        tmp += (x % i)*10/i;
    }
    return tmp;
}

int main()
{
    int a = 2, b = 2;
    char arr[10000] = {0,1,0,1,0,1,0};

    do
    {
        if( b <= 10000 )
            arr[ b - 1 ] = 1;
        b = funcD( a );
        a++;
    } while( b <= 13000 );
    
    for( int i = 0; i < 10000; ++ i )
        if( !arr[ i ] ) printf( "%d \n", i + 1 );
    return 0;
}

