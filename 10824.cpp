#include <stdio.h>
#include <string.h>

int main ( void )
{
    char str[ 4 ][ 8 ], combine[ 2 ][ 16 ] = { 0 };
    scanf( "%s%s%s%s", str[ 0 ], str[ 1 ], str[ 2 ], str[ 3 ] );
    strcat( combine[ 0 ], str[ 0 ] );
    strcat( combine[ 0 ], str[ 1 ] );
    strcat( combine[ 1 ], str[ 2 ] );
    strcat( combine[ 1 ], str[ 3 ] );
    long long a, b;
    sscanf( combine[ 0 ], "%lld", &a );
    sscanf( combine[ 1 ], "%lld", &b );
    printf( "%lld", a + b );
    return 0;
}