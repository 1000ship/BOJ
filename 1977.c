#include <stdio.h>

int main ( void )
{
    int min, max, sumValue = 0, minValue = 999999;
    scanf( "%d %d", &min, &max );
    for( int i = 1; i <= 100; ++ i )
    {
        int powValue = i * i;
        if( powValue > max ) break;
        if( min <= powValue && powValue <= max )
        {
            if( minValue > powValue ) minValue = powValue;
            sumValue += powValue;
        }
    }
    if( sumValue == 0 )
        printf( "-1" );
    else
        printf( "%d\n%d", sumValue, minValue );
    return 0;
}