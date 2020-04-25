#include <stdio.h>
#include <math.h>

int n, min = 2000000000, x, y;

void calc2( int value, int* big, int from, int to )
{
    
    int nextFrom = from, nextTo = to;
    int mid = ( from + to ) / 2;
    int tmp = value + big[ mid ];
    if( tmp > 0 )
        nextTo = mid;
    else
    {
        nextFrom = mid;
        if( nextFrom == from && nextTo == to )
            nextFrom = nextTo;
    }
    
    //printf( "from: %d, to: %d, mid: %d -> tmp: %d\n", from, to, mid, tmp );
    
    if( abs( tmp ) < abs( min ) )
    {
        min = tmp;
        x = value;
        y = big[ mid ];
    }
    
    if( to == from ) return;
    calc2( value, big, nextFrom, nextTo );
}

void calc ( int* small, int s, int* big, int b )
{
    for( int i = 0; i < s; ++ i )
        calc2( small[ i ], big, 0, b );
}

int main ( void )
{
    scanf( "%d", &n );
    int arr[ n ], minus = 0, plus = 0;
    int pp[ n ], mm[ n ];
    for( int i = 0; i < n; ++ i )
    {
        scanf( "%d", &arr[ i ] );
        if( arr[ i ] > 0 ) pp[ plus ++ ] = arr[ i ];
        else mm[ minus ++ ] = arr[ i ];
    }
    
    if( minus == 0 )
    {
        printf( "%d %d", arr[ 0 ], arr[ 1 ] );
        return 0;
    }
    if( plus == 0 )
    {
        printf( "%d %d", arr[ n - 2 ], arr[ n - 1 ] );
        return 0;
    }
    
    if( minus > plus )
        calc( pp, plus, mm, minus );
    else
        calc( mm, minus, pp, plus );
    
    //printf( "%d %d\n", plus, minus );
    //printf( "%d %d %d", x, y, min );
    printf( "%d %d", (x>y)?y:x, (x<y)?y:x );
    
    return 0;
}