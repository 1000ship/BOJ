#include <stdio.h>

char isHansu ( int x )
{
    if( x < 100 ) return 1;
    //
    int tmp, num1 = x % 10, num2;
    for( int i = 100; i <= x * 10; i *= 10 )
    {
        num2 = (x%i) * 10 / i;
        if( i == 100 )
            tmp = num2 - num1;
        else if( tmp != num2 - num1 )
            return 0;
        num1 = num2;
    }
    return 1;
}

int main ( void )
{
    int n, cnt = 0;
    scanf( "%d", &n );
    
    for( int i = 1; i <= n; ++ i )
        if( isHansu( i ) )
            cnt++;
            
    printf( "%d", cnt );
    return 0;
}