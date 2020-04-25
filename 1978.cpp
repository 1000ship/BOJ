#include <stdio.h>

int main ( void )
{
    char prime[ 1001 ] = { 1, 1, 0 };
    for( int i = 2; i <= 1000; ++ i )
        for( int j = i*2; j <= 1000; j += i )
            if( !prime[ j ] )
                prime[ j ] = 1;
    
    int n, cnt = 0, x;
    scanf( "%d", &n );
    for( int i = 0; i < n; ++ i )
    {
        scanf( "%d", &x );
        if( !prime[ x ] ) cnt ++;
    }
    printf( "%d", cnt );
    return 0;
}