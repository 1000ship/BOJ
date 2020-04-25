#include <stdio.h>

int main ( void )
{
    long value = 1, n;
    int ok = 1, cnt = 31;
    scanf( "%ld", &n );
    while( n != value && ok )
    {
        value <<= 1, cnt--;
        if( cnt == 0 ) ok = 0;
    }
    printf( "%d", ok );
    return 0;
}