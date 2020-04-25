#include <stdio.h>

void printResult( long long x, long long y )
{
    for( long long i = 0; i < y; ++ i )
    {
        printf( "%lld ", x + i );
    }
}

int main ( void )
{
    long long n; // 1,000,000,000
    long long l; // 2 ~ 100
    scanf( "%lld %lld", &n, &l );
    
    for( long long i = l; i <= 100; ++ i )
    {
        for( long long j = n / (i-1); j >= 0; -- j )
        {
            // j 부터 i개의 수
            long long result = ( j * i ) + i * ( i - 1 ) / 2;
            if( result == n )
            {
                printResult( j, i );
                return 0;
            }
            else if( result < n )
                break;
        }
    }
    printf( "-1" );
    return 0;
}