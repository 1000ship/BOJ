#include <stdio.h>

int main ( void )
{
    int level;
    scanf( "%d", &level );
    for( int i = 1; i <= level; ++ i )
    {
        for( int j = 0; j < level-i; ++ j )
            printf( " " );
        for( int j = 0; j < 2*i-1; ++ j )
            printf( "*" );
        if( i != level ) printf( "\n" );
    }
    return 0;
}