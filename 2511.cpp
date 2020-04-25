#include <stdio.h>

int main ( void )
{
    int a[ 10 ], b[ 10 ];
    for( int i = 0; i < 10; ++ i )
        scanf( "%d", &a[ i ] );
    for( int i = 0; i < 10; ++ i )
        scanf( "%d", &b[ i ] );
    int ap = 0, bp = 0, winner = 0;
    for( int i = 0; i < 10; ++ i )
    {
        if( a[ i ] > b[ i ] )
        {
            ap += 3;
            winner = 1;
        }
        else if( a[ i ] < b[ i ] )
        {
            bp += 3;
            winner = 2;
        }
        else
            ap += 1, bp += 1;
    }
    if( ap != bp )
    {
        if( ap > bp ) winner = 1;
        else if( ap < bp ) winner = 2;
    }
    char c;
    switch( winner )
    {
        case 0:
            c = 'D';
            break;
        case 1:
            c = 'A';
            break;
        case 2:
            c = 'B';
            break;
    }
    printf( "%d %d\n%c", ap, bp, c );
    return 0;
}