#include <stdio.h>
#include <string.h>

int main ( void )
{
    int n;
    scanf( "%d", &n );
    for( int i = 0; i < n; ++ i )
    {
        char str[62];
        scanf( "%s", str );
        int len = strlen( str );
        if( ( str[ len - 1 ] - '0' ) % 2 )
            printf( "odd\n" );
        else
            printf( "even\n" );
    }
    return 0;
}