#include <stdio.h>

int main ( void )
{
    long n, i;
    scanf( "%ld", &n );
    for( i = 0; i * i <= n; ++ i );
    printf( "%ld", i - 1 );
    return 0;
}