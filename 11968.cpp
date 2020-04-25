#include <stdio.h>

int main ( void )
{
    int n;
    scanf( "%d", &n );
    
    int arr[ 2 * n + 1 ] = { 0 };
    int deck[ n ];
    for( int i = 0; i < n; ++ i )
    {
        int tmp;
        scanf( "%d", &tmp );
        arr[ tmp ] = 1;
        deck[ i ] = tmp;
    }
    
    int point = 0;
    for( int i = 0; i < n; ++ i )
    {
        int idx = deck[ i ];
        while( idx < 2 * n + 1 )
        {
            if( !arr[idx] )
            {
                arr[idx] = 1;
                point++;
                idx = 2 * n + 1;
            }
            ++idx;
        }
    }
    
    printf( "%d", point );
    return 0;
}