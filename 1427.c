#include <stdio.h>

int main ( void )
{
    int cnt[10] = { 0 }, k = 0;
    char c, str[10];
    scanf( "%s", str );
    while( ( c = str[ k++ ] ) != 0 )
    {
        cnt[ c - '0' ] ++;
    }
    
    for( int i = 9; i >= 0; -- i )
        for( int j = 0; j < cnt[ i ]; ++ j )
            printf( "%c", '0' + i );
    return 0;
}