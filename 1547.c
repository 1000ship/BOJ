#include <stdio.h>

int main ( void )
{
    int m, a, b, ball = 1;
    scanf( "%d", &m );
    for( int i = 0; i < m; ++ i )
    {
        scanf( "%d %d", &a, &b );
        if( a == ball )
            ball = b;
        else if( b == ball )
            ball = a;
    }
    printf( "%d", ball );
    return 0;
}