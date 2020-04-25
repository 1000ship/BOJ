#include <stdio.h>

int main ( void )
{
    int n;
    scanf( "%d", &n );
    
    for( int i = 2; i < n; ++ i )
        printf( "A" );    
    printf( "!@\n" );
    for( int i = 2; i < n; ++ i )
        printf( "A" );   
    printf( "\"!" );
    return 0;
}