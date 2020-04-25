#include <stdio.h>

int main ( void )
{
    int cnt[26] = {0};
    char str[100];
    scanf("%s", str);
    
    int k = 0;
    while( str[ k ] != '\0' )
    {
        if( str[ k ] >= 'a' && str[ k ] <= 'z' )
            cnt[ (int)(str[ k ] - 'a') ]++;
        k++;
    }
    for( int i = 0; i < 26; ++ i )
        printf( "%d ", cnt[ i ] );
    return 0;
}