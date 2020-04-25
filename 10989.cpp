#include <stdio.h>

short cnt[ 10000 ] = { 0 };

int main(void)
{
    int n, x;
    scanf( "%d", &n );
    for( int i = 0; i < n; ++ i )
    {
        scanf( "%d", &x );
        cnt[ x - 1 ] ++;
    }
    
    for( int i = 0; i < 10000; ++ i )
    {
        for( int j = 0; j < cnt[ i ]; ++ j )
            printf( "%d\n", i + 1 );
    }
    return 0;
}

