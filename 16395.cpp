#include <stdio.h>

int main ( void )
{
    int n, k;
    scanf( "%d %d", &n, &k );
    
    // y, x
    unsigned long long arr[ 31 ][ 31 ] = { 0 };
    arr[ 1 ][ 1 ] = 1;
    arr[ 2 ][ 1 ] = arr[ 2 ][ 2 ] = 1;
    for( int i = 3; i <= 30; ++ i )
        arr[ i ][ 1 ] = arr[ i ][ i ] = 1;
    
    for( int y = 3; y <= 30; ++ y )
        for( int x = 2; x < y; ++ x )
            arr[ y ][ x ] = arr[ y - 1 ][ x ] + arr[ y - 1 ][ x - 1 ];
    
    /*for( int y = 1; y <= 30; ++ y )
    {
        for( int x = 1; x <= y; ++ x )
        {
            printf( "%d\t", arr[ y ][ x ] );
        }
        printf( "\n" );
    }*/
    
    printf( "%llu", arr[ n ][ k ] );
    
    return 0;
}