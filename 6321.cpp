#include <stdio.h>
#include <string.h>

int main ( void )
{
    int n;
    scanf( "%d", &n );
    
    for( int i = 1; i <= n; ++ i )
    {
        char str[ 51 ] = "";
        scanf( "%s", str );
        for( int j = 0; j < strlen( str ); ++ j )
            if( str[ j ] == 'Z' )
                str[ j ] = 'A';
            else
                str[ j ] += 1;
        if( i != 1 ) printf( "\n\n" );
        printf( "String #%d\n%s", i, str );
    }
    return 0;
}