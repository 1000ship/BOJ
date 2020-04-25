#include <stdio.h>
#include <string.h>

int main ( void )
{
    char str[ 1001 ];
    scanf( "%s", str );
    int len = strlen( str );
    
    char *arr[ 1001 ];
    for( int i = 0; i < len; ++ i )
        arr[ i ] = str + i;
        
    int idx;
    char *target;
    for( int i = 0; i < len - 1; ++ i )
    {
        idx = i;
        target = arr[ i ];
        for( int j = i + 1; j < len; ++ j )
            if( strcmp( target, arr[ j ] ) > 0 ) target = arr[ j ], idx = j;
        if( i != idx )
        {
            arr[ idx ] = arr[ i ];
            arr[ i ] = target;
        }
    }
    
    for( int i = 0; i < len; ++ i )
        printf( "%s\n", arr[ i ] );
    return 0;
}