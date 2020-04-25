#include <stdio.h>
#include <math.h>

int main ( void )
{
    int arr[ 32 ] = { 0 };
    int n, idx = 0;
    scanf( "%d", &n );
    while( n != 0 )
        arr[ idx ] = n % 2, n /= 2, idx++;
    int result = 0;
    for( int i = 0; i <= idx; ++ i )
        result += arr[ i ] * pow( 2, idx - i - 1 );
    printf( "%d", result );
    return 0;
}