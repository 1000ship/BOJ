#include <stdio.h>

int main ( void )
{
    int n, sum = 0;
    scanf( "%d", &n );
    for( int i = 0; i < n; ++ i )
    {
        int a, b;
        scanf( "%d %d", &a, &b );
        sum += b % a;
    }
    printf( "%d", sum );
    return 0;
}