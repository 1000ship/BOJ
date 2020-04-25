#include <stdio.h>

int main()
{
    int n, a, b, cnt = 0;
    scanf( "%d %d %d", &n, &a, &b );
    
    while( 1 )
    {
        cnt ++;
        a = ( a + 1 ) / 2;
        b = ( b + 1 ) / 2;
        if( a == b ) break;
    }
    printf( "%d", cnt );
    return 0;
}