#include <stdio.h>

int main ( void )
{
    char c;
    int arr[ 26 ] = { 0 };
    while( (c = getchar()) != EOF )
    {
        if( c >= 'a' && c <= 'z' )
            arr[ c - 'a' ]++;
    }
    
    int max = arr[ 0 ], idx = 0;
    for( int i = 1; i < 26; ++ i )
        if( max < arr[ i ] ) max = arr[ i ], idx = i;
    for( int i = 0; i < 26; ++ i )
        if( arr[ i ] == max )
            printf( "%c", (char)(i + 'a') );
    return 0;
}