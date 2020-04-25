#include <stdio.h>

int zero[ 41 ] = { 0 };
int one[ 41 ] = { 0 };
int zeroCnt, oneCnt;

void fibo ( int n ) {
    if( zero[ n ] != -1 && one[ n ] != -1 )
    {
        zeroCnt += zero[ n ];
        oneCnt += one[ n ];
        return;
    }
    else if (n == 0)
    {
        zeroCnt++;
        return;
    } else if (n == 1)
    {
        oneCnt++;
        return;
    }
    fibo( n-2 );
    fibo( n-1 );
}

int main ( void )
{
    int t;
    scanf( "%d", &t );
    
    for( int i = 0; i < 41; ++ i )
        zero[ i ] = -1, one[ i ] = -1;
    zero[0] = 1;
    
    for( int i = 0; i < 41; ++ i )
    {
        zeroCnt = 0, oneCnt = 0;
        fibo( i );
        zero[ i ] = zeroCnt;
        one[ i ] = oneCnt;
    }
    
    for( int i = 0; i < t; ++ i )
    {
        int num;
        scanf( "%d", &num );
        printf( "%d %d\n", zero[ num ], one[ num ] );
    }
    return 0;
}