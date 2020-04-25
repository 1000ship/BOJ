#include <stdio.h>

int main ( void )
{
    int t;
    scanf( "%d", &t );
    for( int i = 0; i < t; ++ i )
    {
        int n, c, result = 0;
        scanf( "%d %d", &n, &c );
        if( n % c ) result = 1;
        result += n / c;
        printf( "%d\n", result );
    }
    return 0;
}