#include <stdio.h>

int tile[3][30] = { 0 }, cnt = 0, fill = 0;

void calculate( int idx, int level, int n )
{
        
    if( idx >= n )
    {
        idx = 0;
        level ++;
    }
    if( fill == n * 3 )
    {
        cnt ++;
        return;
    }
    
    if( tile[ level ][ idx ] != 0 )
    {
        calculate( idx + 1, level, n );
    }
    
    if( idx < n - 1 && tile[ level ][ idx ] == 0 && tile[ level ][ idx + 1 ] == 0 )
    {
        tile[ level ][ idx ] = tile[ level ][ idx + 1 ] = 1;
        fill += 2;
        calculate( idx + 2, level, n );
        tile[ level ][ idx ] = tile[ level ][ idx + 1 ] = 0;
        fill -= 2;
    }
    
    if( level < 2 && tile[ level ][ idx ] == 0 && tile[ level + 1 ][ idx ] == 0 )
    {
        tile[ level ][ idx ] = tile[ level + 1 ][ idx ] = 2;
        fill += 2;
        calculate( idx + 1, level, n );
        tile[ level ][ idx ] = tile[ level + 1 ][ idx ] = 0;
        fill -= 2;
    }
}

int main()
{
    int n, arr[ 31 ] = { 0 };
    for( int i = 0; i < 4; ++ i )
    {
        cnt = 0;
        calculate( 0, 0, i );
        arr[ i ] = cnt;
    }
    
    for( int i = 4; i <= 30; ++ i )
        arr[ i ] = arr[ i - 2 ] * 4 - arr[ i - 4 ];
    
    scanf( "%d", &n );
    printf( "%d", arr[ n ] );
    return 0;
}

