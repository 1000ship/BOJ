#include <stdio.h>
#include <stdlib.h>

int compare ( const void* a, const void* b )
{
    if( *(int*)a < *(int*)b ) return 1;
    return 0;
}

int main ( void )
{
    int n;
    scanf( "%d", &n );
    int straw[ n ];
    for( int i = 0; i < n; ++ i )
        scanf( "%d", &straw[ i ] );
    qsort( straw, n, sizeof( int ), compare );
    
    int max = -1;
    for( int i = 0; i < n - 2; ++ i )
    {
        if( straw[ i ] < straw[ i + 1 ] + straw[ i + 2 ] )
        {
            max = straw[ i ] + straw[ i + 1 ] + straw[ i + 2 ];
            break;
        }
    }
    printf( "%d", max );
    return 0;
}