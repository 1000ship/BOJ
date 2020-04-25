#include <stdio.h>

int isGMS ( int x )
{
    for( int i = 1; i < x; i *= 10 )
    {
        if( (x/i) % 10 != 4 && (x/i) % 10 != 7 )
            return 0;
    }
    return 1;
}

int main ( void )
{
    int n;
    scanf( "%d", &n );
    for( int i = n; i >= 4; -- i )
    {
        if( isGMS( i ) )
        {
            printf( "%d", i );
            return 0;
        }
    }
    return 0;
}