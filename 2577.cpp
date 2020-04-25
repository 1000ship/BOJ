#include <stdio.h>
#include <string.h>

int main ( void )
{
    int cnt[ 10 ] = { 0 };
    char str[99];
    long long a, b, c, result;
    scanf( "%lld %lld %lld", &a, &b, &c );
    result = a * b * c;
    sprintf( str, "%lld", result );
    
    int k = 0;
    while( str[ k ] != '\0' )
    {
        cnt[ str[ k ] - '0' ]++;
        k++;
    }
    
    for( int i = 0; i < 10; ++ i )
        printf( "%d\n", cnt[ i ] );
    return 0;
}