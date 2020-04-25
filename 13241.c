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
    long long a, b;
    scanf( "%lld %lld", &a, &b );
    long long c = gcm( a, b );
    printf( "%lld", a*b/c );
    return 0;
}