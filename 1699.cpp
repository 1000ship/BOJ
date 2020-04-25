#include <stdio.h>
#include <math.h>

int min = 999999999;

void calculate ( int value, int unit, int cnt )
{
    if( value == 0 )
    {
        if( min > cnt ) min = cnt;
        return;
    }
    if( unit == 0 ) return;
    if( cnt >= min ) return;
    if( unit == 1 )
    {
        calculate( 0, 0, cnt + value );
        return;
    }
    
    if( value >= unit * unit )
        calculate( value - unit * unit, unit, cnt + 1 );
    calculate( value, unit - 1, cnt );
}

int main ( void )
{
    int n, cnt = 0;
    scanf( "%d", &n );
    double rootValue = sqrt( n );
    calculate( n, (int)rootValue, 0 );
    printf( "%d", min );
    return 0;
}