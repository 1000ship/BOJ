#include <stdio.h>

int main ( void )
{
    int t, n;
    scanf( "%d", &t );
    
    for( int order = 0; order < t; ++ order )
    {
        scanf( "%d", &n );
        int cnt = 0;
        while( n > 0 )
        {
            if( n % 2 )
                printf( "%d ", cnt );
            n >>= 1;
            ++cnt;
        }
        printf( "\n" );
    }
    return 0;
}