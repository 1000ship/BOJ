#include <stdio.h>

int main ( void )
{
    int a, b;
    do
    {
        scanf( "%d %d", &a, &b );
        if( !a && !b ) break;
        printf( "%d\n", a + b );
    }
    while( 1 );
    return 0;
}