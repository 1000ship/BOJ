#include <stdio.h>

int main ( void )
{
    int n, m;
    int arr[100000] = {0};
    
    long long sum = 0, max;
    
    scanf( "%d %d", &n, &m );
    
    for( int i = 0; i < m; ++ i )
    {
        scanf( "%d", &arr[ i ] );
        sum += arr[ i ];
    }
    max = sum;
    
    for( int i = m; i < n; ++ i )
    {
        scanf( "%d", &arr[ i ] );
        sum -= arr[ i - m ];
        sum += arr[ i ];
        if( max < sum ) max = sum;
    }
    
    printf( "%lld", max );
    return 0;
}