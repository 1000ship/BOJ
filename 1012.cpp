#include <stdio.h>

char arr[ 50 ][ 50 ];
int m, n;

void rmv ( int x, int y )
{
    arr[ x ][ y ] = 0;
    if( x > 0 && arr[ x - 1 ][ y ] ) rmv( x - 1, y );
    if( x < m - 1 && arr[ x + 1 ][ y ] ) rmv( x + 1, y );
    if( y > 0 && arr[ x ][ y - 1 ] ) rmv( x, y - 1 );
    if( y < n - 1 && arr[ x ][ y + 1 ] ) rmv( x, y + 1 );
}

int check( int x, int y )
{
    if( arr[ x ][ y ] )
    {
        rmv( x, y );
        return 1;
    }
    return 0;
}

int main ( void )
{
    int test_case;
    scanf( "%d", &test_case );
    
    for( int current_case = 0; current_case < test_case; ++ current_case )
    {
        int k, x, y, cnt = 0;
        scanf( "%d %d %d", &m, &n, &k );
        for( int i = 0; i < m; ++ i )
            for( int j = 0; j < n; ++ j )
                arr[ i ][ j ] = 0;
        
        for( int i = 0; i < k; ++ i )
        {
            scanf( "%d %d", &x, &y );
            arr[ x ][ y ] = 1;
        }
        
        for( int i = 0; i < m; ++ i )
            for( int j = 0; j < n; ++ j )
                if( check( i, j ) )
                    cnt++;
        
        printf( "%d\n", cnt );
    }
    return 0;
}