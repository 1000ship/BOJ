#include <stdlib.h>
#include <stdio.h>

int compare ( const void* a, const void* b )
{
    if( *(int*)a > *(int*)b )
        return 1;
    return 0;
}

int main ( void )
{
    int t;
    scanf( "%d", &t );
    
    int arr[5];
    for( int i = 0; i < t; ++ i )
    {
        for( int j = 0; j < 5; ++ j )
            scanf( "%d", &arr[j] );
        qsort( arr, 5, sizeof( int ), compare );
        if( arr[3] - arr[1] >= 4 )
            printf( "KIN\n" );
        else
            printf( "%d\n", arr[1]+arr[2]+arr[3] );
    }
    return 0;
}