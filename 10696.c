#include <stdio.h>
#include <string.h>

int main ( void )
{
    char str[ 1000001 ];
    long case_num, value, len, result, idx;
    scanf( "%ld", &case_num );
    for( long i = 0; i < case_num; ++ i )
    {
        result = 0;
        idx = 0;
        scanf( "%s", str );
        len = strlen( str );
        scanf( "%d", &value );
        
        while( idx < len )
        {
            result *= 10;
            result += str[ idx ] - '0';
            if( result >= value ) result %= value;
            idx++;
        }
        
        printf( "Case %ld: %ld\n", i + 1, result );
    }
    return 0;
}