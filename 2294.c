#include <stdio.h>
#include <stdlib.h>

int n, k, arr[ 100 ] = { 0 };
int save[ 10001 ] = { 0 }, min = -1, step = 0;

void calculate ( )
{
    if( min != -1 && min <= step )
        return;
    if( k == 0 )
    {
        if( min == -1 || min > step )
            min = step;
        return;
    }
    if( save[ k ] != 0 && save[ k ] <= step )
        return;
    else save[ k ] = step;
    
    for( int i = 0; i < n; ++ i )
    {
        if( k < arr[ i ] ) continue;
        step++;
        k -= arr[ i ];
        calculate();
        k += arr[ i ];
        step--;
    }
}

int compare ( const void* left, const void* right )
{
    int *x = (int*)left, *y = (int*)right;
    return *x < *y;
}

int main ( void )
{
    scanf( "%d %d", &n, &k );
    for( int i = 0; i < n; ++ i )
        scanf( "%d", &arr[ i ] );
    qsort( arr, n, sizeof( int ), compare );
    calculate();
    printf( "%d", min );
    return 0;
}