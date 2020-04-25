#include <stdio.h>

int main ( void )
{
    int n;
    scanf( "%d", &n );
    
    int arr[ n ] = { 0 };
    int idx = n*n;
    for( int i = 0; i < n; ++ i )
        scanf( "%d", &arr[ i ] );
    
    int stack[ n ] = { 0 };
    int cnt = 0;
    int step = 0;
    
    while( cnt < n )
    {
        while( step > 0 )
            if( arr[(++idx)%n] != 0 )
                step--;
        while( step < 0 )
            if( arr[(--idx)%n] != 0 )
                step++;
        step = arr[ idx%n ];
        arr[ idx%n ] = 0;
        stack[ cnt++ ] = (idx % n) + 1;
    }
    
    for( int i = 0; i < n; ++ i )
        printf( "%d ", stack[ i ] );
    return 0;
}