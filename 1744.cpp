#include <stdio.h>
#include <stdlib.h>

int compare ( const void* a, const void* b )
{
    if( *(int*)a > *(int*)b )
        return 1;
    return 0;
}
 
int main ( void )
{
    int n;
    scanf( "%d", &n );
    
    int arr[ n ] = { 0 };
    int totalPlus = 0, totalMinus = 0, totalOne = 0;
    for( int i = 0; i < n; ++ i )
    {
        scanf( "%d", &arr[ i ] );
        if( arr[ i ] == 1 ) totalOne++;
        else if( arr[ i ] > 0 ) totalPlus++;
        else totalMinus++;
    }
    qsort( arr, n, sizeof( int ), compare );
    
    int plus[ totalPlus ] = { 0 };
    int minus[ totalMinus ] = { 0 };
    for( int i = 0; i < totalMinus; ++ i )
        minus[ totalMinus - i - 1 ] = arr[ i ];
    for( int i = 0; i < totalPlus; ++ i )
        plus[ i ] = arr[ i + totalOne + totalMinus ];
    
    long result = totalOne;
    for( int i = totalPlus - 1; i > 0; i -= 2)
        result += plus[ i ] * plus[ i-1 ];
    if( totalPlus % 2 == 1 )
        result += plus[ 0 ];
    for( int i = totalMinus - 1; i > 0; i -= 2)
        result += minus[ i ] * minus[ i-1 ];
    if( totalMinus % 2 == 1 )
        result += minus[ 0 ];
    printf( "%ld", result );
    return 0;
}