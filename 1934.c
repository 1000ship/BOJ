#include <stdio.h>

int gcm ( int a, int b )
{
    if( a % b == 0 )
        return b;
    else
        return gcm( b, a % b );
}

int main ( void )
{
    int n, a, b, c;
    scanf( "%d", &n );
    for( int T = 0; T < n; ++ T )
    {
        scanf( "%d %d", &a, &b );
        c = gcm( a, b );
        printf( "%d\n", a * b / c );
    }
}