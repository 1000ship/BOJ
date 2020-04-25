#include <stdio.h>

int main ( void )
{
    short order[ 5000 ] = { 0 };
    char man[ 5000 ] = { 0 }; // 0 is live, 1 is dead
    int n, m, tmp, idx = 0, kill = 0;
    scanf( "%d %d", &n, &m );
    
    while( kill != n )
    {
        tmp = 0;
        while( tmp != m )
        {
            if( idx == n ) idx = 0;
            if( man[ idx++ ] ) continue;
            tmp++;
        }
        idx--;
        man[ idx ] = 1;
        order[ kill ] = idx;
        kill++;
    }
    
    printf( "<" );
    for ( int i = 0; i < n; ++ i )
        printf( (i==n-1)?"%d>":"%d, ", order[ i ] + 1 );
    return 0;
}