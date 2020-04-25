#include <stdio.h>

int main ( void )
{
    int value, sum = 0, min = -1;
    for( int i = 0; i < 7; ++ i )
    {
        scanf( "%d", &value );
        if( value % 2 == 0 ) continue;
        if( min == -1 || min > value ) min = value;
        sum += value;
    }
    if( min == -1 )
        printf( "-1" );
    else
        printf( "%d\n%d", sum, min );
    return 0;
}