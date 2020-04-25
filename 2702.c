#include <stdio.h>

long long gcm ( long long a, long long b )
{
    if( a % b == 0 )
        return b;
    else
        return gcm( b, a % b );
}

int main ( void )
{
    int n;
    long long a, b;
    
    scanf( "%d", &n );
    for( int i = 0; i < n; ++ i )
    {
        scanf( "%lld %lld", &a, &b );
        long long c = gcm( a, b );
        printf( "%lld %lld\n", a*b/c, c );
    }
    return 0;
}