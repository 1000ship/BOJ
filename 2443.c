#include <stdio.h>

int main ( void )
{
    int level;
    scanf( "%d", &level );
    for( int i = level; i >=1; -- i )
    {
        for( int j = 0; j < level-i; ++ j )
            printf( " " );
        for( int j = 0; j < 2*i-1; ++ j )
            printf( "*" );
        printf( "\n" );
    }
    return 0;
}