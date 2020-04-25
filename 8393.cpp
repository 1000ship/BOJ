#include <stdio.h>

int main ( void )
{
    int n;
    scanf( "%d", &n );
    printf( "%d", (int)( (float)( n * (n+1) ) / 2 ) );
    return 0;
}