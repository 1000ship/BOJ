#include <stdio.h>

void sort( int arr[], int n )
{
    for( int i = 0; i < n; ++ i )
    {
        int idx = i, min = arr[ i ];
        for( int j = i + 1; j < n; ++ j )
            if( min > arr[ j ] )
                min = arr[ j ], idx = j;
        if( i != idx )
        {
            int tmp = arr[ i ];
            arr[ i ] = arr[ idx ];
            arr[ idx ] = tmp;
        }
    }
}

int main(void)
{
    int n, arr[ 1000 ];
    scanf( "%d", &n );
    
    for( int i = 0; i < n; ++ i )
        scanf( "%d", &arr[ i ] );
    
    sort( arr, n );
    
    for( int i = 0; i < n; ++ i )
        printf( "%d\n", arr[ i ] );
        
    return 0;
}

