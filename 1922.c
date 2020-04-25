#include <stdio.h>
#include <stdlib.h>

typedef struct line_struct {
    int start;
    int end;
    int value;
} Line;

int compare ( const void* a, const void* b )
{
    Line* x = (Line*)a;
    Line* y = (Line*)b;
    return x->value > y->value;
}

int getKruskal ( Line lines[], int n, int m )
{
    qsort( lines, m, sizeof( Line ), compare );
    int sum = 0;
    int state[ n + 1 ];
    for( int i = 0; i <= n; ++ i )
        state[ i ] = i;
    for( int i = 0; i < m; ++ i )
    {
        int start = state[ lines[ i ].start ];
        int end = state[ lines[ i ].end ];
        while( start != state[ start ] ) start = state[ start ];
        while( end != state[ end ] ) end = state[ end ];
        if( start != end )
        {
            sum += lines[ i ].value;
            if( start < end ) state[ end ] = start;
            else state[ start ] = end;
        }
    }
    return sum;
}

int main ( void )
{
    int n, m;
    scanf( "%d %d", &n, &m );
    
    Line lines[ m ];
    for( int i = 0; i < m; ++ i )
        scanf( "%d %d %d", &lines[ i ].start, &lines[ i ].end, &lines[ i ].value );
    printf( "%d", getKruskal( lines, n, m ) );
    return 0;
}