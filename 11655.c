#include <stdio.h>

int main ( void )
{
    char str[ 101 ];
    gets( str );
    int i = 0;
    while( str[ i ] != '\0' )
    {
        char c = str[ i ];
        if( c >= 'a' && c <= 'm' )
            c += 13;
        else if( c >= 'n' && c <= 'z' )
            c -= 13;
        else if( c >= 'A' && c <= 'M' )
            c += 13;
        else if( c >= 'N' && c <= 'Z' )
            c -= 13;
        printf( "%c", c );
        i++;
    }
    return 0;
}