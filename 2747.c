#include <stdio.h>

long long f[46] = { 0, 1 };

long long fibo ( int x )
{
    if( x == 0 ) return 0;
    if( f[ x ] ) return f[ x ];
    f[ x ] = fibo( x - 1 ) + fibo( x - 2 );
    return f[ x ];
}

int main ( void )
{
    int n;
    scanf( "%d", &n );
    printf( "%lld", fibo( n ) );
    return 0;
}