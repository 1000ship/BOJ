#include <stdio.h>

int isWin[ 1001 ] = { -1, 1, 2, 1, 2, 2 }; // win 2, lose 1

void calculate ( )
{
    for( int i = 6; i <= 1000; ++ i )
    {
        if( isWin[ i - 1 ] == 1 || isWin[ i - 3 ] == 1 || isWin[ i - 4 ] == 1 )
            isWin[ i ] = 2;
        else
            isWin[ i ] = 1;
    }
}

int main ( void )
{
    int n;
    scanf( "%d", &n );
    calculate();
    if( isWin[ n ] == 2 )
        printf( "SK" );
    else
        printf( "CY" );
    return 0;
}