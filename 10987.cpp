#include <stdio.h>
#include <string.h>

int isvowel ( char c )
{
    switch( c )
    {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return 1;
    }
    return 0;
}

int main ( void )
{
    char str[101];
    scanf( "%s", str );
    int cnt = 0, size = strlen( str );
    for ( int i = 0; i < size; ++ i )
        if( isvowel( str[ i ] ) ) cnt ++;
    printf( "%d", cnt );
    return 0;
}