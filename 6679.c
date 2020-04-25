#include <stdio.h>

int main ( void )
{
    for( int n = 1000; n < 10000; ++ n )
    {
        int a = 0, b = 0, c = 0;
        for( int i = 1; i <= n; i *= 10 )
            a += (n/i) % 10;
        for( int i = 1; i <= n; i *= 12 )
            b += (n/i) % 12;
        if( a == b )
            for( int i = 1; i <= n; i *= 16 )
                c += (n/i) % 16;
        else continue;
        if( b == c )
            printf( "%d\n", n );
    }
    return 0;
}