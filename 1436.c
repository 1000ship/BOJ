#include <stdio.h>

int isSixThree ( long n )
{
    int cnt = 0;
    for( int i = 1; i < n; i *= 10 )
    {
        if( (n / i) % 10 == 6 )
        {
            cnt++;
            if( cnt == 3 )
                return 1;
        }
        else
            cnt = 0;
    }
    return 0;
}

int main ( void )
{
    long value = 666;
    int n, idx = 1;
    scanf( "%d", &n );
    while( idx != n )
    {
        value++;
        while( !isSixThree( value ) )
        {
            value += 1;
        }
        idx++;
    }
    printf( "%ld", value );
    return 0;
}