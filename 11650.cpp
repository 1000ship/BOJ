#include <stdio.h>
#include <stdlib.h>

typedef struct point_struct {
    int x;
    int y;
} Point;

int n;
Point points[ 100000 ];

int compareX( const void* a, const void* b )
{
    Point* first = (Point*)a;
    Point* second = (Point*)b;
    if( first->x > second->x )
        return 1;
    return 0;
}

int compareY( const void* a, const void* b )
{
    Point* first = (Point*)a;
    Point* second = (Point*)b;
    if( first->y > second->y )
        return 1;
    return 0;
}

int main ( void )
{
    scanf( "%d", &n );
    for( int i = 0; i < n; ++ i )
        scanf( "%d %d", &points[ i ].x, &points[ i ].y );
    qsort( points, n, sizeof(Point), compareY );
    qsort( points, n, sizeof(Point), compareX );
    for( int i = 0; i < n; ++ i )
        printf( "%d %d\n", points[ i ].x, points[ i ].y );
    return 0;
}