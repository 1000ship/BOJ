#include <stdio.h>
#include <stdlib.h>

int compare ( const void* a, const void* b )
{
    int *x = (int*)a, *y = (int*)b;
    return *x < * y;
}

int main ( void )
{
    int a[ 10 ], b[ 10 ];
    for( int i = 0; i < 10; ++ i )
        scanf( "%d", &a[ i ] );
    for( int i = 0; i < 10; ++ i )
        scanf( "%d", &b[ i ] );
    qsort( a, 10, sizeof( int ), compare );
    qsort( b, 10, sizeof( int ), compare );
    printf( "%d %d", a[0]+a[1]+a[2], b[0]+b[1]+b[2] );
    return 0;
}