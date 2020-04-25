#include <stdio.h>
#include <string.h>

int main ( void )
{
    char a[ 1000 ], b[ 1000 ];
    scanf( "%s%s", a, b );
    if( strstr( a, b ) != NULL )
        printf( "go" );
    else
        printf( "no" );
    return 0;
}