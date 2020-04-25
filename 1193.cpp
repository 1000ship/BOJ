#include <stdio.h>

int main ( void )
{
    int n;
    scanf( "%d", &n );
    
    for( int i = 1;; i++ )
    {
        if( n > i )
        {
            n -= i;
        }
        else
        {
            if( i % 2 == 0 ) printf( "%d/%d", n, i - n + 1 );
            else printf( "%d/%d", i - n + 1, n );
            break;
        }
    }
    return 0;
}