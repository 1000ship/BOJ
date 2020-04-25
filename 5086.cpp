#include <stdio.h>

int main ( void )
{
    int a = 1, b = 1;
    while( 1 )
    {
        scanf( "%d %d", &a, &b );
        if( !a && !b ) break;
        if( b % a == 0 ) printf( "factor" );
        else if( a % b == 0 ) printf( "multiple" );
        else printf( "neither" );
        printf( "\n" );
    }
    return 0;
}