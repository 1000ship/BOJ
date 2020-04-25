#include <math.h>
#include <stdio.h>

int main()
{
    int cnt = 0;
    unsigned long long sum = 0, n;
    scanf( "%llu", &n );
    for( unsigned long long i = n; i > 0; i /= 2, cnt++ )
        if( i % 2 )
        {
            unsigned long long tmp = 1;
            for( int j = 0; j < cnt; ++ j )
                tmp *= 3;
            sum += tmp;
        }
    printf( "%llu", sum );

    return 0;
}