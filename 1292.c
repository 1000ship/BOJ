#include <stdio.h>

int main ( void )
{
    int arr[ 1000 ], level = 1, cnt = 1;
    for( int i = 0; i < 1000; ++ i )
    {
        arr[ i ] = level;
        cnt--;
        if( cnt == 0 )
        {
            level++;
            cnt = level;
        }
    }
    
    int a, b, sum = 0;
    scanf( "%d %d", &a, &b );
    a--;
    b--;
    for( int i = a; i <= b; ++ i )
        sum += arr[ i ];
    printf( "%d", sum );
    return 0;
}