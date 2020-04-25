#include <stdio.h>

int main ( void )
{
    int sum = 0, tmp;
    for( int i = 0; i < 5; ++ i )
    {
        scanf( "%d", &tmp );
        if( tmp < 40 ) tmp = 40;
        sum += tmp;
    }
    sum /= 5;
    printf( "%d", sum );
    return 0;
}