#include <stdio.h>

long gcm ( long a, long b )
{
    if( a % b == 0 )
        return b;
    else
        return gcm( b, a % b );
}

int main()
{
    long a, b;
    scanf( "%lld %lld", &a, &b );
    long iteration = gcm( a, b );
    for( int i = 0; i < iteration; ++ i )
        printf( "1" );
    return 0;
}

