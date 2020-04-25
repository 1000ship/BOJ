#include <stdio.h>

int max[300][300] = { 0 };
int map[300][300] = { 0 };
int n, m, result = 0;

void calculate( int x, int y, int cnt )
{
    cnt += map[ x ][ y ];
    
    if( x == m - 1 && y == n - 1 )
    {
        if( result < cnt ) result = cnt;
        return;
    }
    
    
    //*/
    if( max[ x ][ y ] < cnt )
        max[ x ][ y ] = cnt;
    else if( max[ x ][ y ] != 0 )
        return;
    //*/
    
    if( x < m - 1 ) calculate( x + 1, y, cnt );
    if( y < n - 1 ) calculate( x, y + 1, cnt );
}

int main ( void )
{
    scanf( "%d %d", &n, &m );
    for( int y = 0; y < n; ++ y )
        for( int x = 0; x < m; ++ x )
            scanf( "%d", &map[ x ][ y ] );
    
    calculate( 0, 0, 0 );
    
    printf( "%d", result );
    return 0;
}