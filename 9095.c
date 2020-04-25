#include <stdio.h>

int calculate( int value, int cnt )
{
    if( value < 0 ) return 0;
    else if( value == 0 ) return 1;
    return calculate( value - 3, cnt + 1 ) + calculate( value - 2, cnt + 1 ) + calculate( value - 1, cnt + 1 );
}

int main ( void )
{
    int n, value;
    scanf( "%d", &n );
    for ( int i = 0; i < n; ++ i )
    {
        scanf( "%d", &value );
        printf( "%d\n", calculate( value, 0 ) );
    }
    return 0;
}