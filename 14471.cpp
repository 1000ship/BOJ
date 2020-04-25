#include <stdio.h>

int main ( void )
{
    int max = 0, cost = 0;
    int n, m;
    scanf( "%d %d", &n, &m );
    for( int i = 0; i < m; ++ i )
    {
        int a, b;
        scanf( "%d %d", &a, &b );
        if( a < n )
        {
            cost += n - a;
            if( max < n - a ) max = n - a;
        }
    }
    cost -= max;
    printf( "%d", cost );
    return 0;
}