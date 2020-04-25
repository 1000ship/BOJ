#include <stdio.h>

int arr[1001][1001] = { 0 };
int dp[1001][1001] = { 0 };

int check( int x, int y, int size )
{
    for(int possible = dp[x][y]; possible < size; ++ possible )
    {
        for( int i = 0; i <= possible; ++ i )
            if( arr[x+possible ][y+i] || arr[x+i][y+possible ] )
                return 0;
        dp[x][y] = possible;
    }
    return 1;
}

int main ()
{
    int m, n;
    scanf( "%d %d", &m, &n );
    
    for( int i = 0; i < m; ++ i )
        for( int j = 0; j < n; ++ j )
            scanf( "%d", &arr[ i ][ j ] );
    
    int min = 0;
    int max = (m>n)?n:m;
    int size = (max+min)/2;
    int pos = 0;
    while( max >= min )
    {
        int finish = 0;
        for( int i = 0; i < m - size + 1; ++ i )
            for( int j = 0; j < n - size + 1; ++ j )
                if( check( i, j, size ) )
                {
                    if( size > pos ) pos = size;
                    min = size+1;
                    size = (max+min)/2;
                    i = m, j = n, finish = 1;
                }
        if( !finish )
        {
            max = size-1;
            size = (max+min)/2;
        }
    }
    printf( "%d", pos );
    return 0;
}