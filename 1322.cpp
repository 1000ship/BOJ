#include <stdio.h>

int main ( void )
{
    unsigned long long x, k;
    bool bc[64] = { 0 }, kb[64] = { 0 };
    scanf( "%llu %llu", &x, &k );
    
    int idx = 0;
    while( x > 0 )
    {
        bc[ idx++ ] = x % 2;
        x /= 2;
    }
    
    idx = 0;
    while( k > 0 )
    {
        kb[ idx++ ] = k % 2;
        k /= 2;
    }
    
    idx = 0;
    unsigned long long result = 0;
    for( int i = 0; i < 32; ++ i )
    {
        while( bc[ idx ] )
            idx++;
        if( kb[ i ] )
        {
            unsigned long long tmp = 1;
            for( int j = 0; j < idx; ++ j )
                tmp *= 2;
            result += tmp;
        }
        idx++;
    }
    
    printf( "%llu", result );
    
    return 0;
}