#include <stdio.h>

int main ( void )
{
    int i, j, cnt = 0;
    char c;
    for ( i = 0 ; i < 8; ++ i )
    for ( j = 0 ; j < 8; ++ j )
    {
        scanf( " %c", &c );
        if( (j % 2 == 0) ? i % 2 == 0: i % 2 == 1 )
        {
            if( c == 'F' )
                cnt++;
        }
    }
    printf( "%d\n", cnt );
    return 0;
}