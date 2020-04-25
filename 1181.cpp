#include <stdio.h>
#include <string.h>

void merge ( char* arr[], int len[], int left, int mid, int right )
{
    int tmpLen[ right - left + 1 ];
    char* tmp[right-left+1];
    int i = left, j = mid + 1, k = 0;
    while( i <= mid && j <= right )
        if( len[ i ] == len[ j ] )
            if( strcmp( arr[ i ], arr[ j ] ) < 0 )
                tmpLen[ k ] = len[ i ], tmp[ k++ ] = arr[ i++ ];
            else
                tmpLen[ k ] = len[ j ], tmp[ k++ ] = arr[ j++ ];
        else if( len[ i ] < len[ j ] )
            tmpLen[ k ] = len[ i ], tmp[ k++ ] = arr[ i++ ];
        else
            tmpLen[ k ] = len[ j ], tmp[ k++ ] = arr[ j++ ];
    
    if( i > mid )
        while( j <= right ) tmpLen[ k ] = len[ j ], tmp[ k++ ] = arr[ j++ ];
    else
        while( i <= mid ) tmpLen[ k ] = len[ i ], tmp[ k++ ] = arr[ i++ ];
    k = 0;
    while( left <= right ) len[ left ] = tmpLen[ k ], arr[ left++ ] = tmp[ k++ ];
}

void sort ( char* arr[], int len[], int left, int right )
{
    if( left >= right ) return;
    int mid = ( left + right ) / 2;
    sort( arr, len, left, mid );
    sort( arr, len, mid + 1, right );
    merge( arr, len, left, mid, right );
}


int main ( void )
{
    char str[20000][51];
    char* arr[20000];
    int len[20000];
    int n, tmp;
    scanf( "%d", &n );
    for( int i = 0; i < n; ++ i )
    {
        scanf( "%s", str[ i ] );
        arr[ i ] = str[ i ];
        
        len[ i ] = strlen( arr[ i ] );
        for( int j = 0; j < i; ++ j )
        {
            if( len[ i ] == len[ j ] && strcmp( arr[ i ], arr[ j ] ) == 0 )
            {
                i -= 1;
                n -= 1;
                break;
            }
        }
    }
    
    sort( arr, len, 0, n - 1 );
    
    for ( int i = 0; i < n; ++ i )
            printf( "%s\n", arr[ i ] );
    return 0;
}