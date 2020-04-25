#include <stdio.h>

int main ( void )
{
    int a, b, result;
    scanf( "%d %d", &a, &b );
    a -= a % 100;
    for( int i = 0; i < 100; ++ i )
        if( (a + i) % b == 0 )
            result = i, i = 100;
    if( result < 10 )
        printf( "0" );
    printf( "%d", result );
    return 0;
}