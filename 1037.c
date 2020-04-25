#include <stdio.h>

void merge( int arr[], int left, int mid, int right )
{
    int tmp[ right - left + 1 ];
    int i = left, j = mid + 1, k = 0;
    while( i <= mid && j <= right )
        if( arr[ i ] > arr[ j ] )
            tmp[ k++ ] = arr[ i++ ];
        else
            tmp[ k++ ] = arr[ j++ ];
    if( i <= mid )
        while( i <= mid ) tmp[ k++ ] = arr[ i++ ];
    else
        while( j <= right ) tmp[ k++ ] = arr[ j++ ];
    k = 0;
    while( left <= right ) arr[ left++ ] = tmp[ k++ ];
}

void sort ( int arr[], int left, int right )
{
    if( left >= right ) return;
    int mid = (left+right)/2;
    sort( arr, left, mid );
    sort( arr, mid + 1, right );
    merge( arr, left, mid, right );
}

int main()
{
    int n, arr[ 50 ], max = 0;
    scanf( "%d", &n );
    for( int i = 0; i < n; ++ i )
    {
        scanf( "%d", &arr[ i ] );
        if( max < arr[ i ] ) max = arr[ i ];
    }
    
    sort( arr, 0, n - 1 );
    int result = arr[ 0 ] * arr[ n - 1 ];
    printf( "%d", result );
    return 0;
}


