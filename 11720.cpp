#include <stdio.h>

int main ( void )
{
    int value = 0, size;
    char c;
    scanf( "%d", &size );
    for( int i = 0; i < size; ++ i )
    {
        scanf( " %c", &c );
        value += c - '0';
    }
    printf( "%d", value );
    return 0;
}