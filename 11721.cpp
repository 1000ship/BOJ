#include <stdio.h>

int main ( void )
{
    int cnt = 0;
    char c;
    while( scanf( "%c", &c ) != EOF )
    {
        printf( "%c", c );
        cnt++;
        if( cnt == 10 )
        {
            cnt = 0;
            printf( "\n" );
        }
    }
    return 0;
}