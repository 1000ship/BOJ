#include <stdio.h>
#include <stdlib.h>

typedef struct line_struct {
    int start;
    int end;
    long long value;
} Line;

int compareLine ( const void* a, const void* b )
{
    Line* l1 = (Line*)a;
    Line* l2 = (Line*)b;
    return l1->value > l2->value;
}

long long getKruskal ( Line lines[], int v, int e )
{
    long long result = 0;
    int state[ v+1 ];
    for( int i = 0; i <= v; ++ i )
        state[ i ] = i;
    for( int i = 0; i < e; ++ i )
    {
        int start = state[ lines[i].start ];
        int end = state[ lines[i].end ];
        while( start != state[start] ) start = state[start];
        while( end != state[end] ) end = state[end];
        if( start != end )
        {
            result += lines[i].value;
            if( start < end )
                state[ end ] = start;
            else
                state[ start ] = end;
        }
    }
    return result;
}

int main ( void )
{
    int v, e;
    scanf( "%d %d", &v, &e );
    
    Line lines[ e ];
    int num = 0;
    for( int i = 0; i < e; ++ i )
        scanf( "%d %d %lld", &lines[i].start, &lines[i].end, &lines[i].value );
    qsort( lines, e, sizeof( Line ), compareLine );
    
    long long result = getKruskal( lines, v, e );
    printf( "%lld", result );
    return 0;
}