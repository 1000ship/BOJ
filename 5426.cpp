#include <stdio.h>
#include <string.h>
#include <math.h>

int main ( void )
{
    int n;
    scanf( "%d", &n );
    
    char str[ 10001 ];
    for( int test_case = 0; test_case < n; ++ test_case )
    {
        scanf( "%s", str );
        int size = sqrt( strlen( str ) );
        
        char arr[ size ][ size ];
        for( int i = 0; i < size; ++ i )
            for( int j = 0; j < size; ++ j )
                arr[ j ][ i ] = str[ i * size + j ];
        
        char result[ 10001 ] = "";
        for( int i = 0; i < size; ++ i )
            for( int j = 0; j < size; ++ j )
                result[ i * size + j ] = arr[ size - i - 1 ][ j ];
        
        printf( "%s\n", result );
    }
    return 0;
}