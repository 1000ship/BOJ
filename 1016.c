#include <stdio.h>

int main ( void )
{
    int check[ 1000001 ] = { 0 };
    long min, max, diff;
    scanf( "%ld %ld", &min, &max );
    diff = max - min;
    
    for( long i = 2; i <= 1000000; ++ i )
    {
        long powValue = i * i;
        if( powValue > max ) continue;
        for( long j = (powValue - (min % powValue)) % powValue; j <= diff; j += powValue )
            if( check[ j ] )
                continue;
            else
                check[ j ] = 1;
    }
    
    int cnt = 0;
    for( int i = 0; i <= diff; ++ i )
        if( !check[ i ] ) cnt ++;
    printf( "%d", cnt );
    return 0;
}