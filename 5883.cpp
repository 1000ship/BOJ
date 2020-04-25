#include <stdio.h>

int main ( void )
{
    int n, max = 1;
    scanf( "%d", &n );
    int arr[ n ];
    bool did[ 1000001 ] = { 0 };
    for( int i = 0; i < n; ++ i )
        scanf( "%d", &arr[i] );
    
    for( int i = 0; i < n; ++ i )
    {
        if( did[ arr[ i ] ] ) continue;
        did[ arr[ i ] ] = 1;
        int tmp = -1, cnt = 1;
        for( int j = 0; j < n; ++ j )
        {
            if( arr[ i ] == arr[ j ] ) continue;
            if( tmp == arr[ j ] )
            {
                ++cnt;
                if( cnt > max ) max = cnt;
            }
            else
                cnt = 1, tmp = arr[ j ];
        }
    }
    
    printf( "%d", max );
    return 0;
}