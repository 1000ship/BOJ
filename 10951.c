#include <stdio.h>

int main ( void )
{
    int a, b, result;
    do
    {
        result = scanf( "%d", &a );
        if( result == EOF ) break;
        scanf( "%d", &b );
        printf( "%d\n", a + b );
    }
    while( 1 );
    return 0;
}