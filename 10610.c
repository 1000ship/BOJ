#include <stdio.h>
#include <string.h>

int main ( void )
{
    char str[ 100001 ];
    scanf( "%s", str );
    
    int hasZero = strchr( str, '0' ) != NULL;
    int sum = 0, len = strlen( str );
    for( int i = 0; i < len; ++ i )
        sum += str[ i ] - '0';
        
    if( hasZero && sum % 3 == 0 && sum != 0 )
    {
        // possible
        int cnt[ 10 ] = { 0 };
        for( int i = 0; i < len; ++ i )
            cnt[ str[ i ] - '0' ]++;
        for( int i = 9; i >= 0; -- i )
            for( int j = 0; j < cnt[ i ]; ++ j )
                printf( "%d", i );
    }
    else
    {
        printf( "-1" );
    }
    return 0;
}