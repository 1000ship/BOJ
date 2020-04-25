#include <stdio.h>

int main ( void )
{
    char otob2[8][4] = { "0", "1", "10", "11", "100", "101", "110", "111" };
    char otob[8][4] = { "000", "001", "010", "011", "100", "101", "110", "111" };
    
    int k = 1;
    char str[ 333335 ];
    scanf( "%s", str );
    
    printf( "%s", otob2[ str[ 0 ] - '0' ] );
    while( str[ k ] != '\0' )
    {
        printf( "%s", otob[ str[ k ] - '0' ] );
        k++;
    }
    
    return 0;
}