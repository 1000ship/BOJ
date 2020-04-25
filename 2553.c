#include <stdio.h>

int func ( int x )
{
    if( x == 0 ) return 0;
    while( x % 10 == 0 ) x /= 10;
    return x;
}

int main ( void )
{
    int n;
    scanf( "%d", &n );
    int result = 1;
    for( int i = n; i > 1; -- i )
    {
        result *= i;
        result = func( result );
        result %= 100000;
    }
    printf( "%d", func(result)%10 );
    return 0;
}