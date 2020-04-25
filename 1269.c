#include <stdio.h>

char check[ 12500001 ];

int getCheck ( long n )
{
    return check[ n / 8 ] & (1<<(n%8));
}

void setCheck ( long n, int value )
{
    if( value ) check[ n / 8 ] |= (1<<(n%8));
    else check[ n / 8 ] &= ~(1<<(n%8));
}

int main ( void )
{
    long v;
    int a, b, cnt = 0;
    scanf( "%d %d", &a, &b );
    for( int i = 0; i < a; ++ i )
    {
        scanf( "%ld", &v );
        setCheck( v, 1 );
    }
    for( int i = 0; i < b; ++ i )
    {
        scanf( "%ld", &v );
        if( getCheck( v ) )
            cnt++;
    }
    
    printf( "%d", a + b - 2 * cnt );
    return 0;
}