#include <stdio.h>

long calculate( long *arr, long n, long bottom, long top, long limit )
{
    long result = -1;
    long mid = (bottom+top)/2;
    while( bottom <= top )
    {
        long value = 0;
        for( int i = 0; i < n; ++ i )
        {
            if( arr[ i ] > mid )
            {
                value += arr[ i ] - mid;
                if( value >= limit )
                {
                    result = mid;
                    bottom = mid + 1;
                    mid = (bottom+top)/2;
                    break;
                }
            }
        }
        if( value < limit )
        {
            top = mid - 1;
            mid = (bottom+top)/2;
        }
    }
    return result;
}

int main ( void )
{
    long n, least;
    scanf( "%ld %ld", &n, &least );
    
    long tree[ 1000000 ], max = 0;
    for( int i = 0; i < n; ++ i )
    {
        scanf( "%ld", &tree[ i ] );
        if( max < tree[ i ] ) max = tree[ i ];
    }
    
    printf( "%ld", calculate( tree, n, 0, max, least ) );
    return 0;
}