#include <stdio.h>

int main ( void )
{
    int k, n, m;
    scanf( "%d %d %d", &k, &n, &m );
    m = k * n - m;
    if( m < 0 ) m = 0;
    printf( "%d", m );
    return 0;
}