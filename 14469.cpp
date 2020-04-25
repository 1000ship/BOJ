#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int visit;
    int wait;
} Cow;

int compare ( const void* a, const void* b )
{
    if( ((Cow*)a)->visit > ((Cow*)b)->visit )
        return 1;
    return 0;
}

int main ( void )
{
    int n;
    scanf( "%d", &n );
    
    Cow cows[ n ];
    for( int i = 0; i < n; ++ i )
        scanf( "%d %d", &cows[i].visit, &cows[i].wait );
    qsort( cows, n, sizeof( Cow ), compare );
    
    int timer = 0;
    for( int i = 0; i < n; ++ i )
    {
        if( timer < cows[ i ].visit )
            timer = cows[ i ].visit;
        timer += cows[ i ].wait;
    }
    printf( "%d", timer );
    
    return 0;
}