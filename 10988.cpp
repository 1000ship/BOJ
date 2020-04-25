#include <stdio.h>
#include <string.h>

int main ( void )
{
    int c = 1;
    char str[101];
    scanf( "%s", str );
    int size = strlen( str );
    for( int i = 0; i < size/2; ++ i )
        if( str[ i ] != str[ size - i - 1 ] )
        {
            c = 0;
            break;
        }
    printf( "%d", c );
}