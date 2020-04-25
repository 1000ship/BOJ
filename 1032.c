#include <stdio.h>
#include <string.h>

int main ( void )
{
    char check[50] = { 0 };
    char name[51], str[51];
    int n, len;
    
    scanf( "%d", &n );
    scanf( "%s", name );
    len = strlen( name );
    for( int i = 1; i < n; ++ i )
    {
        scanf( "%s", str );
        for( int j = 0; j < len; ++ j )
            if( !check[ j ] && name[ j ] != str[ j ] )
                check[ j ] = 1;
    }
    
    for( int i = 0; i < len; ++ i )
        if( check[ i ] ) printf( "?" );
        else printf( "%c", name[ i ] );
    return 0;
}