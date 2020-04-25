#include <stdio.h>
#include <string.h>

int main ( void )
{
    int n;
    scanf( "%d", &n );
    char str[ 11 ];
    for( int i = 0; i < n; ++ i )
    {
        int value = 0;
        scanf( "%s", str );
        for( int j = 0; j < 10; ++ j )
            if( strchr( str, '0'+j ) != NULL )
                value ++;
        printf( "%d\n", value );
    }
}