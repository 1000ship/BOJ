#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
    int state;
} Line;

int compare ( const void* a, const void* b )
{
    if( ((Line*)a)->start > ((Line*)b)->start )
        return 1;
    return 0;
}

int main ( void )
{
    int n;
    scanf( "%d", &n );
    
    Line lines[ n ] = { 0 };
    
    for( int i = 0; i < n; ++ i )
    {
        int from, to, a, b;
        scanf( "%d %d", &a, &b );
        if( a < b )
            from = a, to = b;
        else
            from = b, to = a;
        lines[ i ].start = from;
        lines[ i ].end = to;
        if( from == to ) lines[ i ].state = 1;
    }
    
    qsort( lines, n, sizeof(Line), compare );
    
    int ink = 0;
    for( int pen = 1; pen < 10000; )
    {
        int minPoint = 10000;
        bool didIt = 0;
        for( int i = 0; i < n; ++ i )
        {
            if( lines[i].state == 0 && lines[i].start > pen )
                if( minPoint > lines[i].start )
                    minPoint = lines[i].start;
            if( lines[i].state == 0 && lines[i].start <= pen && lines[i].end > pen )
            {
                lines[i].state = 1;
                ink += lines[i].end - pen;
                pen = lines[i].end;
                didIt = 1;
            }
        }
        if( !didIt )
            pen = minPoint;
    }
    
    printf( "%d", ink );
    
    return 0;
}