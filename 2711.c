#include <stdio.h>

int main ( void )
{
    int n, idx;
    char str[81];
    scanf( "%d", &n );
    for( int i = 0; i < n; ++ i )
    {
        scanf( "%d%s", &idx, str );
        str[ idx - 1 ] = 0;
        printf( "%s%s\n", &str[0], &str[idx] );
    }
    return 0;
}