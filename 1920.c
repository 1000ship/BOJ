#include <stdio.h>

void sort( int *arr, int left, int right );
void merge ( int *arr, int left, int mid, int right );
int isExist ( int *arr, int n, int value );

void sort( int *arr, int left, int right )
{
    int mid = (left+right)/2;
    if( left < right )
    {
        sort( arr, left, mid );
        sort( arr, mid + 1, right );
        merge( arr, left, mid, right );
    }
}

void merge ( int *arr, int left, int mid, int right )
{
    int tmp[ right - left + 1 ];
    int i = left, j = mid + 1, k = 0;
    while( i <= mid && j <= right )
        if( arr[ i ] < arr[ j ] )
            tmp[ k++ ] = arr[ i++ ];
        else
            tmp[ k++ ] = arr[ j++ ];
    if( i > mid )
        while( j <= right ) tmp[ k++ ] = arr[ j++ ];
    else
        while( i <= mid ) tmp[ k++ ] = arr[ i++ ];
    
    k = 0;
    while( left <= right ) arr[ left++ ] = tmp[ k++ ];
}

int indexOf ( int *arr, int target, int left, int right )
{
    int mid = (left + right) / 2;
    while( left <= right )
        if( arr[ mid ] == target ) return mid;
        else if( arr[ mid ] < target )
            left = mid + 1, mid = (left+right)/2;
        else
            right = mid - 1, mid = (left+right)/2;
    return -1;
}

int main ( void )
{
    int arr[100000], n, m, value;
    scanf( "%d", &n );
    for( int i = 0; i < n; ++ i )
        scanf( "%d", &arr[ i ] );
        
    sort( arr, 0, n - 1 );
    
    scanf( "%d", &m );
    for( int i = 0; i < m; ++ i )
    {
        scanf( "%d", &value );
        printf( "%d\n", indexOf( arr, value, 0, n - 1 ) != -1 );
    }
    return 0;
}