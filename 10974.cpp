#include <stdio.h>

int n, arr[ 9 ], check[ 9 ] = { 0 }, isRepeat = 0;

void calculate( int current )
{
    if( current == n )
    {
        if( isRepeat ) printf( "\n" );
        isRepeat = 1;
        for( int i = 0; i < n; ++ i )
            printf( (i==n-1)?"%d":"%d ", arr[ i ] );
        return;
    }
    
    for( int i = 1; i <= n; ++ i )
    {
        if( check[ i ] ) continue;
        arr[ current ] = i;
        check[ i ] = 1;
        calculate( current + 1 );
        check[ i ] = 0;
    }
}

int main ( void )
{
    scanf( "%d", &n );
    calculate( 0 );
    return 0;
}