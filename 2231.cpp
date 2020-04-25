#include <stdio.h>

int ssj ( int n )
{
    int result = n;
    for( int i = n; i > 0; i /= 10 )
        result += i % 10;
    return result;
}

int main()
{
    int arr[ 1000001 ] = { 0 };
    
    for( int i = 1; i <= 1000000; ++ i )
        arr[ i ] = ssj( i );
        
    int in, w;
    scanf( "%d", &in );
    for( w = 1; w <= 1000000; ++ w )
        if( arr[ w ] == in )
            break;
    if( w != 1000001 )
        printf( "%d", w );
    else
        printf( "0" );

    return 0;
}