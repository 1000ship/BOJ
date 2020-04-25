/*
1
2 3 4 5 6 7
8 9 10 11 12 13 14 15 16 17 18 19
20 21 22 23 ~~ 37
38 ~61
62

1개 - 1
6개 - 2
12개 - 3
18개
24개
30개..
*/

#include <stdio.h>

int main ( void )
{
    int n, total = 1;
    scanf( "%d", &n );
    if( n == 1 )
    {
        printf( "1" );
        return 0;
    }
    for( int i = 6;; i += 6 )
    {
        total += i;
        if( total >= n )
        {
            printf( "%d", i / 6 + 1);
            break;
        }
    }
    return 0;
}