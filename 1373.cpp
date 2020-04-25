#include <stdio.h>
#include <string.h>

void printBuffer ( char buffer[] )
{
    int tmp = 0;
    if( buffer[ 0 ] == '1' ) tmp += 4;
    if( buffer[ 1 ] == '1' ) tmp += 2;
    if( buffer[ 2 ] == '1' ) tmp += 1;
    printf( "%d", tmp );
}

int main ( void )
{
    char str[ 1000001 ];
    scanf( "%s", str );
    int len = strlen( str );
    int from = len % 3;
    char buffer[4];
    
    if( len == 2 )
    {
        buffer[ 0 ] = '0';
        buffer[ 1 ] = str[ 0 ];
        buffer[ 2 ] = str[ 1 ];
        printBuffer( buffer );
        return 0;
    }
    else if( len == 1 )
    {
        buffer[ 0 ] = '0';
        buffer[ 1 ] = '0';
        buffer[ 2 ] = str[ 0 ];
        printBuffer( buffer );
        return 0;
    }
    
    switch( from )
    {
        case 2:
            buffer[ 0 ] = '0';
            buffer[ 1 ] = str[ 0 ];
            buffer[ 2 ] = str[ 1 ];
            printBuffer( buffer );
            break;
        case 1:
            buffer[ 0 ] = buffer[ 1 ] = '0';
            buffer[ 2 ] = str[ 0 ];
            printBuffer( buffer );
            break;
    }
    
    for( int i = from; i < len; i += 3 )
    {
        buffer[ 0 ] = str[ i ];
        buffer[ 1 ] = str[ i + 1 ];
        buffer[ 2 ] = str[ i + 2 ];
        printBuffer( buffer );
    }
    return 0;
}