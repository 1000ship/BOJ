//첫째 줄에는 입력으로 주어진 두 수의 최대공약수를,둘째 줄에는 입력으로 주어진 두 수의 최소 공배수를 출력한다.

#include <stdio.h>

long long n, one[91], zero[91];

long long calculate( int idx, int value );

int main ( void )
{
    for( int i = 0; i < 91; ++ i )
        one[ i ] = zero[ i ] = -1;
    scanf( "%d", &n );
    printf( "%lld", calculate( 1, 1 ) );
    return 0;
}

long long calculate( int idx, int value )
{
    if( value )
    {
        if( one[ idx ] != -1 ) return one[ idx ];
    }
    else
    {
        if( zero[ idx ] != -1 ) return zero[ idx ];
    }
    
    if( idx == n ) return 1;
    long long result = ((value)?0:calculate( idx + 1, 1 )) + calculate( idx + 1, 0 );
    if( value )
        one[ idx ] = result;
    else
        zero[ idx ] = result;
    return result;
}