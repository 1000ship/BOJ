#include <stdio.h>

long long fibo[ 91 ] = { 0, 1 };

long long getFibo ( int n )
{
    if( n == 0 ) return 0;
    else if( fibo[ n ] ) return fibo[ n ];
    fibo[ n ] = getFibo( n - 1 ) + getFibo( n - 2 );
    return fibo[ n ];
}

int main ( void )
{
    int n;
    scanf( "%d", &n );
    printf( "%lld", getFibo( n ) );
    return 0;
}