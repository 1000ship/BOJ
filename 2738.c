#include <stdio.h>

int main ( void )
{
    int n, m, value;
    scanf( "%d %d", &n, &m );
    
    int arr[ n ][ m ];
    for( int i = 0; i < n; ++ i )
    for( int j = 0; j < m; ++ j )
    {
        scanf( "%d", &value );
        arr[ i ][ j ] = value;
    }
    
    for( int i = 0; i < n; ++ i )
    for( int j = 0; j < m; ++ j )
    {
        scanf( "%d", &value );
        arr[ i ][ j ] += value;
    }
    
    for( int i = 0; i < n; ++ i )
    {
        for( int j = 0; j < m; ++ j )
            printf( "%d ", arr[ i ][ j ] );
        printf( "\n" );
    }
    return 0;
}