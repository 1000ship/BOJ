#include <stdio.h>

int arr[1000][1000] = { 0 };
int day = 0;
int n, m;

int aroundZero ( int x, int y )
{
    if( x > 0 && arr[ x - 1 ][ y ] == 0 ) return 1;
    if( x < m - 1 && arr[ x + 1 ][ y ]  == 0 ) return 1;
    if( y > 0 && arr[ x ][ y - 1 ] == 0 ) return 1;
    if( y < n - 1 && arr[ x ][ y + 1 ]  == 0 ) return 1;
    return 0;
}

void touch ( int x, int y, int level, int memo[][2], int* cnt )
{
    if( x > 0 && arr[ x - 1 ][ y ] == 0 )
        arr[x-1][y] = level, memo[*cnt][0] = x - 1, memo[*cnt][1] = y, (*cnt)++;
    if( x < m - 1 && arr[ x + 1 ][ y ]  == 0 )
        arr[ x + 1 ][ y ] = level, memo[*cnt][0] = x + 1, memo[*cnt][1] = y, (*cnt)++;
    if( y > 0 && arr[ x ][ y - 1 ] == 0 )
        arr[ x ][ y - 1 ] = level, memo[*cnt][0] = x, memo[*cnt][1] = y - 1, (*cnt)++;
    if( y < n - 1 && arr[ x ][ y + 1 ]  == 0 )
        arr[ x ][ y + 1 ] = level, memo[*cnt][0] = x, memo[*cnt][1] = y + 1, (*cnt)++;
}

void calculate( int level, int memo[][2], int cnt )
{
    int target[ cnt * 4 ][ 2 ], targetCnt = 0;
    
    day++;
    for( int i = 0; i < cnt; ++ i )
        touch( memo[i][0], memo[i][1], level + 1, target, &targetCnt );
    
    if( targetCnt != 0 )
        calculate( level + 1, target, targetCnt );
    else
    {
        day--;
        for( int y = 0; y < n; ++ y )
            for( int x = 0; x < m; ++ x )
                if( arr[ x ][ y ] == 0 )
                    day = -1, x = m, y = n;
    }
}

int main ( void )
{
    int memo[ 1000000 ][ 2 ] = { 0 }, cnt = 0;
    
    scanf( "%d %d", &m, &n );
    for( int y = 0; y < n; ++ y )
        for( int x = 0; x < m; ++ x )
            scanf( "%d", &arr[x][y] );
    
    
    for( int y = 0; y < n; ++ y )
        for( int x = 0; x < m; ++ x )
            if( arr[x][y] == 1 && aroundZero( x, y ) )
                memo[ cnt ][ 0 ] = x, memo[ cnt ][ 1 ] = y, cnt++;
    
    calculate( 1, memo, cnt );
    printf( "%d", day );
    return 0;
}