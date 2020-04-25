#include <stdio.h>
#include <string.h>

int main ( void )
{
    char str[ 31 ];
    int n;
    scanf( "%d", &n );
    for( int i = 0; i < n; ++ i )
    {
        gets( str );
        if( strlen( str ) == 0 )
        {
            i--;
            continue;
        }
        if( str[0] >= 'a' && str[0] <= 'z' )
            str[0] -= 'a'-'A';
        printf( "%s\n", str );
    }
    return 0;
}