#include <stdio.h>
#include <stdlib.h>
#define llu unsigned long long

int m, n;

int compare ( const void* a, const void* b )
{
    if( *(llu*)a < *(llu*)b )
        return true;
    return false;
}

int isOK ( llu arr[], int x )
{
    int eat = 0;
    for( int i = 0; i < n && eat < m; ++ i )
    {
        llu tmp = arr[ i ] / x;
        if( tmp == 0 ) break;
        eat += tmp;
    }
    if( eat >= m ) return true;
    return false;
}

int main ( void )
{
    scanf( "%d %d", &m, &n );
    
    llu arr[ n ];
    for( int i = 0; i < n; ++ i )
        scanf( "%llu", &arr[ i ] );
    qsort( arr, n, sizeof( llu ), compare );
    
    int left = 0;
    int right = arr[ 0 ];
    int mid;
    
    while( right - left > 1 )
    {
        mid = (left+right)/2;
        if( isOK( arr, mid ) )
            left = mid;
        else
            right = mid;
    }
    
    if( isOK( arr, right ) )
        printf( "%d", right );
    else
        printf( "%d", left );
    return 0;
}