#include <stdio.h>

int main ( void )
{
    int n, w, h, size, value;
    scanf( "%d %d %d", &n, &w, &h );
    size = w * w + h * h;
    
    for( int i = 0; i < n; ++ i )
    {
        scanf( "%d", &value );
        if( value * value <= size )
            printf( "DA\n" );
        else
            printf( "NE\n" );
    }
    return 0;
}