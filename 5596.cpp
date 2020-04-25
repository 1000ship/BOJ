#include <stdio.h>

int main ( void )
{
    int in, a = 0, b = 0;
    for( int i = 0; i < 4; ++ i )
    {
        scanf( "%d", &in );
        a += in;
    }
    
    for( int i = 0; i < 4; ++ i )
    {
        scanf( "%d", &in );
        b += in;
    }
    
    printf( "%d", (a>b)?a:b );
    return 0;
}