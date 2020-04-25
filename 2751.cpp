#include <stdio.h>

short cnt[ 2000001 ] = { 0 };

int main(void)
{
    int n, x;
    scanf( "%d", &n );
    for( int i = 0; i < n; ++ i )
    {
        scanf( "%d", &x );
        cnt[ x + 1000000 ] ++;
    }
    
    for( int i = 0; i < 2000001; ++ i )
    {
        for( int j = 0; j < cnt[ i ]; ++ j )
            printf( "%d\n", i - 1000000 );
    }
    return 0;
}

