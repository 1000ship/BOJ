#include <stdio.h>
#include <stdlib.h>

typedef struct work_struct {
    int d;
    int w;
    int check;
} Work;


int compareW ( const void *a, const void *b )
{
    Work *left = (Work*)a, *right = (Work*)b;
    return (left->w) < (right->w);
}

int compareD ( const void *a, const void *b )
{
    Work *left = (Work*)a, *right = (Work*)b;
    return (left->d) < (right->d);
}

int main ( void )
{
    int n, maxDay = 0;
    scanf( "%d", &n );
    Work works[n];
    for( int i = 0; i < n; ++ i )
    {
        int d, w;
        scanf( "%d %d", &d, &w );
        works[ i ].d = d;
        works[ i ].w = w;
        works[ i ].check = 0;
        if( maxDay < d )
            maxDay = d;
    }
    qsort( works, n, sizeof( Work ), compareW );
    qsort( works, n, sizeof( Work ), compareD );
    
    int score = 0;
    for( int day = maxDay; day > 0; -- day )
    {
        int idx = -1, tw = -1, td = -1;
        for( int i = 0; i < n; ++ i )
        {
            if( works[ i ].check ) continue;
            if( works[ i ].d >= day )
            {
                if( works[ i ].w > tw )
                {
                    idx = i;
                    tw = works[i].w;
                    td = works[i].d;
                }
                else if( works[ i ].w == tw && works[ i ].d > td )
                {
                    idx = i;
                    tw = works[ i ].w;
                    td = works[ i ].d;
                }
            }
        }
        //printf( "day:%d idx:%d tw:%d td:%d\n", day, idx, tw, td );
        
        if( idx == -1 )
        {
            continue;
        }
        else
        {
            works[ idx ].check = 1;
            score += works[ idx ].w;
        }
    }
    printf( "%d", score );
    return 0;
}