#include <stdlib.h>
#include <stdio.h>

int compare ( const void* a, const void* b )
{
    if( *(int*)a < *(int*)b )
        return 1;
    return 0;
}

int main ( void )
{
    int h, w, c;
    scanf( "%d %d %d", &h, &w, &c );
    int arr[ c ] = { 0 };
    for( int i = 0; i < c; ++ i )
        scanf( "%d", &arr[ i ] );
    //qsort( arr, c, sizeof( int ), compare );
    
    int map[ h ][ w ] = { 0 };
    int idx = 0;
    for( int i = 0; i < c; ++ i )
        for( int j = 0; j < arr[ i ]; ++ j )
            map[ idx % h ][ idx / h ] = i+1, idx++;
    
    for( int i = 0; i < h; ++ i )
    {
        if( i != 0 ) printf( "\n" );
        for( int j = 0; j < w; ++ j )
            printf( "%d", map[ i ][ j ] );
    }
    return 0;
}