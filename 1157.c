#include <stdio.h>
#include <ctype.h>

int main ( void )
{
    int i, cnt[26] = {0};
    char c[1000000];
    scanf( "%s", c );
    
    int k = 0;
    while( c[ k ] != '\0' )
    {
        cnt[ toupper( c[ k ] ) - 'A' ]++;
        k++;   
    }
    
    char maxC = 'A';
    int max = 0;
    for( i = 0; i < 26; ++ i )
        if( max < cnt[ i ] )
            max = cnt[ i ], maxC = i + 'A';
    
    for( i = 0; i < 26; ++ i )
        if( max == cnt[ i ] && maxC != i + 'A' )
            maxC = '?';
            
    printf( "%c", maxC );
    return 0;
}