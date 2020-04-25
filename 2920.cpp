#include <stdio.h>

int main ( void )
{
    int arr[ 8 ] = { 0 };
    for( int i = 0; i < 8; ++ i )
        scanf( "%d", &arr[ i ] );
    
    int yes = true;
    for( int i = 1; i <= 8; ++ i )
        if( arr[ i-1 ] != i ) yes = false;
    if( yes )
    {
        printf( "ascending" );
        return 0;
    }
    
    yes = true;
    for( int i = 1; i <= 8; ++ i )
        if( arr[ i-1 ] != 9-i ) yes = false;
    if( yes )
    {
        printf( "descending" );
        return 0;
    }
    
    printf( "mixed" );
    return 0;
}