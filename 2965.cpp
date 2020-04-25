#include <stdio.h>
#include <stdlib.h>

int compareFunc ( const void* a, const void* b )
{
    int* x = (int*)a;
    int* y = (int*)b;
    return *x > *y;
}

int main ( void )
{
    int arr[ 3 ], cnt = 0;
    scanf( "%d %d %d", &arr[ 0 ], &arr[ 1 ], &arr[ 2 ] );
    qsort( arr, 3, sizeof(int), compareFunc );
    
    while( arr[ 2 ] - arr[ 1 ] != 1 || arr[ 1 ] - arr[ 0 ] != 1 )
    {
        cnt++;
        int gap1 = arr[ 2 ] - arr[ 1 ];
        int gap2 = arr[ 1 ] - arr[ 0 ];
        if( gap1 < gap2 )
        {
            arr[ 2 ] = arr[ 0 ] + 1;
        }
        else
        {
            arr[ 0 ] = arr[ 1 ] + 1;
        }
        qsort( arr, 3, sizeof( int ), compareFunc );
    }
    
    printf( "%d", cnt );
}