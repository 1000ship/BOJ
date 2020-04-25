#include <stdio.h>

int main ( void )
{
    int n;
    double max, score[ 1000 ], avg = 0;
    scanf( "%d", &n );
    for( int i = 0; i < n; ++ i )
    {
        scanf( "%lf", &score[ i ] );
        if( max < score[ i ] ) max = score[ i ];
    }
    
    for( int i = 0; i < n; ++ i )
        avg += score[ i ] / max * 100;
    avg /= n;
    
    printf( "%.2lf", avg );
    return 0;
}